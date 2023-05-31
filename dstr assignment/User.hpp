#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Assignment test.hpp"

using namespace std;

struct user{
	string username;
	string password;
	string email;
	user* NextAddress;
}*usHead;

user* createNewUserNode(string username, string password, string email){
    user* newnode = new user;
    newnode -> username = username;
	newnode -> password = password;
	newnode -> email = email;
    newnode-> NextAddress = NULL;
    return newnode;
}


void InsertIntoStartofUserList(user* newnode){
	if (usHead == NULL)
	{
		usHead  = newnode;
	}
	else
	{
		newnode -> NextAddress = usHead;
		usHead = newnode;
	}	
	cout<<"succesfully registered"<<endl;

}

void InsertIntoStartofUserList(user* newnode){
	if (usHead == NULL)
	{
		usHead  = newnode;
	}
	else
	{
		newnode -> NextAddress = usHead;
		usHead = newnode;
	}	
	cout<<"registered successfully"<<endl;
}

void DisplayUsers() {
    if (usHead == nullptr) {
        cout << "No users found in the list." << endl;
    }
    else {
        user* temp = usHead;
        while (temp != nullptr) {
            cout << "Username: " << temp->username << endl;
            cout << "Password: " << temp->password << endl;
            cout << "Email: " << temp->email << endl;
            //cout << "Last Login Date: " << system_clock::to_time_t(temp->lastLoginDate) << endl;
            cout << endl;
            temp = temp->NextAddress;
        }
    }
}

bool login(const string& username, const string& password) {
    user* current = usHead;
    while (current != nullptr) {
        if (username == current->username && password == current->password) {
            return true;
        }
        current = current->NextAddress;
    }
    return false;
}