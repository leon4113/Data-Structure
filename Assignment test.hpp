#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>
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

struct Institution{
	int Rank;
	string Name;
	string LocationCode;
	string Location;
	double ArScore;
	string ArRank;
	double ErScore;
	string ErRank;
	double FsrScore;
	string FsrRank;
	double CpfScore;
	string CpfRank;
	double IfrScore;
	string IfrRank;
	double IsrScore;
	string IsrRank;
	double IrnScore;
	string IrnRank;
	double GerScore;
	string GerRank;
	double ScoreScaled;
	Institution* PrevAddress;
	Institution* NextAddress;
}*head, *tail;

Institution* CreateNewNode(int rank, string Name, string LocationCOde, string Location, double ArScore, string ArRank, double ErScore, string ErRank,
double FsrScore, string FsrRank, double CpfScore, string CpfRank, double IfrScore, string IfrRank, double IsrScore, string IsrRank,
double IrnScore, string IrnRank, double GerScore, string GerRank, double ScoreScaled){
	Institution* newnode = new Institution;
	newnode -> Rank = rank;
	newnode -> Name = Name;
	newnode -> LocationCode = LocationCOde;
	newnode -> Location = Location;
	newnode -> ArScore = ArScore;
	newnode -> ArRank = ArRank;
	newnode -> ErScore = ErScore;
	newnode -> ErRank = ErRank;
	newnode -> FsrScore = FsrScore;
	newnode -> FsrRank = FsrRank;
	newnode -> CpfScore = CpfScore;
	newnode -> CpfRank = CpfRank;
	newnode -> IfrScore = IfrScore;
	newnode -> IfrRank = IfrRank;
	newnode -> IsrScore = IsrScore;
	newnode -> IsrRank = IsrRank;
	newnode -> IrnScore = IrnScore;
	newnode -> IrnRank = IrnRank;
	newnode -> GerScore = GerScore;
	newnode -> GerRank = GerRank;
	newnode -> ScoreScaled = ScoreScaled;
	newnode -> PrevAddress = NULL;
	newnode -> NextAddress = NULL;
	
	return newnode;
}

void InsertIntoEndofList(Institution* newnode){
	if (head == NULL)
	{
		head = tail = newnode;
	}
	else
	{
		newnode -> PrevAddress = tail;
		tail -> NextAddress = newnode;
		tail = newnode;
	}	
}

void InsertIntoStartofList(Institution* newnode){
	if (head == NULL)
	{
		head = tail = newnode;
	}
	else
	{
		newnode -> NextAddress = head;
		head -> PrevAddress = newnode;
		head = newnode;
	}	
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

void DeleteStartofList(){
	Institution* temp = head;
	if(temp -> NextAddress != NULL)
		head = head -> NextAddress;
	delete temp;
}

void DeleteEndofList(){
	Institution* temp = tail;

	if(temp-> PrevAddress != NULL)
		tail = tail -> PrevAddress;
	delete temp;
}

//Head counts as index 1
void DeleteAt(int index){
	Institution* temp = head;
	for(int i=1;i<index-1;i++){
		temp = temp -> NextAddress;
	}
	Institution* DeletedNode = temp -> NextAddress;
	temp -> NextAddress = DeletedNode -> NextAddress;
	temp = temp -> NextAddress -> NextAddress;
	temp -> PrevAddress = DeletedNode -> PrevAddress;
	
	delete DeletedNode;
}


//linear search
Institution* linearSearch( string searchValue){
	Institution * current = head;

	while(current->Name != searchValue && current->NextAddress != NULL){
		current = current-> NextAddress;
	}

	if(current->Name != searchValue){
		return NULL;
	}

	return current;
}

//bidirecional search
Institution* bidirectionalSearch(string searchValue){
	Institution* forwardPtr = head;
    Institution* backwardPtr = tail;

	while(forwardPtr != NULL && backwardPtr != NULL && 
	forwardPtr != backwardPtr && forwardPtr->PrevAddress != backwardPtr){
		// Check if forward pointer has reached the target
		if (forwardPtr->Name == searchValue) {
            return forwardPtr;
        }

        // Check if backward pointer has reached the target
        if (backwardPtr->Name == searchValue) {
            return backwardPtr;
        }

        forwardPtr = forwardPtr->NextAddress;
        backwardPtr = backwardPtr->PrevAddress;
	}

	//not found
	return NULL;
}

void customerMenu(){
	while(true){
		int option;

		cout << "1. sort universities" << endl;
		cout << "2. search universities" << endl;
		cout << "3. save favorite university " << endl;
		cout << "4. feedback" << endl;
		cout << "5. Logout" << endl << endl;

		cout << "choose a function :" << endl;
		cin >> option;
		
		if (option == 1){
            //sort()
		}
        else if (option == 2){
			string searchValue;
			cout << "enter the university name :";
			cin >> searchValue;
            bidirectionalSearch(searchValue);
		}
        else if (option == 3){
			//save university
		}
        else if (option == 4){
			//feedback
		}   
		else if(option == 5){
			break;
		}
		else{
			cout<<"please enter from the option above!";
		}
	}
}

void displayUniversities() {
    Institution* current = head;
	int count = 0;

    while (current != nullptr) {
        // Print the information of the current node
        cout<<endl;
		cout << "Rank: " << current->Rank << endl;
        cout << "Name: " << current->Name << endl;
        cout << "Location Code: " << current->LocationCode << endl;
        cout << "Location: " << current->Location << endl;
        cout << "Ar Score: " << current->ArScore << endl;
        cout << "Ar Rank: " << current->ArRank << endl;
        cout << "Er Score: " << current->ErScore << endl;
        cout << "Er Rank: " << current->ErRank << endl;
        cout << "Fsr Score: " << current->FsrScore << endl;
        cout << "Fsr Rank: " << current->FsrRank << endl;
        cout << "Cpf Score: " << current->CpfScore << endl;
        cout << "Cpf Rank: " << current->CpfRank << endl;
        cout << "Ifr Score: " << current->IfrScore << endl;
        cout << "Ifr Rank: " << current->IfrRank << endl;
        cout << "Isr Score: " << current->IsrScore << endl;
        cout << "Isr Rank: " << current->IsrRank << endl;
        cout << "Irn Score: " << current->IrnScore << endl;
        cout << "Irn Rank: " << current->IrnRank << endl;
        cout << "Ger Score: " << current->GerScore << endl;
        cout << "Ger Rank: " << current->GerRank << endl;
        cout << "Score Scaled: " << current->ScoreScaled << endl<<endl;
        
		count++;
        // Move to the next node
        current = current->NextAddress;

		if (count >= 20){
			string ans;
			cout<<"do you want to continue displaying? ";
			cout<<"input no to end, press anything to continue :";
			cin>> ans;
			if (ans == "no"){
				return;
			}
			else{
				count = 0;
			}
		}
    }
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