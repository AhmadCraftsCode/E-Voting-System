#include<iostream>
#include<string>	
#include"User.h"
#include<fstream>
#include<sstream>
#include<Windows.h>

using namespace std;
void login_menu(User& voter) {
	cout << "\t\t\t\t.....................................................\n";
	cout << "\t\t\t\t::::::::::::::: LOGIN TO YOUR ACCOUNT :::::::::::::::\n";
	cout << "\t\t\t\t:\t\t1. Admin                            :\n";
	cout << "\t\t\t\t:\t\t2. Voter                            :\n";
	cout << "\t\t\t\t:\t\t3. Candidate                        :\n";
	cout << "\t\t\t\t:\t\t4. Main Menu                        :\n";
	cout << "\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::\n";

	int choice;
	cout << "\t\t\t\t\t\tYour choice here : ";
	cin >> choice;

	switch (choice) {
	case 1:
		break;
	case 2:
		voter.login();
		break;
	case 3:
		//Candidate candidate;
		//candidate.login();
		break;
	case 4:
		main_menu(voter);
		break;
	default:
		cout << "Invalid choice!\n";
		login_menu(voter);
		break;
	}
}
void signup_menu() {
	cout << "\t\t\t\t.................................................\n";
	cout << "\t\t\t\t::::::::::::::: CREATE AN ACCOUNT :::::::::::::::\n";
	cout << "\t\t\t\t:\t\t1. Admin                           :\n";
	cout << "\t\t\t\t:\t\t2. Voter                         :\n";
	cout << "\t\t\t\t:\t\t3. Candidate                           :\n";
	cout << "\t\t\t\t:\t\t4. Main Menu                           :\n";
	cout << "\t\t\t\t::::::::::::::::::::::::::::::::::::::::::::::::::::\n";

	int choice;
	cout << "\t\t\t\t\t\tYour choice here : ";
	cin >> choice;

	switch (choice) {
	case 1:
		//Administrator admin;
		//admin.signup();
		break;
	case 2:
		//Voter voter;
		//voter.signup();
		break;
	case 3:
		//Candidate candidate;
		//candidate.signup();
		break;
	case 4:
		//main_menu();
		break;
	default:
		break;
	}
}
void main_menu(User& voter) {
	cout << "\t\t\t\t.....................................................\n";
	cout << "\t\t\t\t::::::::::::::: ONLINE VOTING SYSTEM ::::::::::::::::\n";
	cout << "\t\t\t\t:\t\t1. Login                            :\n";
	cout << "\t\t\t\t:\t\t2. Sign Up                           :\n";
	cout << "\t\t\t\t:\t\t3. Exit                             :\n";
	cout << "\t\t\t\t:::::::::::::::::::::::::::::::::::::::::::::::::::::\n";

	int choice;
	cout << "\t\t\t\t\t\tYour choice here : ";
	cin >> choice;

	switch (choice) {
	case 1:
		login_menu(voter);
		break;
	case 2:
		signup_menu();
		break;
	case 3:
		cout << "\t\t\t    Hopefuly it was a nice experience using online voting system!\n";
		break;
	default:
		cout << "Invalid choice!\n";
		main_menu(voter);
		break;
	}
}

// Function to set user information
void User::setUser(string username, string password, string name, string CNIC, int age, string postalCode) {
	this->username = username;
	this->password = password;
	this->name = name;
	this->CNIC = CNIC;
	this->age = age;
	this->postalCode = postalCode;
}

// Setters 
void User::setUsername(string username) { this->username = username; }
void User::setPassword(string password) { this->password = password; }
void User::setName(string name) { this->name = name; }
void User::setCNIC(string CNIC) { this->CNIC = CNIC; }
void User::setAge(int age) { this->age = age; }
void User::setPostalCode(string postalCode) { this->postalCode = postalCode; }

// Getters
string User::getUsername() { return username; }
string User::getPassword() { return password; }
string User::getName() { return name; }
string User::getCNIC() { return CNIC; }
int User::getAge() { return age; }
string User::getPostalCode() { return postalCode; }

// User login function
void User ::login() {
	system("cls");
	string id, pw;
	cout << "\tEnter Login ID: ";
	cin >> id;

	cout << "\tEnter Password: ";
	cin >> pw;

	ifstream infile("login.txt");
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
			}
		}
		if (!found) {
			cout << "\tError: Incorrect Login ID Or Password!" << endl;
		}
	}
	infile.close();
	Sleep(5000);
}

// Function to display user information	
void User::displayUserInfo() {
	cout << "Username: " << username << endl;
	cout << "Password: " << password << endl;
	cout << "Name: " << name << endl;
	cout << "CNIC: " << CNIC << endl;
	cout << "Age: " << age << endl;
	cout << "Postal Code: " << postalCode << endl;
}