#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct User {
    string username;
    string password;
    string email;
    User* next;

    User(const string& uname, const string& pwd, const string& mail)
        : username(uname), password(pwd), email(mail), next(nullptr) {}
};

struct Ticket {
    string id;
    string name;
    string institution;
    string query;
    string reply;
    string resolution;
    Ticket* next;

    Ticket(const string& ticketId, const string& ticketName, const string& ticketInstitution,
        const string& ticketQuery, const string& ticketReply, const string& ticketResolution)
        : id(ticketId), name(ticketName), institution(ticketInstitution), query(ticketQuery),
        reply(ticketReply), resolution(ticketResolution), next(nullptr) {}
};

// Function to display the user data in the linked list
void displayUsers(const User* head) {
    const User* current = head;
    while (current != nullptr) {
        cout << "Username: " << current->username << endl;
        cout << "Password: " << current->password << endl;
        cout << "Email: " << current->email << endl;
        cout << endl;
        current = current->next;
    }
}

// Function to insert a new user at the end of the linked list
void insertUser(User*& head, const string& uname, const string& pwd, const string& mail) {
    User* newUser = new User(uname, pwd, mail);
    if (head == nullptr) {
        head = newUser;
    }
    else {
        User* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newUser;
    }
}

// Function to read user data from a file and create the linked list
void readUsersFromFile(User*& head, const string& filename) {
    ifstream inputFile(filename);
    if (inputFile) {
        string line;
        while (getline(inputFile, line)) {
            istringstream iss(line);
            string username, password, email;
            getline(iss, username, ',');
            getline(iss, password, ',');
            getline(iss, email, ',');
            insertUser(head, username, password, email);
        }
        inputFile.close();
    }
    else {
        cout << "Failed to open file. Creating a new file." << endl;
    }
}

void writeUsersToFile(User* head, const string& fileName) {
    ofstream file(fileName);

    if (file.is_open()) {
        User* temp = head;
        while (temp != nullptr) {
            file << temp->username << ", " << temp->password << ", " << temp->email << ", " << "\n";
            temp = temp->next;
        }
        file.close();
        cout << "Users successfully written to file!" << endl;
    }
    else {
        cout << "Error opening file: " << fileName << endl;
    }
}

// Function to save the user data to a file
void saveUsersToFile(const User* head, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile) {
        const User* current = head;
        while (current != nullptr) {
            outputFile << current->username << ", " << current->password << ", " << current->email << endl;
            current = current->next;
        }
        outputFile.close();
        cout << "User data saved to file." << endl;
    }
    else {
        cout << "Failed to open file." << endl;
    }
}

// Function to modify a user's data in the linked list based on user input
bool modifyUser(User* head, const string& uname) {
    User* current = head;
    while (current != nullptr) {
        if (current->username == uname) {
            string newPwd, newEmail;
            cout << "Enter new password: ";
            cin.ignore(); // Ignore the newline character from previous input
            getline(cin, newPwd);
            cout << "Enter new email: ";
            getline(cin, newEmail);
            current->password = newPwd;
            current->email = newEmail;
            return true; // User found and modified
        }
        current = current->next;
    }
    return false; // User not found
}

// Function to provide the option to modify a user's data
void modifyUserOption(User* head) {
    string usernameToModify;
    cout << "Enter username to modify: ";
    getline(cin, usernameToModify);
    if (modifyUser(head, usernameToModify)) {
        cout << "User '" << usernameToModify << "' modified successfully." << endl;
    }
    else {
        cout << "User '" << usernameToModify << "' not found." << endl;
    }
}

// Function to delete a user's data from the linked list and remove the corresponding line from the file
bool deleteUser(User*& head, const string& uname, const string& filename) {
    User* current = head;
    User* prev = nullptr;

    while (current != nullptr) {
        if (current->username == uname) {
            if (prev != nullptr) {
                prev->next = current->next;
            }
            else {
                head = current->next;
            }
            delete current;

            // Update the file by rewriting the remaining user data
            ofstream outputFile(filename);
            if (outputFile) {
                current = head;
                while (current != nullptr) {
                    outputFile << current->username << ", " << current->password << ", " << current->email << endl;
                    current = current->next;
                }
                outputFile.close();
                return true; // User found and deleted
            }
            else {
                cout << "Failed to open file." << endl;
            }
            break;
        }
        prev = current;
        current = current->next;
    }
    return false; // User not found
}

// Function to provide the option to delete a user's data
void deleteUserOption(User*& head, const string& filename) {
    string usernameToDelete;
    cout << "Enter username to delete: ";
    getline(cin, usernameToDelete);
    if (deleteUser(head, usernameToDelete, filename)) {
        cout << "User '" << usernameToDelete << "' deleted successfully." << endl;
    }
    else {
        cout << "User '" << usernameToDelete << "' not found." << endl;
    }
}

// Function to display ticket data
void displayTickets(const Ticket* head) {
    const Ticket* current = head;
    while (current != nullptr) {
        cout << "ID: " << current->id << endl;
        cout << "Name: " << current->name << endl;
        cout << "Institution: " << current->institution << endl;
        cout << "Query: " << current->query << endl;
        cout << "Reply: " << current->reply << endl;
        cout << "Resolution: " << current->resolution << endl;
        cout << endl;
        current = current->next;
    }
}

// Function to insert a new ticket at the end of the linked list
void insertTicket(Ticket*& head, const string& ticketId, const string& ticketName, const string& ticketInstitution,
    const string& ticketQuery, const string& ticketReply, const string& ticketResolution) {
    Ticket* newTicket = new Ticket(ticketId, ticketName, ticketInstitution, ticketQuery, ticketReply, ticketResolution);
    if (head == nullptr) {
        head = newTicket;
    }
    else {
        Ticket* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newTicket;
    }
}

