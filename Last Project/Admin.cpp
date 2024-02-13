#include "Admin.h"
#include<iostream>
#include<vector>
#include<fstream>
#include"globalFiles.h"
#include<algorithm>

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
	//just load the information by looping through stuVector,teachVector
	cout << "Student Infos:" << endl;
	for (const auto&c: studentVec )
	{
		cout << "ID: " << c.m_ID << "\tName: " << c.m_Name << "\tPassword: " << c.m_Pwd << endl;
	}

	cout << "Teacher Infos:" << endl;
	for (const auto& c : teacherVec)
	{
		cout << "ID: " << c.m_ID << "\tName: " << c.m_Name << "\tPassword: " << c.m_Pwd << endl;
	}
	cout << "Admin Infos:" << endl;
	for (const auto& c : adminVec)
	{
		cout << "\tName: " << c.m_Name << "\tPassword: " << c.m_Pwd << endl;
	}
	system("pause");
}

void Admin::showLab()
{
	//just loop through map and display here
	for (const auto& c : PCRoomMap)
	{
		cout << "ID: " << c.first << "\tCapacity:" << c.second << endl;
	}
	system("pause");
}

void Admin::clearAllOrders()
{
	ofstream ofsOrder (ORDER_FILE, std::ofstream::trunc);
	ofsOrder.close();
	cout << "all order cleared!" << endl;
	system("pause");
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

class GreaterStudent
{
public:
	bool operator()(const Student& lhs, const Student& rhs)
	{
		return lhs.m_ID < rhs.m_ID;
	}
};

class GreaterTeacher
{
public:
	bool operator()(const Teacher& lhs, const Teacher& rhs)
	{
		return lhs.m_ID < rhs.m_ID;
	}
};

void Admin::initVector()
{
	//read info from txt file
	ifstream ifsStudent(STUDENT_FILE, ios::in);
	ifstream ifsTeacher(TEACHER_FILE, ios::in);
	ifstream ifsAdmin(ADMIN_FILE, ios::in);
	ifstream ifsComputerRoom(PCROOM_FILE, ios::in);

	if (ifsStudent.is_open()&&ifsAdmin.is_open()&&ifsTeacher.is_open()&&ifsComputerRoom.is_open())
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
		
		string roomId, roomCapcity;
		while (ifsComputerRoom>>roomId>>roomCapcity)
		{
			this->PCRoomMap.insert(make_pair(roomId,roomCapcity));
		}

		ifsAdmin.close();
		ifsTeacher.close();
		ifsStudent.close();
		ifsComputerRoom.close();
	
		cout << studentCnt << " Students information registered!" << endl;
		cout << teacherCnt << " Teachers information registered!" << endl;
		cout << adminCnt << " Admins information registered!" << endl;

		//sort the vector according to their ID, so that it looks better when shows INFO
		sort(studentVec.begin(), studentVec.end(), GreaterStudent());
		sort(teacherVec.begin(), teacherVec.end(), GreaterTeacher());

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
	else
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