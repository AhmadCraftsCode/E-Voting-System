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