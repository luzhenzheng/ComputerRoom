#pragma once
#include<string>
#include"Identity.h"
using namespace std;
#include<vector>
class Teacher:public Identity
{
public:
	Teacher();
	Teacher(string id, string name,string pwd);
	void showAllOrders();
	void operMenu() override;
	void approve();
	string m_ID;
	void initOrderVector();
	vector<string> infoVec;//this vector stores all information 
};

