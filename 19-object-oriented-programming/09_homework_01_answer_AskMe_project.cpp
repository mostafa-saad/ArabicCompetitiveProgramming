// You are encouraged to challenge this code and notify me of issues :)
// Compare this code with Programming 1 code to realize differences

// From Model View perspective, this code mixes things. This makes real-life development harder due to coupling

#include <bits/stdc++.h>
using namespace std;

/////////////////////////////// Helper Methods ///////////////////////////////
vector<string> ReadFileLines(const string &path) {
	vector<string> lines;

	fstream file_handler(path.c_str());

	if (file_handler.fail()) {
		cout << "\n\nERROR: Can't open the file\n\n";
		return lines;
	}
	string line;

	while (getline(file_handler, line)) {
		if (line.size() == 0)
			continue;
		lines.push_back(line);
	}

	file_handler.close();
	return lines;
}

void WriteFileLines(const string &path, const vector<string> &lines, bool append = true) {
	auto status = ios::in | ios::out | ios::app;

	if (!append)
		status = ios::in | ios::out | ios::trunc;	// overwrite

	fstream file_handler(path.c_str(), status);

	if (file_handler.fail()) {
		cout << "\n\nERROR: Can't open the file\n\n";
		return;
	}
	for (const auto &line : lines)
		file_handler << line << "\n";

	file_handler.close();
}

vector<string> SplitString(const string &str, const string &delimiter = ",") {
	string s = str;
	vector<string> strs;

	int pos = 0;
	string substr;
	while ((pos = (int) s.find(delimiter)) != -1) {
		substr = s.substr(0, pos);
		strs.push_back(substr);
		s.erase(0, pos + delimiter.length());
	}
	strs.push_back(s);
	return strs;
}

int ToInt(const string &str) {
	istringstream iss(str);
	int num;
	iss >> num;

	return num;
}

int ReadInt(int low, int high) {
	cout << "\nEnter number in range " << low << " - " << high << ": ";
	int value;

	cin >> value;

	if (low <= value && value <= high)
		return value;

	cout << "ERROR: invalid number...Try again\n";
	return ReadInt(low, high);
}

int ShowReadMenu(const vector<string> &choices) {
	cout << "\nMenu:\n";
	for (int ch = 0; ch < (int) choices.size(); ++ch) {
		cout << "\t" << ch + 1 << ": " << choices[ch] << "\n";
	}
	return ReadInt(1, choices.size());
}
//////////////////////////////////////////////////////////////

class Question {
private:
	int question_id;
	// To support thread. Each question look to a parent question
	// -1 No parent (first question in the thread)
	int parent_question_id;
	int from_user_id;
	int to_user_id;
	int is_anonymous_questions;	// 0 or 1
	string question_text;
	string answer_text;			// empty = not answered

public:
	/*
	 * How many conclassor arguments is too many?
	 * 	https://stackoverflow.com/questions/40264/how-many-conclassor-arguments-is-too-many
	 */
	Question() :
			question_id(-1), parent_question_id(-1), from_user_id(-1), to_user_id(-1), is_anonymous_questions(1) {
	}

	Question(const string &line) {
		vector<string> substrs = SplitString(line);
		assert(substrs.size() == 7);

		question_id = ToInt(substrs[0]);
		parent_question_id = ToInt(substrs[1]);
		from_user_id = ToInt(substrs[2]);
		to_user_id = ToInt(substrs[3]);
		is_anonymous_questions = ToInt(substrs[4]);
		question_text = substrs[5];
		answer_text = substrs[6];
	}

	// It is more proper (or safer) to use the getters/setters in the class itself. For simplicity, I did not apply this in the code.

	string ToString() const {
		ostringstream oss;
		oss << question_id << "," << parent_question_id << "," << from_user_id << "," << to_user_id << "," << is_anonymous_questions << "," << question_text << "," << answer_text;

		return oss.str();
	}

