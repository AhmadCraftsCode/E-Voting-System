#ifndef VOTER_H
#define VOTER_H

#include<string>
#include"User.h"

using namespace std;

class Voter : public User {
private:
	bool hasVoted;

public:
	// Default parameterized constructor
	Voter(string username = " ", string password = " ", string name = " ", string CNIC = " ", int age = 0, string postalCode = " ", bool hasVoted = false) : User(username, password, name, CNIC, age, postalCode) {
		this->hasVoted = hasVoted;
	}

	void setVoter(string username, string password, string name, string CNIC, int age, string postalCode, bool hasVoted);

	// Setters
	void setHasVoted(bool);

	// Getters
	bool getHasVoted();

	// Cast vote
	void castVote();

	// Voter menu
	void voter_menu();

	// Function to display voter information
	void displayVoterInfo();

	
};

void voter_login();
void voter_signup();


#endif