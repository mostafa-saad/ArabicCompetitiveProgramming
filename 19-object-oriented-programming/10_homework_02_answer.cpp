#include <bits/stdc++.h>
using namespace std;

class CommunityMember {
};



class Student : public CommunityMember {
};

class Alumnus : public CommunityMember {
};

class Employee : public CommunityMember {
};





class Staff : public Employee {
};

class Faculty : public Employee {
};





class Teacher : public Faculty {
};

class Administrator : public Faculty {
};




class AdministratorTeacher : public Teacher, public Administrator {
};


int main() {


	return 0;
}
