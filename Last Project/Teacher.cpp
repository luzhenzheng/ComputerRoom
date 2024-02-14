#include "Teacher.h"
#include<iostream>
#include<fstream>
#include"globalFiles.h"
using namespace std;
Teacher::Teacher()
{

}
Teacher::Teacher(string id, string name, string pwd)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}
void Teacher::showAllOrders()
{
	int cnt = 0;
	for (const auto& c : infoVec)
	{
		++cnt;
		cout << cnt << ".\t" << c << endl;
	}
}
void Teacher::approve()
{
	//show only the orders in review
	int cnt = 0;
	for (const auto& c : infoVec)
	{
		auto idx_Status = c.rfind("Status:");
		auto status_string = c.substr(idx_Status + string("Status: ").size(), c.size());
		//++cnt;
		//cout << cnt << ".\t" << c << endl;

		if (status_string == "review")
		{
			++cnt;
			cout << cnt << ".\t" << c << endl;
		}
	}


	int choice;
	cout << "which order do you want to review?" << endl;
	cin >> choice;
	int cnt = 0;
	for (auto& c : infoVec)
	{
		++cnt;
		auto idx_Status = c.rfind("Status: ");
		if (cnt == choice)
		{
			cout << "approve or deny?" << endl;
			cout << "1.\tapprove" << endl;
			cout << "2.\tdeny" << endl;
			int decision;
			cin >> decision;
			while (true)
			{
				if (decision == 1 || decision == 2)
				{
					break;
				}
				cout << "please enter again:" << endl;
			}
			if (decision == 1)
			{
				c.replace(idx_Status + string("Status: ").size(), c.size(), "approved");
				cout << cnt << ".\t" << c << endl;
			}
			else
			{
				c.replace(idx_Status + string("Status: ").size(), c.size(), "deny");
				cout << cnt << ".\t" << c << endl;
			}

		}
	}

	//write the changed infoVec back into .txt file
	ofstream ofs(ORDER_FILE, ios::out || ios::trunc);
	for (const auto& c : infoVec)
	{
		ofs << c << endl;
	}
	ofs.close();
}

void Teacher::operMenu()
{
	while (true)
	{
		system("cls");
		this->initOrderVector();
		//read information and write it into vectors everytime when admin logs in
		//this->initVector();
		//clear the screen first

		cout << "welcome teacher: " << this->m_Name << " login£¡" << endl;
		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|          1.show all Orders          |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|          2.review order        |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|          0.log out         |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t ----------------------------------\n";
		cout << "please enter your option: " << endl;

		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			showAllOrders();
			break;
		case 2:
			approve();
			break;
		case 0:
			cout << "log out success!" << endl;
			break;
		default:
			break;
		}

		if (choice == 0)
		{
			break;
		}
		system("pause");
	}

}

void Teacher::initOrderVector()
{
	//clear the vector first
	infoVec.clear();
	//this function should be called everytime when a new student logs in
	//read info from order.txt file
	ifstream ifs(ORDER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "file not found!" << endl;
	}
	else
	{
		string infoString;
		int cnt = 0;
		//dont use ifs>>infoString to read, because it will read all separate words
		//use getline instead
		while (getline(ifs, infoString))
		{
			infoVec.push_back(infoString);
			++cnt;
		}
		cout << cnt << " orders detected!" << endl;
	}
	ifs.close();
}