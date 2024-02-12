#pragma once
#include"Identity.h"
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
};

