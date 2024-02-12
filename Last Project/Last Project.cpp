// Last Project.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include"ReserverSystem.h"
using namespace std;
int main()
{

	ReserveSystem rs;

	while (true)
	{
		rs.showMenu();
		int choice;
		cin >> choice;
		switch (choice)
		{
			//set up the framework first
		case 1:
			//student
			rs.login(choice);
			break;
		case 2:
			//teacher
			rs.login(choice);
			break;
		case 3:
			//admin
			rs.login(choice);
			break;
		case 0:
			//system("exit");
			cout << "welcome to use next time!" << endl;
			return 0;
			break;
		default:	
			cout << "Enter wrong, please reenter!" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
