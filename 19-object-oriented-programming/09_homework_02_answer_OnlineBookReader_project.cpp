// If you don't understand reason behind something, change it and see
// E.g. why the system has users_manager as pointer?

#include <bits/stdc++.h>
#include <ctime>
using namespace std;

////////////////////////// Utilities //////////////////////////
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

string GetCurrentTimeDate() {	// src: https://stackoverflow.com/questions/17223096/outputting-date-and-time-in-c-using-stdchrono
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
	return ss.str();
}

///////////////////////////////////////////////////

class Book {
private:
	string isbn;
	string title;
	string author;
	vector<string> pages;

public:
	void Read() {
		string str;

		cout << "Enter ISBN: ";
		cin >> str;
		SetIsbn(str);

		cout << "Enter Title: ";
		cin >> str;
		SetTitle(str);

		cout << "Enter Author Name: ";
		cin >> str;
		SetAuthor(str);

		cout << "Enter How many pages: ";
		int pages_count;
		cin >> pages_count;

		for (int page = 0; page < pages_count; ++page) {
			cout << "Enter page # " << page + 1 << ": ";
			cin >> str;
			pages.push_back(str);
		}
	}

	const string& GetAuthor() const {
		return author;
	}

	void SetAuthor(const string& author) {
		this->author = author;
	}

	const string& GetIsbn() const {
		return isbn;
	}

	void SetIsbn(const string& isbn) {
		this->isbn = isbn;
	}

	const vector<string>& GetPages() const {
		return pages;
	}

	void SetPages(const vector<string>& pages) {
		this->pages = pages;
	}

	const string& GetTitle() const {
		return title;
	}

	void SetTitle(const string& title) {
		this->title = title;
	}

	string ToString() {
		return title;
	}
};

class BookReadingSession {
private:
	// Using a pointer is a bad design chioce here: what if the original book removed now by admin? We access garbage!
	// A more proper way: use book isbn, and later use book manager to find the book
	Book* book;	// Note, we did not create this pointer. Someone else should destory
	int current_page;
	string last_access_date;

public:
	BookReadingSession() :
			BookReadingSession(nullptr) {
	}

	BookReadingSession(Book* book) :
			book(book), current_page(0), last_access_date(GetCurrentTimeDate()) {

	}
	string ToString() {
		ostringstream oss;
		oss << GetBook()->GetTitle() << " Page: " << PageIdxStr() << " - " << GetLastAccessDate();
		return oss.str();
	}

	string GetCurrentPageContent() {
		return book->GetPages()[current_page];
	}

	const Book* GetBook() const {
		return book;	// No set
	}

	const string& GetLastAccessDate() const {
		return last_access_date;
	}

	void ResetLastAccessDate() {	// More convenient
		last_access_date = GetCurrentTimeDate();
	}

	int GetCurrentPage() const {
		return current_page;
	}

	string PageIdxStr() {
		ostringstream oss;
		oss << GetCurrentPage() + 1 << "/" << book->GetPages().size();
		return oss.str();
	}

	void NextPage() {
		if (current_page < (int) book->GetPages().size() - 1)
			current_page++;
	}
	void PreviousPage() {
		if (current_page > 0)
			current_page--;
	}
};

class User {
private:
	string user_name;
	string password;
	string name;
	string email;
	bool is_library_admin;

	vector<BookReadingSession*> reading_sessions;

public:

	// If you have pointers internally: start with canceling copy constructor, so that you discover any bugs due to misuse
	// Provide it based on logic & needs
	User(const User&) = delete;
	void operator=(const User&) = delete;

	User() {
		is_library_admin = false;
	}

	~User() {
		cout << "Destructor User\n";
		for (auto &session : reading_sessions)
			delete session;

		reading_sessions.clear();
	}

	string ToString() const {
		ostringstream oss;
		oss << "Name: " << user_name;
		if (IsLibraryAdmin())
			oss << " | Admin";
		oss << "\n";
		oss << "Email: " << email << "\n";
		oss << "User name: " << user_name << "\n";
		return oss.str();
	}

	void Read(const string &user_name) {
		SetUserName(user_name);

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

	const string& GetUserName() const {
		return user_name;
	}

	void SetUserName(const string& userName) {
		user_name = userName;
	}

	bool IsLibraryAdmin() const {
		return is_library_admin;
	}

	void SetIsLibraryAdmin(bool isLibraryAdmin) {
		is_library_admin = isLibraryAdmin;
	}

	const vector<BookReadingSession*>& GetReadingSessions() const {
		// Note: Although the return is const vector, but the pointer is not const, so someone can cause problems using setters on pointer
		return reading_sessions;	// No set
	}

	BookReadingSession* AddReadingSession(Book* book) {
		// We create pointer & later delete it
		BookReadingSession* session = new BookReadingSession(book);
		reading_sessions.push_back(session);
		return session;
	}
};

class UsersManager {
private:
	User* current_user = nullptr;
	map<string, User*> userame_userobject_map;