	void PrintToQuestion() const {
		string prefix = "";

		if (parent_question_id != -1)
			prefix = "\tThread: ";

		cout << prefix << "Question Id (" << question_id << ")";
		if (!is_anonymous_questions)
			cout << " from user id(" << from_user_id << ")";
		cout << "\t Question: " << question_text << "\n";

		if (answer_text != "")
			cout << prefix << "\tAnswer: " << answer_text << "\n";
		cout << "\n";
	}

	void PrintFromQuestion() const {
		cout << "Question Id (" << question_id << ")";
		if (!is_anonymous_questions)
			cout << " !AQ";

		cout << " to user id(" << to_user_id << ")";
		cout << "\t Question: " << question_text;

		if (answer_text != "")
			cout << "\tAnswer: " << answer_text << "\n";
		else
			cout << "\tNOT Answered YET\n";
	}

	void PrintFeedQuestion() const {
		if (parent_question_id != -1)
			cout << "Thread Parent Question ID (" << parent_question_id << ") ";

		cout << "Question Id (" << question_id << ")";
		if (!is_anonymous_questions)
			cout << " from user id(" << from_user_id << ")";

		cout << " To user id(" << to_user_id << ")";

		cout << "\t Question: " << question_text << "\n";
		if (answer_text != "")
			cout << "\tAnswer: " << answer_text << "\n";
	}
	/////////////////
	// Setters & Getters

	const string& GetAnswerText() const {
		return answer_text;
	}

	void SetAnswerText(const string& answerText) {
		answer_text = answerText;
	}

	int GetFromUserId() const {
		return from_user_id;
	}

	void SetFromUserId(int fromUserId) {
		from_user_id = fromUserId;
	}

	int GetIsAnonymousQuestions() const {
		return is_anonymous_questions;
	}

	void SetIsAnonymousQuestions(int isAnonymousQuestions) {
		is_anonymous_questions = isAnonymousQuestions;
	}

	int GetParentQuestionId() const {
		return parent_question_id;
	}

	void SetParentQuestionId(int parentQuestionId) {
		parent_question_id = parentQuestionId;
	}

	int GetQuestionId() const {
		return question_id;
	}

	void SetQuestionId(int questionId) {
		question_id = questionId;
	}

	const string& GetQuestionText() const {
		return question_text;
	}

	void SetQuestionText(const string& questionText) {
		question_text = questionText;
	}

	int GetToUserId() const {
		return to_user_id;
	}

	void SetToUserId(int toUserId) {
		to_user_id = toUserId;
	}
};

class User {
private:
	int user_id;		// internal system ID
	string user_name;
	string password;
	string name;
	string email;
	int allow_anonymous_questions;	// 0 or 1

	vector<int> questions_id_from_me;
	// From question id to list of questions IDS on this question (thread questions) - For this user
	map<int, vector<int>> questionid_questionidsThead_to_map;

public:
	User() :
			user_id(-1), allow_anonymous_questions(-1) {
	}

	User(const string &line) {
		vector<string> substrs = SplitString(line);
		assert(substrs.size() == 6);

		user_id = ToInt(substrs[0]);
		user_name = substrs[1];
		password = substrs[2];
		name = substrs[3];
		email = substrs[4];
		allow_anonymous_questions = ToInt(substrs[5]);
	}

	string ToString() const {
		ostringstream oss;
		oss << user_id << "," << user_name << "," << password << "," << name << "," << email << "," << allow_anonymous_questions;

		return oss.str();
	}

	void Print() const {
		cout << "User " << user_id << ", " << user_name << " " << password << ", " << name << ", " << email << "\n";
	}

	void ResetToQuestions(const vector<int> &to_questions) {
		questions_id_from_me.clear();

		for (const auto & question_id : to_questions)
			questions_id_from_me.push_back(question_id);
	}
	void ResetFromQuestions(const vector<pair<int, int>> &to_questions) {
		questionid_questionidsThead_to_map.clear();

		for (const auto & id_pair : to_questions)
			questionid_questionidsThead_to_map[id_pair.first].push_back(id_pair.second);
	}

