#include <iostream>
using namespace std;
#include "Assignment test.hpp"

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
        cerr << "Failed to open login_data.txt" << endl;
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
        else if (option == 2);
            //sort()
        else if (option == 3){
			string searchValue;
			cout << "Enter the university name: ";
			cin.ignore();
			getline (cin, searchValue);
						
			Institution* result = bidirectionalSearch(searchValue);

			if (result == NULL) {
				cout << "University not found." << endl;
			} 
			else {
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

			if (login(username, password)){
				customerMenu();
			}
			else{
				cout<<"wrong username / password";
			}
		}
		else{
			cout<<"please enter from the option above!" <<endl <<endl;
		}
	}
}