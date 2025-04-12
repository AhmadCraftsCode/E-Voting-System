#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

using namespace std;

class Admin : public User {
private:
	string Job_Title;
	int year_of_service;
public:
	// Default parameterized ctor
	Admin(string username = " ", string password = " ", string name = " ", string CNIC = " ", int age = 0, string postalCode = " ", string Job_Title = "", int year_of_service = 0) {
		setUser(username, password, name, CNIC, age, postalCode);
		this->Job_Title = Job_Title;
		this->year_of_service = year_of_service;
	}

	// Function to set admin information
	void setAdmin(string username, string password, string name, string CNIC, int age, string postalCode, string Job_Title, int year_of_service);

	// Setters
	void setJob_Title(string);
	void set_year_of_service(int);

	// Getters
	string  get_Job_Title();
	int  get_year_of_service();

	// Utility functions
	void admin_menu();
	void create_Election();
	void AddCandidate();
	void RemoveCandidate();
	void ViewRegisteredVoters();
	void ViewRegisteredCandidates();
	void ViewResults();
	void DeclareResults();
	void DisplayAdministrator();
};

void admin_login();

#endif
