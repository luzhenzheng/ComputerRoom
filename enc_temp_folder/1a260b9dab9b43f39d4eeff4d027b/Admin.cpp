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

	int type;
	cin >> type;
	if (type == 1)
	{//student
		ofs.open(STUDENT_FILE, ios::out | ios::app);
		if (!ofs.is_open())
		{
			cout << "file not found!" << endl;
			return;
		}
	}
	else if (type == 2)
	{//teacher
		ofs.open(TEACHER_FILE, ios::out | ios::app);
		if (!ofs.is_open())
		{
			cout << "file not found!" << endl;
			return;
		}
	}

	string id, name, password;
	while (true)
	{
		//check repeat first 

		cout << "Please enter id of the person:" << endl;
		cin >> id;
		if (!checkRepeat(id,type))
		{

			break;
		}
		else
		{
			cout << "ID is repeated!" << endl;
		}

	}

	cout << "Please enter name for the person" << endl;
	cin >> name;
	cout << "Please enter password for the person:" << endl;
	cin >> password;

	

	//write id, name ,password into student.txt and teacher.txt file
	if (type ==1)
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
	ifstream ifsStudent;
	ifstream ifsTeacher;
	ifstream ifsAdmin;

	ifsStudent.open(STUDENT_FILE, ios::in);
	if (!ifsStudent.is_open())
	{
		cout << "Student file not found!" << endl;
		ifsStudent.close();
	}

	ifsTeacher.open(TEACHER_FILE, ios::in);
	if (!ifsTeacher.is_open())
	{
		cout << "Teacher file not found!" << endl;
		ifsTeacher.close();
	}
	ifsAdmin.open(ADMIN_FILE, ios::in);
	if (!ifsAdmin.is_open())
	{
		cout << "Admin file not found!" << endl;
		ifsAdmin.close();
	}


	string id, name, password;
	cout << "Students Information:" << endl;
	while (ifsStudent>>id>>name>>password)
	{
		cout << "ID: " << id << "\tName: " << name << "\tPassword: " << password << endl;
	}

	cout << "Teachers Information:" << endl;
	while (ifsTeacher >> id >> name >> password)
	{
		cout << "ID: " << id << "\tName: " << name << "\tPassword: " << password << endl;
	}
	
	cout << "Admins Information:" << endl;
	while (ifsAdmin >> id >> name >> password)
	{
		cout << "ID: " << id << "\tName: " << name << "\tPassword: " << password << endl;
	}
	ifsStudent.close();
	ifsTeacher.close();
	ifsAdmin.close();
	
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
		system("cls");
		//read information and write it into vectors everytime when admin logs in
		this->initVector();
		//clear the screen first
		
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
		string studentId, studentName, studentPassword;
		int studentCnt = 0;
		while (ifsStudent>> studentId >> studentName >> studentPassword)
		{
			this->studentVec.push_back(Student(studentId, studentName, studentPassword));
			++studentCnt;
		}
		int teacherCnt = 0;
		string teacherId, teacherName, teacherPassword;
		while (ifsTeacher >> teacherId >> teacherName >> teacherPassword)
		{
			this->teacherVec.push_back(Teacher(teacherId, teacherName, teacherPassword));
			teacherCnt++;
		}
		int adminCnt = 0;
		string adminId, adminName, adminPassword;
		while (ifsAdmin >> adminId >> adminName >> adminPassword)
		{
			this->adminVec.push_back(Admin(teacherName, teacherPassword));
			++adminCnt;
		}

		ifsAdmin.close();
		ifsTeacher.close();
		ifsStudent.close();
	
		cout << studentCnt << " Students information registered!" << endl;
		cout << teacherCnt << " Teachers information registered!" << endl;
		cout << adminCnt << " Admins information registered!" << endl;
	
	}
	else
	{
		cout << "files not found!" << endl;
		return;
	}
}

bool Admin::checkRepeat(string id, int type)
{
	if (type == 1)
	{
		for (auto it = studentVec.begin(); it < studentVec.end(); it++)
		{
			if (it->m_ID==id)
			{
				return true;
			}
		}
		return false;
	}
	else if (type ==2 )
	{
		for (auto it = teacherVec.begin(); it < teacherVec.end(); it++)
		{
			if (it->m_ID == id)
			{
				return true;
			}
		}
		return false;
	}
}