	void ReadUser(const string &user_name, int id) {
		SetUserName(user_name);
		SetUserId(id);

		string str;

		cout << "Enter password: ";
		cin >> str;
		SetPassword(str);

		cout << "Enter name: ";
		cin >> str;
		SetName(str);

		cout << "Enter email: ";
		cin >> str;
		SetEmail(str);

		cout << "Allow anonymous questions? (0 or 1): ";
		int st;
		cin >> st;
		SetAllowAnonymousQuestions(st);
	}

	int IsAllowAnonymousQuestions() const {
		return allow_anonymous_questions;
	}

	void SetAllowAnonymousQuestions(int allowAnonymousQuestions) {
		allow_anonymous_questions = allowAnonymousQuestions;
	}

	const string& GetEmail() const {
		return email;
	}

	void SetEmail(const string& email) {
		this->email = email;
	}

	const string& GetName() const {
		return name;
	}

	void SetName(const string& name) {
		this->name = name;
	}

	const string& GetPassword() const {
		return password;
	}

	void SetPassword(const string& password) {
		this->password = password;
	}

	int GetUserId() const {
		return user_id;
	}

	void SetUserId(int userId) {
		user_id = userId;
	}

	const string& GetUserName() const {
		return user_name;
	}

	void SetUserName(const string& userName) {
		user_name = userName;
	}

	const map<int, vector<int> >& GetQuestionidQuestionidsTheadToMap() const {
		return questionid_questionidsThead_to_map;
		// Note no setter is provided / returned as const &
	}

	const vector<int>& GetQuestionsIdFromMe() const {
		return questions_id_from_me;
		// Note no setter is provided
	}
};

class QuestionsManager {
private:
	// From question id to list of questions IDS on this question (thread questions) - All users
	map<int, vector<int>> questionid_questionidsThead_to_map;

	// Map the question id to question object. Let's keep one place ONLY with the object
	// When you study pointers, easier handling
	map<int, Question> questionid_questionobject_map;

	int last_id;

public:
	QuestionsManager() {
		last_id = 0;
	}

	void LoadDatabase() {
		last_id = 0;
		questionid_questionidsThead_to_map.clear();
		questionid_questionobject_map.clear();

		vector<string> lines = ReadFileLines("09_homework_01_answer_AskMe_project_questions.txt");
		for (const auto &line : lines) {
			Question question(line);
			last_id = max(last_id, question.GetQuestionId());

			questionid_questionobject_map[question.GetQuestionId()] = question;

			if (question.GetParentQuestionId() == -1)
				questionid_questionidsThead_to_map[question.GetQuestionId()].push_back(question.GetQuestionId());
			else
				questionid_questionidsThead_to_map[question.GetParentQuestionId()].push_back(question.GetQuestionId());
		}
	}

	vector<int> GetUserToQuestions(const User &user) const {
		vector<int> question_ids;

		for (const auto &pair : questionid_questionidsThead_to_map) {	// pair<int, vector<Question>>
			for (const auto &question_id : pair.second) {		//  vector<Question>

				// Get the question from the map. & means same in memory, DON'T COPY
				const Question &question = questionid_questionobject_map.find(question_id)->second;

				if (question.GetFromUserId() == user.GetUserId())
					question_ids.push_back(question.GetQuestionId());
			}
		}
		return question_ids;
	}

	vector<pair<int, int>> GetUserFromQuestions(const User &user) const {
		vector<pair<int, int>> question_ids;

		for (const auto &pair : questionid_questionidsThead_to_map) {	// pair<int, vector<Question>>
			for (const auto &question_id : pair.second) {		//  vector<Question>
				// Get the question from the map. & means same in memory, DON'T COPY
				const Question &question = questionid_questionobject_map.find(question_id)->second;

				if (question.GetToUserId() == user.GetUserId()) {
					if (question.GetParentQuestionId() == -1)
						question_ids.push_back(make_pair(question.GetQuestionId(), question.GetQuestionId()));
					else
						question_ids.push_back(make_pair(question.GetParentQuestionId(), question.GetQuestionId()));
				}
			}
		}
		return question_ids;
	}

