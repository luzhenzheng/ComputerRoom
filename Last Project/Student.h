#pragma once
#include"Identity.h"
#include<vector>
#include<string>
class Student:public Identity
{
public:
	Student();
	Student(string id, string name, string pwd);
	string m_ID = "";
	void operMenu() override;
	void applyForOrder();
	void showMyOrder();
	void showAllOrders();
	void cancelMyOrder();
	void quit();
	void initOrderVector();
	vector<string> infoVec;//this vector stores all information 
};
