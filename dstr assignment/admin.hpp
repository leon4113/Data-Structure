#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>
using namespace std;

void admminMenu(UserList& userList, const string& fileName) {
    int choice;
    string username, password, email;
    time_point<system_clock> lastLoginDate;

    do {
        cout << "1. Display Users" << endl;
        cout << "2. Modify User's Details" << endl;
        cout << "3. Delete Inactive Accounts" << endl;
        cout << "4. Reply User's Feedback" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            userList.DisplayUsers();
            break;
        case 2:
            //modifyuser();
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