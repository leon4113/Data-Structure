#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

struct UserNode {
    string username;
    string password;
    string email;
    time_point<system_clock> lastLoginDate; // Last login time
    UserNode* next;
};

class UserList {
public:
    UserNode* head;

    UserList() {
        head = nullptr;
    }

    // Function to add a user to the linked list
    void AddUser(const string& username, const string& password, const string& email, const time_point<system_clock>& lastLoginDate) {
        UserNode* newNode = new UserNode;
        newNode->username = username;
        newNode->password = password;
        newNode->email = email;
        newNode->lastLoginDate = lastLoginDate;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        }
        else {
            UserNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to display all users in the linked list
    void DisplayUsers() {
        if (head == nullptr) {
            cout << "No users found in the list." << endl;
        }
        else {
            UserNode* temp = head;
            while (temp != nullptr) {
                cout << "Username: " << temp->username << endl;
                cout << "Password: " << temp->password << endl;
                cout << "Email: " << temp->email << endl;
                //cout << "Last Login Date: " << system_clock::to_time_t(temp->lastLoginDate) << endl;
                cout << endl;
                temp = temp->next;
            }
        }
    }

    // Function to delete inactive accounts based on inactivity threshold
    void DeleteInactiveAccounts(int inactiveThreshold) {
        UserNode* temp = head;
        UserNode* prev = nullptr;
        time_point<system_clock> currentTime = system_clock::now();

        while (temp != nullptr) {
            // Calculate the duration between the current time and the last login date
            auto duration = duration_cast<seconds>(currentTime - temp->lastLoginDate); 

            // Check if the duration is greater than the specified inactivity threshold (30 days)
            if (duration.count() > inactiveThreshold) {
                // Delete the inactive account
                if (prev == nullptr) {
                    // The inactive account is the head of the linked list
                    head = temp->next;
                    delete temp;
                    temp = head;
                }
                else {
                    // The inactive account is not the head
                    prev->next = temp->next;
                    delete temp;
                    temp = prev->next;
                }
            }
            else {
                // Move to the next node
                prev = temp;
                temp = temp->next;
            }
        }
    }
};

void ReadUsersFromFile(UserList& userList, const string& fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string username, password, email, lastLoginDateStr;
            if (getline(ss, username, ',') && getline(ss, password, ',') && getline(ss, email, ',') && getline(ss, lastLoginDateStr)) {
                time_t lastLoginTime = stoi(lastLoginDateStr);
                time_point<system_clock> lastLoginDate = system_clock::from_time_t(lastLoginTime);
                userList.AddUser(username, password, email, lastLoginDate);
            }
        }
        file.close();
        cout << "Users successfully loaded from file!" << endl;
    }
    else {
        cout << "Error opening file: " << fileName << endl;
    }
}

void WriteUsersToFile(UserList& userList, const string& fileName) {
    ofstream file(fileName, ios::app);

    if (file.is_open()) {
        UserNode* temp = userList.head;
        while (temp != nullptr) {
            file << temp->username << ", " << temp->password << ", " << temp->email << ", " << system_clock::to_time_t(temp->lastLoginDate) << "\n";
            temp = temp->next;
        }
        file.close();
        cout << "Users successfully written to file!" << endl;
    } else {
        cout << "Error opening file: " << fileName << endl;
    }
}

void Menu(UserList& userList, const string& fileName) {
    int choice;
    string username, password, email;
    time_point<system_clock> lastLoginDate;

    do {
        cout << "1. Display Users" << endl;
        cout << "2. Add User" << endl;
        cout << "3. Delete Inactive Accounts" << endl;
        cout << "4. Write Users to File" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            userList.DisplayUsers();
            break;
        case 2:
            cout << "Enter username: ";
            cin.ignore(); // Ignore the newline character in the input stream
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);
            cout << "Enter email: ";
            getline(cin, email);
            // Set the last login date to the current time
            lastLoginDate = system_clock::now();
            userList.AddUser(username, password, email, lastLoginDate);
            cout << "User added successfully!" << endl;
            break;
        case 3:
            int inactiveThreshold;
            cout << "Enter the inactivity threshold (in days): ";
            cin >> inactiveThreshold;
            userList.DeleteInactiveAccounts(inactiveThreshold);
            cout << "Inactive accounts deleted." << endl;
            break;
        case 4:
            WriteUsersToFile(userList, fileName);
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    } while (choice != 5);
}

int main() {
    UserList userList;

    string filename = "users.txt";
    int inactiveThreshold = 2592000;

    ReadUsersFromFile(userList, "users.txt");

    Menu(userList, filename);

    return 0;
}
