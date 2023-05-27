#include <iostream>
using namespace std;


struct user{
	string username;
	string password;
	string email;
	string address;
	user* NextAddress;
}*usHead;

user* createNewUserNode(string username, string password, string email, string address){
    user* newnode = new user;
    newnode -> username = username;
	newnode -> password = password;
	newnode -> email = email;
	newnode -> address = address;
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


void displayUniversities(){

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

void registerUser(string username, string password, string email, string address) {
    
}