	void PrintUserToQuestions(const User &user) const {
		cout << "\n";

		if (user.GetQuestionidQuestionidsTheadToMap().size() == 0)
			cout << "No Questions";

		for (const auto &pair : user.GetQuestionidQuestionidsTheadToMap()) {		// pair<int, vector<Question>>
			for (const auto &question_id : pair.second) {		//  vector<Question>

				// Get the question from the map. & means same in memory, DON'T COPY
				// Accessing questionid_questionobject_map[] change the map by adding if not exist. You can't use in const function
				// Here we just find, which return iterator (second is like a pointer to object)
				const Question &question = questionid_questionobject_map.find(question_id)->second;
				question.PrintToQuestion();
			}
		}
		cout << "\n";
	}

	void PrintUserFromQuestions(const User &user) const {
		cout << "\n";
		if (user.GetQuestionsIdFromMe().size() == 0)
			cout << "No Questions";

		for (const auto &question_id : user.GetQuestionsIdFromMe()) {		//  vector<Question>
			const Question &question = questionid_questionobject_map.find(question_id)->second;
			question.PrintFromQuestion();
		}
		cout << "\n";
	}

	// Used in Answering a question for YOU.
	// It can be any of your questions (thread or not)
	int ReadQuestionIdAny(const User &user) const {
		int question_id;
		cout << "Enter Question id or -1 to cancel: ";
		cin >> question_id;

		if (question_id == -1)
			return -1;

		if (!questionid_questionobject_map.count(question_id)) {
			cout << "\nERROR: No question with such ID. Try again\n\n";
			return ReadQuestionIdAny(user);
		}
		const Question &question = questionid_questionobject_map.find(question_id)->second;

		if (question.GetToUserId() != user.GetUserId()) {
			cout << "\nERROR: Invalid question ID. Try again\n\n";
			return ReadQuestionIdAny(user);
		}
		return question_id;
	}

	// Used to ask a question on a specific thread for whatever user
	int ReadQuestionIdThread(const User &user) const {
		int question_id;
		cout << "For thread question: Enter Question id or -1 for new question: ";
		cin >> question_id;

		if (question_id == -1)
			return -1;

		if (!questionid_questionidsThead_to_map.count(question_id)) {
			cout << "No thread question with such ID. Try again\n";
			return ReadQuestionIdThread(user);
		}
		return question_id;
	}

	void AnswerQuestion(const User &user) {
		int question_id = ReadQuestionIdAny(user);

		if (question_id == -1)
			return;

		Question &question = questionid_questionobject_map.find(question_id)->second;

		question.PrintToQuestion();

		if (question.GetAnswerText() != "")
			cout << "\nWarning: Already answered. Answer will be updated\n";

		cout << "Enter answer: ";	// if user entered comma, system fails :)

		string line;
		getline(cin, line);
		getline(cin, line);
		question.SetAnswerText(line);
	}

	void DeleteQuestion(const User &user) {
		int question_id = ReadQuestionIdAny(user);

		if (question_id == -1)
			return;

		vector<int> ids_to_remove;	// to remove from questionid_questionobject_map

		// Let's see if thread or not. If thread, remove all of it
		if (questionid_questionidsThead_to_map.count(question_id)) { // thread
			ids_to_remove = questionid_questionidsThead_to_map[question_id];
			questionid_questionidsThead_to_map.erase(question_id);
		} else {
			ids_to_remove.push_back(question_id);

			// let's find in which thread to remove. Consistency is important when have multi-view
			for (auto &pair : questionid_questionidsThead_to_map) {
				vector<int> &vec = pair.second;
				for (int pos = 0; pos < (int) vec.size(); ++pos) {
					if (question_id == vec[pos]) {
						vec.erase(vec.begin() + pos);
						break;
					}
				}
			}
		}
		for (const auto &id : ids_to_remove)
			questionid_questionobject_map.erase(id);
	}

