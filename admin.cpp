#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct UserNode {
    string username;
    string password;
    string email;
    UserNode* next;
};

class UserList {
private:
    UserNode* head;
public:
    UserList() {
        head = nullptr;
    }

    // Function to add a user to the linked list
    void AddUser(const string& username, const string& password, const string& email) {
        UserNode* newNode = new UserNode;
        newNode->username = username;
        newNode->password = password;
        newNode->email = email;
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
                cout << endl;
                temp = temp->next;
            }
        }
    }

    // Function to delete inactive accounts based on inactivity threshold
    void DeleteInactiveAccounts(int inactiveThreshold) {
        UserNode* temp = head;
        UserNode* prev = nullptr;

        while (temp != nullptr) {
            // Implement your logic to determine inactivity status based on your criteria
            // For this example, we assume that an account is inactive if the username is empty
            if (temp->username.empty()) {
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
            string username, password, email;
            if (getline(ss, username, ',') && getline(ss, password, ',') && getline(ss, email)) {
                userList.AddUser(username, password, email);
            }
        }
        file.close();
        cout << "Users successfully loaded from file!" << endl;
    } else {
        cout << "Error opening file: " << fileName << endl;
    }
}


int main() {
    UserList userList;

    string filename = "users.txt";
    int inactiveThreshold = 90;

    ReadUsersFromFile(userList, "users.txt");
    userList.DisplayUsers();

    // Perform deletion of inactive accounts based on the specified inactivity threshold
    userList.DeleteInactiveAccounts(inactiveThreshold);

    cout << "Inactive accounts deleted." << endl;

    // Display the updated list of users after deletion
    userList.DisplayUsers();

    return 0;
}
