#include<iostream>
#include<string>	
#include"Admin.h"
#include<fstream>
#include<sstream>
#include<Windows.h>

using namespace std;

void Admin::setAdmin(string username, string password, string name, string CNIC, int age, string postalCode, string Job_Title, int year_of_service) {
	User::setUser(username, password, name, CNIC, age, postalCode);
	this->Job_Title = Job_Title;
	this->year_of_service = year_of_service;
}

// Setters
void Admin::setJob_Title(string jt) { Job_Title = jt; }
void Admin::set_year_of_service(int yos) { year_of_service = yos; }

// Getters
string Admin::get_Job_Title() { return Job_Title; }
int Admin::get_year_of_service() { return year_of_service; }

// Utility functions
void admin_login() {
	system("cls");
	string id, pw;
	cout << "\tEnter Login ID: ";
	cin >> id;

	cout << "\tEnter Password: ";
	cin >> pw;

	ifstream infile("admin_cr.txt");
	if (!infile) {
		cout << "\tError: File Can't Open!" << endl;
	}
	else {
		string line;
		bool found = false;
		while (getline(infile, line)) {
			stringstream ss;
			ss << line;
			string userID, userPW;
			char delimiter;
			ss >> userID >> delimiter >> userPW;

			if (id == userID && pw == userPW) {
				found = true;

				cout << "\tPlease Wait";
				for (int i = 0; i < 3; i++) {
					cout << ".";
					Sleep(800);
				}
				system("cls");
				cout << "\tWelcome To This Page!" << endl;
				Admin admin;
				admin.admin_menu();
			}
		}
	}
}
void Admin::admin_menu() {
	system("cls");
	cout << "\t\t\t\t\t\tAdministrator Menu" << endl;
	cout << "\t1. Create Election" << endl;
	cout << "\t2. Add Candidate" << endl;
	cout << "\t3. Remove Candidate" << endl;
	cout << "\t4. View Registered Voters" << endl;
	cout << "\t5. View Registered Candidates" << endl;
	cout << "\t6. View Results" << endl;
	cout << "\t7. Declare Results" << endl;
	cout << "\t8. Display Administrator Information" << endl;
	cout << "\t9. Exit" << endl;
	cout << "\tEnter your choice: ";
}
void Admin::create_Election() {

}
void Admin::AddCandidate() {

}
void Admin::RemoveCandidate() {

}
void Admin::ViewRegisteredVoters() {

}
void Admin::ViewRegisteredCandidates() {
		
}
void Admin::ViewResults() {
	system("cls");
	cout << "\t\t\t\t\t\tElection Results" << endl;
	cout << "\tResults are as follows:" << endl;
	cout << "\tCandidate 1: 100 votes" << endl;
	cout << "\tCandidate 2: 200 votes" << endl;
	cout << "\tCandidate 3: 150 votes" << endl;
	cout << "\tPress any key to continue..." << endl;
	cin.ignore();
	cin.get();
	system("cls");
}
void Admin::DeclareResults() {
	system("cls");
	cout << "\t\t\t\t\t\tElection Results" << endl;
	cout << "\tResults have been declared successfully!" << endl;
	cout << "\tPress any key to continue..." << endl;
	cin.ignore();
	cin.get();
	system("cls");
}
void Admin::DisplayAdministrator() {
	system("cls");
	cout << "\t\t\t\t\t\tAdministrator Information" << endl;
	cout << "\tUsername: " << getUsername() << endl;
	cout << "\tPassword: " << getPassword() << endl;
	cout << "\tName: " << getName() << endl;
	cout << "\tCNIC: " << getCNIC() << endl;
	cout << "\tAge: " << getAge() << endl;
	cout << "\tPostal Code: " << getPostalCode() << endl;
	cout << "\tJob Title: " << Job_Title << endl;
	cout << "\tYear of Service: " << year_of_service << endl;
}