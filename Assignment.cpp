#include <iostream>
using namespace std;
#include "Assignment.hpp"


Ticket ticket;
Favorite universities[1400];

void AddFavourite(string uniname){
	int index=0;
	while(index<1400){
		if(universities[index].name == uniname){
			universities[index].students++;
			cout << "Successfully added to favorites!\n\n";
			return;
		}
		index++;	
	}
	cout << "University name not found\n\n";
	return;
}


void FavoriteMenu(){
	int choice = 0;
	while(choice!=2){
		cout << "1. Select a uni to mark as favorite\n";
		cout << "2. Go back\n\n";
		cout << "Input choice here:";
		cin >> choice;
		cout << endl;
		string uniname;
		switch(choice){
			case 1:
				cout << "Input the name of the university to mark as favorite: ";
				cin.ignore();
				getline(cin, uniname);
				AddFavourite(uniname);
				break;
			case 2:
				break;
			default:
				cout << "Invalid Input!";
				break;
		}
	}
	cout << endl;
}

void customerMenu(string username){
	while(true){
		int option;
		cout<<"Customer Menu" <<endl;
		cout << "1. sort universities" << endl;
		cout << "2. search universities" << endl;
		cout << "3. save favorite university " << endl;
		cout << "4. feedback" << endl;
		cout << "5. Logout" << endl << endl;

		cout << "choose a function :" << endl;
		cin >> option;
		
		if (option == 1){
            int choice;
			cout << "1. Sort by Academic Reputation Score" << endl;
			cout << "2. Sort by Faculty/Student Ratio" << endl;
			cout << "3. Sort by Employer Reputation Score" << endl;
			cout << "Enter the sorting criterion: " << endl;
			cin >> choice;
			
			// Sort the linked list based on the user's choice
			switch (choice) {
				case 1:
					mergeSortByArScore(&head);
					break;
				case 2:
					mergeSortByFsrScore(&head);
					break;
				case 3:
					mergeSortByErScore(&head);
					break;
				default:
					cout << "Invalid choice. Sorting by Academic Reputation Score." << endl;
					mergeSortByArScore(&head);
					break;
			}
			// Print the sorted linked list
			cout << "Sorted Linked List: " << endl;
			printList(head);
		}
        else if (option == 2){
			string searchValue;
			cout << "enter the university name :";
			cin >> searchValue;
            partialSearch(searchValue);
		}
        else if (option == 3){
			FavoriteMenu();
		}
        else if (option == 4){
			CusFeedback(username, ticket);

		}   
		else if(option == 5){
			break;
		}
		else{
			cout<<"please enter from the option above!";
		}
	}
}