	void FreeLoadedData() {
		for (auto pair : userame_userobject_map) {
			delete pair.second;
		}
		userame_userobject_map.clear();
		current_user = nullptr;
	}

public:
	UsersManager() {
	}

	~UsersManager() {
		cout << "Destuctor: UsersManager\n";
		FreeLoadedData();
	}

	// No sense for such a class (manager of objects) to be copyable!
	// This is a C++ 11 feature that prevents Copy constructor and Assignment Operator (=)from being called. It delete then from the class
	// https://ariya.io/2015/01/c-class-and-preventing-object-copy#:~:text=There%20are%20three%20ways%20to,have%20its%20instance%20copied%20around.
	UsersManager(const UsersManager&) = delete;
	void operator=(const UsersManager&) = delete;

	void LoadDatabase() {
		cout<<"UsersManager: LoadDatabase\n";

		FreeLoadedData();
		// Some "Dummy Data" for simplicity
		User* user1 = new User();
		user1->SetUserName("mostafa");
		user1->SetPassword("111");
		user1->SetEmail("most@gmail.com");
		user1->SetIsLibraryAdmin(true);
		user1->SetName("Mostafa Saad Ibrahim");
		userame_userobject_map[user1->GetUserName()] = user1;

		User* user2 = new User();
		user2->SetUserName("asmaa");
		user2->SetPassword("222");
		user2->SetEmail("asmaa@gmail.com");
		user2->SetIsLibraryAdmin(false);
		user2->SetName("Asmaa Saad Ibrahim");
		userame_userobject_map[user2->GetUserName()] = user2;
	}

	void AccessSystem() {
		int choice = ShowReadMenu( { "Login", "Sign Up" });
		if (choice == 1)
			DoLogin();
		else
			DoSignUp();
	}

