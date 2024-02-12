#pragma once
#include<string>
#include"Identity.h"
using namespace std;
class Teacher:public Identity
{
public:
	Teacher();
	Teacher(string id, string name,string pwd);
	void showAllOrder();
	void operMenu() override;
	void approve();
	void quit();
	string m_ID;
};

