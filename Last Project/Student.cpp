#include "Student.h"
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include"globalFiles.h"
#include<fstream>
#include<algorithm>
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
		system("pause");
	}

}

void Student::initOrderVector()
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
	cout << "1.\tSmall" << endl << "2.\tMiddle" << endl << "3.\tLarge" << endl;

	int size = 1;
	cin >> size;

	vector<string> daysVec{ "Monday","Tuesday","Wednesday","Thursday","Freiday" };
	vector<string> morningsVec{ "Morning","Afternoon" };
	vector<string> sizesVec{ "Small","Middle","Large" };

	//combine all information into one string and save it into a vector
	string infoString = "ID: " + this->m_ID + " Name:" + this->m_Name + " Day: " + daysVec[day - 1] + " Quarter: " + morningsVec[morning - 1] + " Size: " + sizesVec[size - 1];

	//add an application state;
	infoString += " Status: review";
	infoVec.push_back(infoString);

	//write it into order.txt file
	ofstream ofs(ORDER_FILE, ios::out | ios::app);

	ofs << infoString << endl;

	ofs.close();

}
void Student::showMyOrder()
{
	//loop through vecInfo
	int cnt = 0;
	for (const auto& c : infoVec)
	{
		//truncate the first part
		auto idx_ID = c.find("ID:", 0);
		//crop the first word, namely the id from the whole string
		auto idx_Name = c.find("Name:", 0);
		auto id_string = c.substr(idx_ID + string("ID:").size(), idx_Name - string("ID:").size());
		//trim the string by deleting the spaces in the front and at the end
		[&id_string]() {
			id_string.erase(0, id_string.find_first_not_of(" "));
			id_string.erase(id_string.find_last_not_of(" ") + 1);}();
			
			if (id_string == this->m_ID)
			{
				++cnt;
				//my orders mean: id == this->m_ID
				cout <<cnt<<".\t"<< c << endl;
			}
	}

}
void Student::cancelMyOrder()
{
	//show myOrder first();
	this->showMyOrder();

	cout << "Which order do you want to cancel?" << endl;
	int choice;
	cin >> choice;

	//turn the last word(state) of the infoString into "canclled" 
	//loop through vecInfo
	

	int cnt = 0;
	for (auto& c : infoVec)
	{
		//truncate the first part
		auto idx_ID = c.find("ID:", 0);
		//crop the first word, namely the id from the whole string
		auto idx_Name = c.find("Name:", 0);
		auto id_string = c.substr(idx_ID + string("ID:").size(), idx_Name - string("ID:").size());
		//trim the string by deleting the spaces in the front and at the end

		auto trim = [](string& s) {s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);};
		trim(id_string);

		if (id_string == this->m_ID)
		{
			++cnt;
			if (cnt==choice)
			{
				//my orders mean: id == this->m_ID
				auto idx_Status = c.rfind("Status: ");
				//replace the part behind Status: with Cancelled
				c.replace(idx_Status + string("Status: ").size(), c.size(), "Cancelled");
				cout << c << endl;
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

void Student::showAllOrders()
{
	int cnt = 0;
	for (const auto& c : infoVec)
	{
		++cnt;
		cout <<cnt<<".\t"<< c << endl;
	}

}