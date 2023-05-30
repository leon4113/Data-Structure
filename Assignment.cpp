#include <iostream>
using namespace std;
#include "Assignment.hpp"
#include "admin.hpp"

void login(const string& username, const string& password) {
    if(username == "admin" && password == "admin"){
        Admin_menu();    
	}
    user* current = usHead;
    while (current != nullptr) {
        if (username == current->username && password == current->password) {
            customerMenu();
        }
        current = current->NextAddress;
    }
    cout << "Incorrect username or password"<<endl;
}

int main(){
	while(true){
		int option;

		cout << "1. Display universities" << endl;
		cout << "2. sort universities" << endl;
		cout << "3. search university details" << endl;
		cout << "4. Resgister as customer" << endl;
		cout << "5. Login" << endl << endl;

		cout << "choose a function :" << endl;
		cin >> option;

		if (option == 1){
			displayUniversities();
		}
        else if (option == 2){
			quicksortUniversities();
		}
        else if (option == 3){
			string searchValue;
			cout << "enter the university name :";
			cin >> searchValue;
            bidirectionalSearch(searchValue);
		}
        else if (option == 4){
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
		else if(option == 5){
			string username;
			string password;
			cout << "Username :" << endl;
			cin >> username;
			cout << "Password :" << endl;
			cin >> password;
			login(username, password);
			
		}
		else{
			cout<<"please enter from the option above!" <<endl <<endl;
		}
	}
}