	void AskQuestion(const User &user, const pair<int, int> &to_user_pair) {
		Question question;

		if (!to_user_pair.second) {
			cout << "Note: Anonymous questions are not allowed for this user\n";
			question.SetIsAnonymousQuestions(0);
		} else {
			cout << "Is anonymous questions?: (0 or 1): ";
			int st;
			cin >> st;
			question.SetIsAnonymousQuestions(st);
		}

		question.SetParentQuestionId(ReadQuestionIdThread(user));

		cout << "Enter question text: ";	// if user entered comma, system fails :)
		string line;
		getline(cin, line);
		getline(cin, line);
		question.SetQuestionText(line);

		question.SetFromUserId(user.GetUserId());
		question.SetToUserId(to_user_pair.first);

		// What happens in 2 parallel sessions who asked question?
		// They are given same id. This is wrong handling :)
		question.SetQuestionId(++last_id);

		questionid_questionobject_map[question.GetQuestionId()] = question;

		if (question.GetParentQuestionId() == -1)
			questionid_questionidsThead_to_map[question.GetQuestionId()].push_back(question.GetQuestionId());
		else
			questionid_questionidsThead_to_map[question.GetParentQuestionId()].push_back(question.GetQuestionId());
	}

	void ListFeed() const {
		for (const auto &pair : questionid_questionobject_map) {
			const Question &question = pair.second;

			if (question.GetAnswerText() == "")
				continue;
			question.PrintFeedQuestion();
		}
	}

	void UpdateDatabase() {
		vector<string> lines;

		for (const auto &pair : questionid_questionobject_map)
			lines.push_back(pair.second.ToString());

		WriteFileLines("09_homework_01_answer_AskMe_project_questions.txt", lines, false);
	}
};

class UsersManager {
private:
	map<string, User> userame_userobject_map;
	User current_user;
	int last_id;


public:
	UsersManager() {
		last_id = 0;
	}

	void LoadDatabase() {
		last_id = 0;
		userame_userobject_map.clear();

		vector<string> lines = ReadFileLines("09_homework_01_answer_AskMe_project_users.txt");
		for (const auto &line : lines) {
			User user(line);
			userame_userobject_map[user.GetUserName()] = user;
			last_id = max(last_id, user.GetUserId());
		}
	}

	void AccessSystem() {
		int choice = ShowReadMenu( { "Login", "Sign Up" });
		if (choice == 1)
			DoLogin();
		else
			DoSignUp();
	}

	void DoLogin() {
		LoadDatabase();	// in case user added from other parallel run

		while (true) {
			string name, pass;
			cout << "Enter user name & password: ";
			cin >> name >> pass;
			current_user.SetUserName(name);
			current_user.SetPassword(pass);

			if (!userame_userobject_map.count(current_user.GetUserName())) {
				cout << "\nInvalid user name or password. Try again\n\n";
				continue;
			}
			const User& user_exist = userame_userobject_map[current_user.GetUserName()];

			if (current_user.GetPassword() != user_exist.GetPassword()) {
				cout << "\nInvalid user name or password. Try again\n\n";
				continue;
			}
			current_user = user_exist;
			break;
		}
	}

	void DoSignUp() {
		string user_name;
		while (true) {
			cout << "Enter user name. (No spaces): ";
			cin >> user_name;

			if (userame_userobject_map.count(user_name))
				cout << "Already used. Try again\n";
			else
				break;
		}
		// Move logic to user class, which may keep extending data members in future

		current_user.ReadUser(user_name, ++last_id);
		userame_userobject_map[current_user.GetUserName()] = current_user;

		UpdateDatabase(current_user);
	}

	void ResetToQuestions(const vector<int> &to_questions) {
		current_user.ResetToQuestions(to_questions);
	}

	void ResetFromQuestions(const vector<pair<int, int>> &to_questions) {
		current_user.ResetFromQuestions(to_questions);
	}

	void ListUsersNamesIds() const {
		for (const auto &pair : userame_userobject_map)
			cout << "ID: " << pair.second.GetUserId() << "\t\tName: " << pair.second.GetName() << "\n";
	}

