#include <iostream>
using namespace std;
#include "Assignment.hpp"

int main(){
    int option;

	do{
		cout << "1. Display universities" << endl;
		cout << "2. sort universities" << endl;
		cout << "3. search university details" << endl;
		cout << "4. Resgister as customer" << endl;
		cout << "5. Login" << endl << endl;

		cout << "choose a function :" << endl;
		cin >> option;

        switch (option){
            case 1:{
                //displayUniversities();
            }
            case 2:{
                //sort()
            }
            case 3:{
                string searchValue;
                cout << "enter the university name :";
                cin >> searchValue;
            // bidirectionalSearch(searchValue);
            }
            case 4:{
                string username;
                string password;
                string email;
                string address;

                cout << "Userame :" << endl;
                cin >> username;

                cout << "Password :" << endl;
                cin >> password;
                
                cout << "email :" << endl;
                cin >> email;
                
                cout << "date of birth :" << endl;
                cin >> address;

                user* usernode = createNewUserNode(username, password, email, address);
                InsertIntoStartofUserList (usernode);
                break;
            }   
            case 5:{
                //login();
            }
            default:{
                cout<<"please enter from the option above!" <<endl <<endl;
            }
        }
	}while (option != 5);
}