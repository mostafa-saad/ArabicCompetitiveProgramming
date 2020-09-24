/*
 * expedia_user.h
 *
 *  Created on: Sep 18, 2020
 *      Author: moustafa
 */

#ifndef EXPEDIA_USER_H_
#define EXPEDIA_USER_H_

#include <bits/stdc++.h>
using namespace std;

enum class UserType {
	CusomterUser = 0, AdminUser = 1
};

class User {
protected:
	string user_name;
	string password;
	string name;
	string email;
	UserType type = UserType::CusomterUser;

public:
	User(const User&) = delete;
	void operator=(const User&) = delete;

	User() {
	}

	virtual ~User() {	// To allow dynamic casting, we need 1+ virtual function
	}

	string ToString() const {
		ostringstream oss;
		oss << "Name: " << user_name;
		if (type == UserType::AdminUser)
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

	UserType GetType() const {
		return type;
	}

	void SetType(UserType type) {
		this->type = type;
	}
};

class Admin: public User {
protected:
public:
	Admin(const Admin&) = delete;
	void operator=(const Admin&) = delete;
	Admin() {
		SetType(UserType::AdminUser);
	}
};



#endif /* EXPEDIA_USER_H_ */