	pair<int, int> ReadUserId() const {
		int user_id;
		cout << "Enter User id or -1 to cancel: ";
		cin >> user_id;

		if (user_id == -1)
			return make_pair(-1, -1);

		for (const auto &pair : userame_userobject_map) {
			if (pair.second.GetUserId() == user_id)
				return make_pair(user_id, pair.second.IsAllowAnonymousQuestions());
		}

		cout << "Invalid User ID. Try again\n";
		return ReadUserId();
	}

	void UpdateDatabase(const User &user) {
		string line = user.ToString();
		vector<string> lines(1, line);
		WriteFileLines("18_users.txt", lines);
	}

	const User& GetCurrentUser() const {
		return current_user;
	}
};

class AskMeSystem {
private:
	UsersManager users_manager;
	QuestionsManager questions_manager;

	void LoadDatabase(bool fill_user_questions = false) {	// Internal
		users_manager.LoadDatabase();
		questions_manager.LoadDatabase();

		if (fill_user_questions)	// first time, waiting for login
			ResetCurrentUserQuestions();
	}

	/*
	 * Probably the most important design change
	 * We needed to decouple the question manager from relying on User implementation
	 * We break to 2 steps
	 * 1) Question manager return relevant question
	 * 2) User manager helps reseting the user question. Even the manager doesn't do this by itself
	 *
	 * This is more OO now
	 */
	void ResetCurrentUserQuestions() {
		const User& user = users_manager.GetCurrentUser();

		const auto &to_questions = questions_manager.GetUserToQuestions(user);
		users_manager.ResetToQuestions(to_questions);

		const auto &from_questions = questions_manager.GetUserFromQuestions(user);
		users_manager.ResetFromQuestions(from_questions);
	}

public:
	void Run() {	// only public one
		LoadDatabase(false);
		users_manager.AccessSystem();
		ResetCurrentUserQuestions();

		vector<string> menu;
		menu.push_back("Print Questions To Me");
		menu.push_back("Print Questions From Me");
		menu.push_back("Answer Question");
		menu.push_back("Delete Question");
		menu.push_back("Ask Question");
		menu.push_back("List System Users");
		menu.push_back("Feed");
		menu.push_back("Logout");

		while (true) {
			int choice = ShowReadMenu(menu);
			LoadDatabase(true);

			if (choice == 1)
				questions_manager.PrintUserToQuestions(users_manager.GetCurrentUser());
			else if (choice == 2)
				questions_manager.PrintUserFromQuestions(users_manager.GetCurrentUser());
			else if (choice == 3) {
				questions_manager.AnswerQuestion(users_manager.GetCurrentUser());
				questions_manager.UpdateDatabase();
			} else if (choice == 4) {
				questions_manager.DeleteQuestion(users_manager.GetCurrentUser());
				// Let's build again (just easier, but slow)
				ResetCurrentUserQuestions();
				questions_manager.UpdateDatabase();
			} else if (choice == 5) {
				pair<int, int> to_user_pair = users_manager.ReadUserId();
				if (to_user_pair.first != -1) {
					questions_manager.AskQuestion(users_manager.GetCurrentUser(), to_user_pair);
					questions_manager.UpdateDatabase();
				}
			} else if (choice == 6)
				users_manager.ListUsersNamesIds();
			else if (choice == 7)
				questions_manager.ListFeed();
			else
				break;
		}
		Run();	// Restart again
	}
};

int main() {
	AskMeSystem service;
	service.Run();

	return 0;
}

/*
 101,-1,11,13,0,Should I learn C++ first or Java,I think C++ is a better Start
 203,101,11,13,0,Why do you think so!,Just Google. There is an answer on Quora.
 205,101,45,13,0,What about python?,
 211,-1,13,11,1,It was nice to chat to you,For my pleasure Dr Mostafa
 212,-1,13,45,0,Please search archive before asking,
 300,101,11,13,1,Is it ok to learn Java for OOP?,Good choice
 301,-1,11,13,0,Free to meet?,
 302,101,11,13,1,Why so late in reply?,

 13,mostafa,111,mostafa_saad_ibrahim,mostafa@gmail.com,1
 11,noha,222,noha_salah,nono171@gmail.com,0
 45,ali,333,ali_wael,wael@gmail.com,0

 */