	void DoLogin() {
		LoadDatabase();

		while (true) {
			string user_name, pass;
			cout << "Enter user user_name & password: ";
			cin >> user_name >> pass;

			if (!userame_userobject_map.count(user_name)) {
				cout << "\nInvalid user user_name or password. Try again\n\n";
				continue;
			}
			User* user_exist = userame_userobject_map.find(user_name)->second;

			if (pass != user_exist->GetPassword()) {
				cout << "\nInvalid user user_name or password. Try again\n\n";
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

		current_user->Read(user_name);
		userame_userobject_map[current_user->GetUserName()] = current_user;
	}

	BookReadingSession* AddReadingSession(Book* book) {
		return current_user->AddReadingSession(book);
	}

	const User* GetCurrentUser() const {
		return current_user;
	}
};

class BooksManager {
private:
	map<string, Book*> isbn_to_book_map;

	void FreeLoadedData() {
		for (auto pair : isbn_to_book_map) {
			delete pair.second;
		}
		isbn_to_book_map.clear();
	}

public:
	BooksManager() {
	}

	void LoadDatabase() {
		cout<<"BooksManager: LoadDatabase\n";
		FreeLoadedData();

		Book* book1 = new Book();
		book1->SetIsbn("00001");
		book1->SetAuthor("Mostafa");
		book1->SetTitle("C++ how to program");
		vector<string> pages1 = { "A C++", "B C++", "C C++", "D C++", "E C++" };
		book1->SetPages(pages1);
		AddBook(book1);

		Book* book2 = new Book();
		book2->SetIsbn("00002");
		book2->SetAuthor("Morad");
		book2->SetTitle("Intro to algo");
		vector<string> pages2 = { "A Algo", "B Algo", "C Algo", "D Algo", "E " };
		book2->SetPages(pages2);
		AddBook(book2);

		Book* book3 = new Book();
		book3->SetIsbn("00003");
		book3->SetAuthor("Morad");
		book3->SetTitle("Data Structures in C++");
		vector<string> pages3 = { "A Data", "B Data", "C Data", "D Data", "E Data" };
		book3->SetPages(pages3);
		AddBook(book3);
	}

	BooksManager(const BooksManager&) = delete;
	void operator=(const BooksManager&) = delete;

	~BooksManager() {
		cout << "Destuctor: BooksManager\n";
		FreeLoadedData();
	}

	// CRUD operations
	void AddBook(Book* book) {
		isbn_to_book_map[book->GetIsbn()] = book;
	}

	void UpdateBook(string isbn, Book* book) {
	}

	void DeleteBook(string isbn) {
	}

	Book* GetBook(string isbn) {
		return nullptr;
	}

	const map<string, Book*>& GetIsbnToBookMap() const {
		return isbn_to_book_map;
	}

	void SetIsbnToBookMap(const map<string, Book*>& isbnToBookMap) {
		isbn_to_book_map = isbnToBookMap;
	}

};

class UserView {
private:
	UsersManager &users_manager;
	BooksManager &books_manager;
public:

	UserView(UsersManager & users_manager, BooksManager &books_manager) :
			users_manager(users_manager), books_manager(books_manager) {

	}

	void Display() {
		const User* user = users_manager.GetCurrentUser();
		cout << "\n\nHello " << user->GetName() << " | User View\n";

		vector<string> menu;
		menu.push_back("View Profile");
		menu.push_back("List & Select from My Reading History");
		menu.push_back("List & Select from Available Books");
		menu.push_back("Logout");

		while (true) {
			int choice = ShowReadMenu(menu);
			if (choice == 1)
				ViewProfile();
			else if (choice == 2)
				ListReadingHistory();
			else if (choice == 3)
				ListAvailableBooks();
			else
				break;
		}
	}

	void ViewProfile() {
		const User* user = users_manager.GetCurrentUser();

		cout << "\n" << user->ToString() << "\n";
	}

	void DisplaySession(BookReadingSession* session) {
		vector<string> menu;
		menu.push_back("Next Page");
		menu.push_back("Previous Page");
		menu.push_back("Stop Reading");

		while (true) {
			cout << "Current Page: " << session->PageIdxStr() << "\n";
			cout << session->GetCurrentPageContent() << "\n";

			int choice = ShowReadMenu(menu);
			if (choice == 1)
				session->NextPage();
			else if (choice == 2)
				session->PreviousPage();
			else
				break;
		}
		session->ResetLastAccessDate();
	}

	void ListReadingHistory() {
		int idx = 0;
		const auto& sessions = users_manager.GetCurrentUser()->GetReadingSessions();
		for (auto& session : sessions) {
			cout << ++idx << ": " << session->ToString() << "\n";
		}

		if (idx == 0)
			cout << "\nNo history. List books and start having fun\n";
		else {
			cout << "\nWhich session to open?: ";
			int choice = ReadInt(1, idx);
			DisplaySession(sessions[choice - 1]);
		}
	}

	void ListAvailableBooks() {
		const map<string, Book*>& mp = books_manager.GetIsbnToBookMap();

		cout << "\nOur current book collection:\n";
		int idx = 0;
		for (const auto &pair : mp) {
			// As we call ToString: we don't need to worry about book data members future changes
			cout << "\t" << ++idx << " " << pair.second->ToString() << "\n";
		}

		cout << "\nWhich book to read?: ";
		int choice = ReadInt(1, idx);	// For simplicity, assume a new book is selected

		idx = 0;
		for (const auto &pair : mp) {
			if (++idx == choice) {
				BookReadingSession* session = users_manager.AddReadingSession(pair.second);
				DisplaySession(session);
				break;
			}
		}

	}
};

class AdminView {
private:
	UsersManager &users_manager;
	BooksManager &books_manager;
public:

	AdminView(UsersManager &users_manager, BooksManager &books_manager) :
			users_manager(users_manager), books_manager(books_manager) {

	}

	void Display() {
		const User* user = users_manager.GetCurrentUser();

		cout << "\n\nHello " << user->GetName() << " | Admin View\n";
		vector<string> menu;
		menu.push_back("View Profile");
		menu.push_back("Add Book");
		menu.push_back("Logout");

		while (true) {
			int choice = ShowReadMenu(menu);
			if (choice == 1)
				ViewProfile();
			else if (choice == 2)
				AddBook();
			else
				break;
		}
	}

	void ViewProfile() {
		const User* user = users_manager.GetCurrentUser();

		cout << "\n" << user->ToString() << "\n";
	}

	void AddBook() {
		Book *book = new Book();
		book->Read();
		books_manager.AddBook(book);
	}

};

class OnlineReaderSystem {
private:
	BooksManager *books_manager;
	UsersManager *users_manager;

	void LoadDatabase() {
		users_manager->LoadDatabase();
		books_manager->LoadDatabase();
	}

public:
	OnlineReaderSystem() :
			books_manager(new BooksManager()), users_manager(new UsersManager()) {
	}

	~OnlineReaderSystem() {
		cout << "Destuctor: OnlineReaderSystem\n";

		if (books_manager != nullptr) {
			delete books_manager;
			books_manager = nullptr;
		}
		if (users_manager != nullptr) {
			delete users_manager;
			users_manager = nullptr;
		}
	}

	void Run() {	// only public one
		LoadDatabase();

		while (true) {
			users_manager->AccessSystem();	// login/signup

			// Let's make for every user, its own viewer class: Remember: Single responsibility principle
			if (users_manager->GetCurrentUser()->IsLibraryAdmin()) {
				AdminView view(*users_manager, *books_manager);
				view.Display();
			} else {
				UserView view(*users_manager, *books_manager);
				view.Display();
			}
		}
	}
};

int main() {
	OnlineReaderSystem site;

	site.Run();

	return 0;
}

