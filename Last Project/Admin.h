#pragma once
#include<string>
#include"Identity.h"
#include"Student.h"
#include"Teacher.h"
#include<vector>

using namespace std;
class Admin:public Identity
{
public:
	Admin();
	Admin(string name, string pwd);
	void operMenu() override;
	void addAccount();
	void showAccount();
	void showLab();
	void clearAllOrders();
	//check repeat
	bool checkRepeat(string id,int type);

	//read info from txt files and write it into vector
	void initVector();
	//save registered students, teachers, admins 
	vector<Student> studentVec;
	vector<Teacher> teacherVec;
	vector<Admin> adminVec;
};

