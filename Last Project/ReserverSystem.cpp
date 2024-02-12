#include "ReserverSystem.h"
#include"globalFiles.h"
#include<fstream>

void ReserveSystem::showMenu()
{
	cout << "======================  Wecome!  ====================="
		<< endl;
	cout << endl << "Please enter your identity" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.student representative           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.teacher            |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.admin              |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.exit               |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "please enter your choice: ";
}

void ReserveSystem::login(int type)
{
	ifstream ifs;
	//where should I use polymorphism
	//verify login according to type
	string id;
	switch (type)
	{
	case 1:
		//student
		cout << "please enter your ID:" << endl;
		cin >> id;
		break;
	case 2:
		//teacher
		cout << "please enter your ID:" << endl;
		cin >> id;
		break;
	default:
		break;
	}
	cout << "please enter your name:" << endl;
	string name;
	cin >> name;

	cout << "please enter your password:" << endl;
	string password;
	cin >> password;

	//check whether it is registered in the txt files, rather than check the vectors
	if (type == 1 )
	{
		ifs.open(STUDENT_FILE, ios::in);
		if (!ifs.is_open())
		{
			cout << "file not found!" << endl;
			ifs.close();
			return;
		}
		string fID, fName, fPassword;
		while (ifs >> fID >> fName >> fPassword)//note the ifs read
		{
			if (fID == id&&fName==name&&password==fPassword)
			{
				cout << "login success!" << endl;
				//go to student submenu
				Student* ps = new Student(id,name,password);
				ps->operMenu();
				delete ps;
				return;
			}
		}
		cout << "login fail!" << endl;
		return;
	}
	else if (type ==2)
	{
		ifs.open(TEACHER_FILE, ios::in);
		if (!ifs.is_open())
		{
			cout << "file not found!" << endl;
			ifs.close();
			return;
		}

		string fID, fName, fPassword;
		while (ifs>>fID>>fName>>fPassword)
		{
			if (fID == id && fName == name && password == fPassword)
			{
				cout << "login success!" << endl;
				//go to teacher submenu
				Teacher* pt = new Teacher(id, name, password);
				pt->operMenu();
				delete pt;
				return;
			}
		}
		cout << "login fail!" << endl;
		return;
	}
	else
	{
		ifs.open(ADMIN_FILE, ios::in);
		if (!ifs.is_open())
		{
			cout << "file not found!" << endl;
			ifs.close();
			return;
		}

		string fName, fPassword;
		while (ifs >> fName >> fPassword)
		{
			if (fName==name&&fPassword==password)
			{
				cout << "login success!" << endl;
				system("pause");
				//go to admin submenu
				Admin* pa = new Admin(name, password);
				pa->operMenu();
				delete pa;

				return;
			}
		}
		cout << "login fail!" << endl;
		return;
	}
}

