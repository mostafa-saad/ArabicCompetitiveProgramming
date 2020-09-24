#include <bits/stdc++.h>
using namespace std;

#include "expedia_customer.h"
#include "expedia_user_mgr.h"
#include "expedia_customer_view.h"

class ExpediaFrontend {
private:
	UsersManager* users_manager;
	ExpediaBackend* expedia_manager;
	CustomerManager* customer_manager = nullptr;

	void LoadDatabase() {
		users_manager->LoadDatabase();
	}

public:
	ExpediaFrontend(const ExpediaFrontend&) = delete;
	void operator=(const ExpediaFrontend&) = delete;

	ExpediaFrontend() : users_manager(new UsersManager()), expedia_manager(new ExpediaBackend()){
	}

	~ExpediaFrontend() {
		cout << "Destructor: ExpediaFrontend\n";

		if (users_manager != nullptr) {
			delete users_manager;
			users_manager = nullptr;
		}
	}

	void Run() {
		LoadDatabase();

		while (true) {
			users_manager->AccessSystem();	// login/signup

			if(users_manager->GetCurrentUser()->GetType() == UserType::CusomterUser) {
				customer_manager = new CustomerManager(users_manager->GetCurrentUser(), *expedia_manager);
				CustomerView view(*customer_manager);
				view.Display();
			} else
				assert(false);
		}
	}
};

// As a project
// Add more flight classes + later operator overloading something + Simulators + logging + integration/unit test + its exception hierarchy
// Singelton loading DB config for flights
// Fawy project maybe with adapters + craigslist

 int main() {
	ExpediaFrontend site;
	site.Run();

	User* user = new Customer();
	dynamic_cast<Customer*>(user);

	return 0;
}


 /*

1 asmaa 222

2
1 Cairo 10-05-20   Vancouver 13-06-20  3 2 1        3
2 10-05-20 13-06-20 Canada Vancouver 3 2            4
3 1

2
1 10-05-20 13-06-20 Canada California 3 2 1         1
3 1

2
1 Giza 10-05-20   Toronto 13-06-20  3 2 1          4
2 10-05-20 2-06-20 Giza Vancouver 3 2              5
2 3-06-20 13-06-20 Giza Vancouver 3 2              1
3 2

  */
