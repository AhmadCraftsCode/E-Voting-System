#include<iostream>
#include"Voter.h"
#include<fstream>
#include<sstream>
#include<Windows.h>

using namespace std;
// Function to set voter information
void Voter::setVoter(string username, string password, string name, string CNIC, int age, string postalCode, bool hasVoted) {
	User::setUser(username, password, name, CNIC, age, postalCode);
	this->hasVoted = hasVoted;
}
// Setters
void Voter::setHasVoted(bool hasVoted) { this->hasVoted = hasVoted; }

// Getters
bool Voter::getHasVoted() { return hasVoted; }

// Cast vote
void Voter::castVote() {
	system("cls");
	if (hasVoted) {
		cout << "\tYou have already voted!" << endl;
	}
	else {
		int vote;
		cout << "\tEnter your vote: ";
		cin >> vote;

		ofstream outfile("votes.txt", ios::app);
		if (!outfile) {
			cout << "\tError: File Can't Open!" << endl;
		}
		else {
			outfile << username << " " << vote << endl;
			hasVoted = true;
			cout << "\tVote casted successfully!" << endl;
		}
	}
}

// Voter menu
void Voter::voter_menu() {
	system("cls");
	int choice;
	cout << "\t\t\t\t\t\tVoter Menu" << endl;
	cout << "\t1. Cast Vote" << endl;
	cout << "\t2. View Voter Information" << endl;
	cout << "\t3. Exit" << endl;
	cout << "\tEnter your choice: ";
	cin >> choice;

	switch (choice) {
	case 1:
		castVote();
		break;
	case 2:
		displayVoterInfo();
		break;
	case 3:
		exit(0);
	default:
		cout << "\tInvalid choice!" << endl;
		break;
	}
}

// Function to display voter information
void Voter::displayVoterInfo() {
	system("cls");
	cout << "\t\t\t\t\t\tVoter Information" << endl;
	cout << "\tUsername: " << getUsername() << endl;
	cout << "\tPassword: " << getPassword() << endl;
	cout << "\tName: " << getName() << endl;
	cout << "\tCNIC: " << getCNIC() << endl;
	cout << "\tAge: " << getAge() << endl;
	cout << "\tPostal Code: " << getPostalCode() << endl;
	cout << "\tHas Voted: " << (hasVoted ? "Yes" : "No") << endl;
}

// Global functions definitions
void voter_login() {
	system("cls");
	string id, pw;
	cout << "\tEnter Login ID: ";
	cin >> id;

	cout << "\tEnter Password: ";
	cin >> pw;

	ifstream infile("voter_cr.txt");
	if (!infile) {
		cout << "\tError: File Can't Open!" << endl;
	}
	else {
		string line;
		bool found = false;
		while (getline(infile, line)) {
			stringstream ss;
			ss << line;

			string username, password, name, CNIC, postalCode;
			int age;
			bool hasVoted;

			char delimiter;

			ss >> username >> delimiter >> password >> delimiter >> name >> delimiter >> CNIC >> delimiter >> age >> delimiter >> postalCode >> delimiter >> hasVoted >> delimiter;

			if (id == username && pw == password) {
				found = true;

				cout << "\tPlease Wait";
				for (int i = 0; i < 3; i++) {
					cout << ".";
					Sleep(800);
				}
				system("cls");
				cout << "\tWelcome To This Page!" << endl;
				Voter voter(username, password, name, CNIC, age, postalCode, hasVoted);
				voter.voter_menu();
			}
		}
	}
}

void voter_signup() {
	system("cls");
	string username, password,name,cnic,postalcode;
	int age;
	bool hasVoted = false;
	string postalCode;
	cout << "\tEnter Login ID: ";
	cin >> username;
	cout << "\tEnter name: ";
	cin >> name;
	cout << "\tEnter CNIC: ";
	cin >> cnic;
	{

		cout << "\tEnter Age: ";
		cin >> age;
		
	}
	cout << "\tEnter Postal Code: ";
	cin >> postalcode;
	{

	start:
		cout << "\tEnter A Strong Password: ";
		cin >> password;
		if (password.length() < 8) {

			cout << "\tEnter Minimum 8 Characters!" << endl;
			goto start;
		}
	}
	if (age < 18) {

		cout << "\tAge must be 18 or above!" << endl;
		signup_menu();
	}
	ofstream outfile("voter_cr.txt", ios::app);
	if (!outfile) {
		cout << "\tError: File Can't Open!" << endl;
	}
	else {
		outfile << "\t" << username << " : " << password <<" : " << name << " : " << cnic << " : " << age << " : " << postalcode << " : " << hasVoted <<" : "<< endl;
		cout << "\tUser Registered Successfuly!" << endl;
	}
	outfile.close();
	Sleep(3000);
}