// Function to read ticket data from a file and create the linked list
void readTicketsFromFile(Ticket*& head, const string& filename) {
    ifstream inputFile(filename);
    if (inputFile) {
        string line;
        getline(inputFile, line);  // Read and discard the header line

        while (getline(inputFile, line)) { 
            istringstream iss(line);
            string ticketId, ticketName, ticketInstitution, ticketQuery, ticketReply, ticketResolution;
            getline(iss, ticketId, ','); 
            getline(iss, ticketName, ',');
            getline(iss, ticketInstitution, ',');
            getline(iss, ticketQuery, ',');
            getline(iss, ticketReply, ',');
            getline(iss, ticketResolution, ',');
            insertTicket(head, ticketId, ticketName, ticketInstitution, ticketQuery, ticketReply, ticketResolution);
        }
        inputFile.close();
    }
    else {
        cout << "Failed to open file. Creating a new file." << endl;
    }
}


// Function to save the ticket data to a file
void saveTicketsToFile(const Ticket* head, const string& filename) {
    ofstream outputFile(filename);
    if (outputFile) {
        const Ticket* current = head;
        while (current != nullptr) {
            outputFile << current->id << ", " << current->name << ", " << current->institution << ", "
                << current->query << ", " << current->reply << ", " << current->resolution << endl;
            current = current->next;
        }
        outputFile.close();
        cout << "Ticket data saved to file." << endl;
    }
    else {
        cout << "Failed to open file." << endl;
    }
}

// Function to reply to a user's feedback
bool replyToTicket(Ticket* head, const string& ticketId, const string& reply) {
    Ticket* current = head;
    while (current != nullptr) {
        if (current->id == ticketId) {
            current->reply = reply;
            return true; // Ticket found and replied
        }
        current = current->next;
    }
    return false; // Ticket not found
}

// Function to provide the option to reply to a user's feedback
void replyToTicketOption(Ticket* head) {
    string ticketId, reply;
    cout << "Enter ticket ID to reply: ";
    getline(cin, ticketId);
    cout << "Enter reply: ";
    getline(cin, reply);
    if (replyToTicket(head, ticketId, reply)) {
        cout << "Reply added to ticket '" << ticketId << "' successfully." << endl;
    }
    else {
        cout << "Ticket '" << ticketId << "' not found." << endl;
    }
}

#include <iostream>
#include <fstream>
#include <algorithm> 
using namespace std;

// Structure to store university data
struct University {
    string name;
    int students;

    University() {}
    University(const string& n, int s) : name(n), students(s) {}
};

// Function to compare universities based on the number of students
bool compareUniversities(const University& u1, const University& u2) {
    return u1.students > u2.students; // Sort in descending order
}

// Function to perform quicksort
void quicksort(University* arr, int left, int right) {
    if (left >= right) {
        return;
    }
    
    int pivot = arr[(left + right) / 2].students;
    int i = left;
    int j = right;
    
    while (i <= j) {
        while (arr[i].students > pivot) {
            i++;
        }
        
        while (arr[j].students < pivot) {
            j--;
        }
        
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    
    quicksort(arr, left, j);
    quicksort(arr, i, right);
}

void summarize() {
    ifstream inputFile("favorites_uni.txt");
    if (!inputFile) {
        cout << "Failed to open file." << endl;
        return;
    }

    const int size = 1400;
    University universities[size];
    int index = 0;
    string line;
    while (getline(inputFile, line) && index < size) {
        // Assuming the format of each line is: university_name, number_of_students
        size_t commaPos = line.find(',');
        string name = line.substr(0, commaPos);
        int students = stoi(line.substr(commaPos + 1));

        universities[index] = University(name, students);
        index++;
    }

    inputFile.close();

    // Sort the universities based on the number of students using quicksort
    quicksort(universities, 0, index - 1);

    // Print the sorted universities
    cout << "Top 10 Universities:" << endl;
    int count = 0;
    for (int i = 0; i < index; i++) {
        cout << universities[i].name << ": " << universities[i].students << " students' favorites" << endl;
        count++;
        if (count >= 10) break;
    }
}


void Admin_menu() {
    User* head = nullptr;
    Ticket* ticketHead = nullptr;
    string userFileName = "users.txt";
    string ticketFileName = "Tickets.txt";
    readUsersFromFile(head, userFileName);
    readTicketsFromFile(ticketHead, ticketFileName);

    int choice;
    string userInput;
    string username, password, email;

    do {
        cout << "1. Display Users" << endl;
        cout << "2. Modify User's Details" << endl;
        cout << "3. Delete user's Accounts" << endl;
        cout << "4. Reply User's Feedback" << endl;
        cout << "5. Summarize top 10 most favorites university" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character from previous input

        switch (choice) {
        case 1:
            displayUsers(head);
            break; 

        case 2:
            modifyUserOption(head);
            saveUsersToFile(head, "users.txt");
            break;

        case 3:
            deleteUserOption(head, "users.txt");
            break;

        case 4:
            displayTickets(ticketHead);
            replyToTicketOption(ticketHead);
            saveTicketsToFile(ticketHead, "tickets.txt");
            break;
        case 5:
            summarize();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    } while (choice != 6);
    // Cleanup: free memory
    User* current = head;
    while (current != nullptr) {
        User* temp = current;
        current = current->next;
        delete temp;
    }
}