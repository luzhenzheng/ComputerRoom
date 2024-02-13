#include "Student.h"
#include<iostream>
using namespace std;

Student::Student()
{

}
Student::Student(string id, string name, string pwd)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_Pwd = pwd;
}
void Student::operMenu()
{
	while (true)
	{
		//clear the screen first
		system("cls");
		cout << "welcome£º" << this->m_Name << "login£¡" << endl;
		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          1.applyForOrder              |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          2.showMyOrder          |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          3.showAllOrder          |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          4.cancelMyOrder              |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          0.logout              |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t ----------------------------------\n";
		cout << "please choose your option£º " << endl;
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			applyForOrder();
			break;
		case 2:
			showMyOrder();
			break;
		case 3:
			showAllOrders();
			break;
		case 4:
			cancelMyOrder();
			break;
		default:
			break;
		}

		if (choice == 0)
		{
			cout << "log out success!" << endl;
			break;
		}
	}
	

}
void Student::applyForOrder()
{
	system("pause");
}
void Student::showMyOrder()
{
	system("pause");
}
void Student::cancelMyOrder()
{
	system("pause");
}
void Student::quit()
{

}

void Student::showAllOrders()
{
	system("pause");
}