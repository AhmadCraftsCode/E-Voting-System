#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
protected:
    string username;
    string password;
    string name;
    string CNIC;
    int age;
    string postalCode;

public:
    // Default parameterized constructor
    User(string username = " ", string password = " ", string name = " ", string CNIC = " ", int age = 0, string postalCode = " ")
    {
        this->username = username;
        this->password = password;
        this->name = name;
        this->CNIC = CNIC;
        this->age = age;
        this->postalCode = postalCode;
    }

    void setUser(string, string, string, string, int, string);

    // Setters
    void setUsername(string);
    void setPassword(string);
    void setName(string);
    void setCNIC(string);
    void setAge(int);
    void setPostalCode(string);

    // Getters
    string getUsername();
    string getPassword();
    string getName();
    string getCNIC();
    int getAge();
    string getPostalCode();

    // login function
    void login();

    // Function to display user information
    void displayUserInfo();
};

void login_menu(User &);
void main_menu(User &);
void signup_menu();

#endif