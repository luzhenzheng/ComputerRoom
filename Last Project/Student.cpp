#include "Student.h"
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include"globalFiles.h"
#include<fstream>

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
		this->initOrderVector();
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

void Student::initOrderVector()
{
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
		while (getline(ifs,infoString))
		{
			infoVec.push_back(infoString);
			++cnt;
		}
		cout << cnt << " orders detected!" << endl;
	}
}


void Student::applyForOrder()
{
	//write the string information into the order.txt file 
	int day;
	cout << "On which day do you want to order?" << endl;
	cout << "1.Monday\t2.Tuesday\t3.Wednesday\t4.Thursday,\t5.Friday" << endl;
	cin >> day;

	cout << "Morning or Afternoo?" << endl;
	cout << "1.Morning\t2.Afternoon" << endl;
	int morning;
	cin >> morning;

	cout << "Small/Middle/Large?" << endl;
	cout << "1.\tSmall" << endl << "2.\tMiddle" << endl<< "3.\tLarge" << endl;

	int size = 1;
	cin >> size;

	vector<string> daysVec{ "Monday","Tuesday","Wednesday","Thursday","Freiday" };
	vector<string> morningsVec{ "Morning","Afternoon" };
	vector<string> sizesVec{ "Small","Middle","Large" };

	//combine all information into one string and save it into a vector
	string infoString = this->m_ID+' ' + daysVec[day - 1] + ' ' + morningsVec[morning - 1]+' '+ sizesVec[size - 1];

	infoVec.push_back(infoString);

	//write it into order.txt file
	ofstream ofs(ORDER_FILE, ios::out|ios::app);

	ofs << infoString << endl;

	ofs.close();
	
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
	for (const auto&c:infoVec)
	{
		cout << c << endl;
	}
	system("pause");
}