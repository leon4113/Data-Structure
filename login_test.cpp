#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct User {
    string username;
    string password;
    User* next;

    User(const string& uname, const string& pwd) : username(uname), password(pwd), next(nullptr) {}
};

class UserList {
private:
    User* head;

public:
    UserList(){} 

    ~UserList() { 
        User* current = head;
        while (current != nullptr) {
            User* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void addUser(const string& username, const string& password) {
        User* newUser = new User(username, password);
        if (head == nullptr) {
            head = newUser;
        } else {
            User* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newUser;
        }
    }

    bool login(const string& username, const string& password) {
        User* current = head;
        while (current != nullptr) {
            if (username == current->username && password == current->password) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main() {
    UserList userList; 

    ifstream file("admin_credentials.txt");
    if (!file) {
        cerr << "Failed to open login_data.txt" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line); //this is for splitting the line into tokens
        string username, password;
        if (getline(iss, username, ';') && getline(iss, password, ';')) {
            userList.addUser(username, password); 
        }
    }

    string inputUsername, inputPassword;
    cout << "Username: ";
    cin >> inputUsername;
    cout << "Password: ";
    cin >> inputPassword;

    if (userList.login(inputUsername, inputPassword)) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Invalid username or password." << endl;
    }

    return 0;
}
