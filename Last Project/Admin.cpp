#include "Admin.h"
#include<iostream>
#include<vector>
#include<fstream>
#include"globalFiles.h"
using namespace std;
Admin::Admin()
{

}
Admin::Admin(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Admin::addAccount()
{
	//just append new account on the corresponding txt files
	ofstream ofs;

	cout << "Please enter what person you want to add?" << endl;
	cout << "1. Student\t" << endl;
	cout << "2. Teacher\t" << endl;

	int choice;
	cin >> choice;
	if (choice == 1)
	{
		ofs.open(STUDENT_FILE, ios::out | ios::app);
		if (!ofs.is_open())
		{
			cout << "file not found!" << endl;
			return;
		}
	}
	else if (choice == 2)
	{
		ofs.open(TEACHER_FILE, ios::out | ios::app);
		if (!ofs.is_open())
		{
			cout << "file not found!" << endl;
			return;
		}
	}

	string id, name, password;
	cout << "Please enter id of the person:" << endl;
	cin >> id;
	cout << "Please enter name for the person" << endl;
	cin >> name;
	cout << "Please enter password for the person:" << endl;
	cin >> password;

	//write id, name ,password into student.txt and teacher.txt file
	if (choice ==1)
	{
		ofs << id << " " << name << " " << password << endl;
		cout << "enter information of " << name << " complete!" << endl;
	}
	else
	{
		ofs << id << " " << name << " " << password << endl;
		cout << "enter information of " << name << " complete!" << endl;
	}

}
void Admin::showAccount()
{
	ifstream ifs;
	cout << "Please enter what person you want to show?" << endl;
	cout << "1. Student\t" << endl;
	cout << "2. Teacher\t" << endl;

	int choice;
	cin >> choice;

	if (choice==1)
	{
		ifs.open(STUDENT_FILE, ios::in);
		if (!ifs.is_open())
		{
			cout << "file not found!" << endl;
			return;
		}
		else
		{
			string id, name, password;
			while (ifs >> id >> name >> password)
			{
				cout << "ID: " << id << "name: " << name << " password: " << password << endl;
			}
		}
	}
	else
	{
		ifs.open(TEACHER_FILE, ios::in);
		if (!ifs.is_open())
		{
			cout << "file not found!" << endl;
			return;
		}
		else
		{
			string id, name, password;
			while (ifs >> id >> name >> password)
			{
				cout << "ID: " << id << "name: " << name << " password: " << password << endl;
			}
		}
	}

	system("pause");
}
void Admin::showLab()
{

}
void Admin::clearAllOrders()
{

}

void Admin::operMenu()
{
	while (true)
	{
		//clear the screen first
		system("cls");
		cout << "welcome:" << this->m_Name << " login£¡" << endl;
		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          1.addAccount              |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          2.showAccount          |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          3.showLab          |\n";
		cout << "\t\t|                                 |\n";
		cout << "\t\t|          4.clearAllOrders              |\n";
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
			addAccount();
			break;
		case 2:
			showAccount();
			break;
		case 3:
			showLab();
			break;
		case 4:
			clearAllOrders();
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
	}
	
}

void Admin::initVector()
{
	//read info from txt file
	ifstream ifsStudent(STUDENT_FILE, ios::in);
	ifstream ifsTeacher(TEACHER_FILE, ios::in);
	ifstream ifsAdmin(ADMIN_FILE, ios::in);

	if (ifsStudent.is_open()&&ifsAdmin.is_open()&&ifsTeacher.is_open())
	{
		string id, name, password;
		while (ifsStudent>>id>>name>>password)
		{
			this->studentVec.push_back(Student(id, name, password));
		}

		string id, name, password;
		while (ifsStudent >> id >> name >> password)
		{
			this->studentVec.push_back(Student(id, name, password));
		}
	}
	else
	{
		cout << "files not found!" << endl;
		return;
	}
}