void Admin_menu() {
    int choice;
    string userInput;
    string username, password, email;

    do {
        cout<<"Admin Menu" <<endl;
		cout << "1. Display Users" << endl;
        cout << "2. Modify User's Details" << endl;
        cout << "3. Delete user's Accounts" << endl;
        cout << "4. view Feedback" << endl;
        cout << "5. Summarize top 10 most favorites university" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character from previous input

        switch (choice) {
        case 1:
            DisplayUsers();
            break; 

        case 2:
            modifyUserOption(usHead);
            break;

        case 3:
            deleteUserOption(usHead);
            break;

        case 4:
            AdmFeedback(ticket);
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
    user* current = usHead;
    while (current != nullptr) {
        user* temp = current;
        current = current->NextAddress;
        delete temp;
    }
}



void login(const string& username, const string& password) {
    if(username == "admin" && password == "admin"){
        Admin_menu();
		    
	}
	else{
		user* current = usHead;
		while (current != nullptr) {
			if (username == current->username && password == current->password) {
				customerMenu(username);
			}
			current = current->NextAddress;
		}
		cout << "Incorrect username or password"<<endl;
	}
    
}


void WriteFavoritesToFile(){
    ofstream file("Favorite_uni.txt");

    if(file.is_open()){
        for(int i=0;i<1400;i++){
            file << universities[i].name << "," << universities[i].students << "\n";
        }
    }
    else{
        cout << "Error opening file" << endl;
    }
}

int main(){
	string line, word;
 
 	string dump;
	string Rankstr;
	int Rank;
	string ArScorestr, ErScorestr, FsrScorestr, CpfScorestr, IfrScorestr, IsrScorestr, IrnScorestr, GerScorestr, ScoreScaledstr;
	double ArScore, ErScore, FsrScore, CpfScore, IfrScore, IsrScore, IrnScore, GerScore, ScoreScaled;
	string Name, Location, LocationCode, ArRank, ErRank, FsrRank, CpfRank, IfrRank, IsrRank, IrnRank, GerRank;
 
	ifstream file ("Institution.csv");
	bool header = true;
	while(file.good()){
		if(header){
			getline(file, dump, '\n');
		}
		else{
			getline(file, Rankstr, ',');
			getline(file, Name, ',');
			getline(file, LocationCode, ',');
			getline(file, Location, ',');
			getline(file, ArScorestr, ',');
			getline(file, ArRank, ',');
			getline(file, ErScorestr, ',');
			getline(file, ErRank, ',');
			getline(file, FsrScorestr, ',');
			getline(file, FsrRank, ',');	
			getline(file, CpfScorestr, ',');
			getline(file, CpfRank, ',');
			getline(file, IfrScorestr, ',');
			getline(file, IfrRank, ',');
			getline(file, IsrScorestr, ',');
			getline(file, IsrRank, ',');
			getline(file, IrnScorestr, ',');
			getline(file, IrnRank, ',');
			getline(file, GerScorestr, ',');
			getline(file, GerRank, ',');
			getline(file, ScoreScaledstr, '\n');
			
			//Debugging stuff
			//cout << Rankstr << " " << Name << " " << LocationCode << endl;
			//cout << "Type of Rankstr = " << typeid(Rank).name() << endl;

            //Stop At end of csv file
            if(Rankstr=="")
                break;

			//Converting datatypes
			Rank = stoi(Rankstr);
			ArScore = stod(ArScorestr);
			ErScore = stod(ErScorestr);
			FsrScore = stod(FsrScorestr);
			CpfScore = stod(CpfScorestr);
			IfrScore = stod(IfrScorestr);
			IsrScore = stod(IsrScorestr);
			IrnScore = stod(IrnScorestr);
			GerScore = stod(GerScorestr);
			ScoreScaled = stod(ScoreScaledstr);
			
			Institution* temp = CreateNewNode(Rank, Name, LocationCode, Location, ArScore, ArRank, ErScore, ErRank, FsrScore, FsrRank, CpfScore, CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled);
			InsertIntoEndofList(temp);
		}
        header = false;				
	}
    file.close();

	file.open("users.txt");
    if (!file) {
        cerr << "Failed to open users.txt" << endl;
        return 1;
    }

	string username, password, email;


	while(file.good()){
		getline(file, username, ',');
		getline(file, password, ',');
		getline(file, email, '\n');
			
        if(username== "")
            break;
		user* temp = createNewUserNode(username, password, email);
		InsertIntoStartofUserList(temp);		
	}
    file.close();

	ticket.ReadFromFile();
	
	ifstream inputFile("Favorite_uni.txt");
    if (!inputFile) {
        cout << "Failed to open file." << endl;
        return 1;
    }

    header=true;
    int index=0;
    while(file.good()){
        string dump;
        string uniname,studentstr;
        int students;
        if(header){
            getline(file, dump, '\n');
        }
        else{
            getline(file, uniname, ',');
            getline(file, studentstr, '\n');

            if(uniname=="")
                break;

            students = stoi(studentstr);
            universities[index] = Favorite(uniname, students);
        }
        header=false;
    }
    inputFile.close();

	while(true){
		int option;

		cout<<"Normal user Menu" <<endl;
		cout << "1. Display universities" << endl;
		cout << "2. sort universities" << endl;
		cout << "3. search university details" << endl;
		cout << "4. Resgister as customer" << endl;
		cout << "5. Login" << endl;
		cout << "6. exit" << endl << endl;

		cout << "choose a function :" << endl;
		cin >> option;

		if (option == 1){
			displayUniversities();
		}
        else if (option == 2){
            int input;
			cout << "1. merge sort" << endl;
			cout << "2. Quick sort" << endl;
			cout << "choose a function :" << endl;
			cin >> input;
			if(input == 1)
				mergeSortUniversities();
			else if(input == 2)
				quicksortUniversities();
			else
				cout << "please enter from the option above!" << endl << endl;
		}
        else if (option == 3){
			string searchValue;
			cout << "Enter the university name: ";
			cin.ignore();
			getline (cin, searchValue);
						
			Institution* result = bidirectionalSearch(searchValue);
			Institution* result2 = linearSearch(searchValue);

			if (result == NULL) {
				cout << "University not found." << endl;
			} 
			else {
				cout<<"\n";
				cout << "Rank: " << result->Rank << endl;
				cout << "Name: " << result->Name << endl;
				cout << "Location Code: " << result->LocationCode << endl;
				cout << "Location: " << result->Location << endl;
				cout << "Ar Score: " << result->ArScore << endl;
				cout << "Ar Rank: " << result->ArRank << endl;
				cout << "Er Score: " << result->ErScore << endl;
				cout << "Er Rank: " << result->ErRank << endl;
				cout << "Fsr Score: " << result->FsrScore << endl;
				cout << "Fsr Rank: " << result->FsrRank << endl;
				cout << "Cpf Score: " << result->CpfScore << endl;
				cout << "Cpf Rank: " << result->CpfRank << endl;
				cout << "Ifr Score: " << result->IfrScore << endl;
				cout << "Ifr Rank: " << result->IfrRank << endl;
				cout << "Isr Score: " << result->IsrScore << endl;
				cout << "Isr Rank: " << result->IsrRank << endl;
				cout << "Irn Score: " << result->IrnScore << endl;
				cout << "Irn Rank: " << result->IrnRank << endl;
				cout << "Ger Score: " << result->GerScore << endl;
				cout << "Ger Rank: " << result->GerRank << endl;
				cout << "Score Scaled: " << result->ScoreScaled << endl<<endl;
			}
		}
        else if (option == 4){
			string username;
			string password;
			string email;

			cout << "Username :" << endl;
			cin >> username;

			cout << "Password :" << endl;
			cin >> password;
			
			cout << "email :" << endl;
			cin >> email;

			user* usernode = createNewUserNode(username, password, email);
			InsertIntoStartofUserList (usernode);
		}   
		else if(option == 5){
			string username;
			string password;
			string email;

			cout << "Username :" << endl;
			cin >> username;

			cout << "Password :" << endl;
			cin >> password;

			login(username, password);
		}
		else if(option == 6){
			writeUsersToFile(usHead, "users.txt");
			ticket.WriteToFile();
			WriteFavoritesToFile();
			break;
		}
		else{
			cout<<"please enter from the option above!" <<endl <<endl;
		}
	}
}