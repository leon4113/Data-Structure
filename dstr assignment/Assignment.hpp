#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;



struct TicketNode {
	string ID;
	string Author;
	string Institution;
	string Query;
	string Reply;
	bool Resolved;
	TicketNode* next;
};

class Ticket {
private:
	TicketNode* head;
public:
	Ticket(){
		head = NULL;
	}	
	
	//Ticket edit functions
	void CreateNewTicket(string Author, string Institution, string Query){
		TicketNode* newNode = new TicketNode;
		newNode->Author = Author;
		newNode->Institution = Institution;
		newNode->Query = Query;
		newNode->Reply = "";
		newNode->Resolved = false;
		newNode->next = NULL;
		
		if(head == NULL){
			newNode->ID = "T1";
			head = newNode;
		}
		else{
			int count=2;
			TicketNode* temp = head;
			while(temp->next != NULL){
				temp = temp->next;
				count++;
			}
			stringstream ss;
			ss << "T" << count;
			newNode->ID = ss.str();
			temp->next = newNode;
		}
		
		cout << "Ticket successfully added!" << endl;
	}
	void AddReply(string ID, string Reply){
		TicketNode* temp = head;
		while(temp->ID!=ID){
			temp = temp->next;
		}
		temp->Reply = Reply;
		cout << "Reply successfully added!\n";
	}
	void MarkAsResolved(string ID){
		TicketNode* temp = head;
		while(temp->ID!=ID){
			temp = temp->next;
		}
		temp->Resolved = true;
		cout << "Ticket marked as resolved!\n";
	}
	void AdmEdit(string ID){
		int choice=0;
		while(choice!=3){
			cout << "\nWhat would you like to do with this ticket?" << endl;
			cout << "1. Add a reply" << endl;
			cout << "2. Mark as resolved" << endl;
			cout << "3. Go Back\n\n";
			cout << "Input here: ";
			cin >> choice;
			string Reply;
			switch (choice) {
		        case 1:
		        	cout << "Input a reply: ";
		        	cin.ignore();
		        	getline(cin, Reply);
		        	AddReply(ID, Reply);
		            break;
		        case 2:
		        	MarkAsResolved(ID);
		            break;
		        case 3:	
		            break;
		        default:
					cout << "Invalid Input!\n" << endl;
		            break;
		    }
		}
		cout << endl;
	}
	void CusEdit(string ID){
		int choice=0;
		while(choice!=2){
			cout << "\nWhat would you like to do with this ticket?" << endl;
			cout << "1. Mark as resolved" << endl;
			cout << "2. Go Back\n\n";
			cout << "Input here: ";
			cin >> choice;
			switch (choice) {
		        case 1:
		        	MarkAsResolved(ID);
		            break;
		        case 2:
		            break;
		        default:
					cout << "Invalid Input!\n" << endl;
		            break;
		    }
		}
		cout << endl;
	}
	
	//Ticket display functions
	void DisplayAll(){
		if(head == NULL){
			cout << "No tickets are present!" << endl;
		}
		else{
			TicketNode* temp = head;
			while(temp != NULL){
				string status;
				if(temp->Resolved)
					status = "Resolved";
				else
					status  = "Unresolved";
				cout << "ID: " << temp->ID << "\nCreated by: " << temp->Author << "\nFor: " << temp->Institution << endl;
				cout << "Query: " << temp->Query << "\nReply: " <<  temp->Reply << "\nStatus: " << status << "\n";
				if(temp->next != NULL)
					cout << endl;
				temp = temp->next;
			}
		}
	}
	void DisplayAll(string Name){
		if(head == NULL){
			cout << "No tickets are present!" << endl;
		}
		else{
			TicketNode* temp = head;
			while(temp != NULL){
				string status;
				if(temp->Resolved)
					status = "Resolved";
				else
					status  = "Unresolved";
				if(temp->Author == Name){
					cout << "ID: " << temp->ID << "\nCreated by: " << temp->Author << "\nFor: " << temp->Institution << endl;
					cout << "Query: " << temp->Query << "\nReply: " <<  temp->Reply << "\nStatus: " << status << "\n";
				}
				if(temp->next != NULL)
					cout << endl;
				temp = temp->next;
			}
		}
	}
	void DisplayUnresolved(){
		if(head == NULL){
			cout << "No tickets are present!" << endl;
		}
		else{
			TicketNode* temp = head;
			while(temp != NULL){
				if(!temp->Resolved){
					cout << "ID: " << temp->ID << "\nCreated by: " << temp->Author << "\nFor: " << temp->Institution << endl;
					cout << "Query: " << temp->Query << "\nReply: " <<  temp->Reply << "\nStatus: Unresolved\n";
				}
				if(temp->next != NULL)
					cout << endl;
				temp = temp->next;
			}
		}
	}
	void DisplayUnresolved(string Name){
		if(head == NULL){
			cout << "No tickets are present!" << endl;
		}
		else{
			TicketNode* temp = head;
			while(temp != NULL){
				if(!temp->Resolved && temp->Author == Name){
					cout << "ID: " << temp->ID << "\nCreated by: " << temp->Author << "\nFor: " << temp->Institution << endl;
					cout << "Query: " << temp->Query << "\nReply: " <<  temp->Reply << "\nStatus: Unresolved\n";
				}
				if(temp->next != NULL)
					cout << endl;
				temp = temp->next;
			}
		}
	}
	bool DisplayTicket(string ID){
		TicketNode* temp = head;
		bool found=false;
		while(temp!=NULL){
			if(temp->ID == ID){
				string status;
				if(temp->Resolved)
					status = "Resolved";
				else
					status  = "Unresolved";
				cout << "ID: " << temp->ID << "\nCreated by: " << temp->Author << "\nFor: " << temp->Institution << endl;
				cout << "Query: " << temp->Query << "\nReply: " <<  temp->Reply << "\nStatus: " << status << "";
				found=true;
				break;
			}
			temp = temp->next;
		}
		if(!found)
			cout << "Ticket does not exist\n";
		return found;	
	}
};

void AdmFeedback(Ticket ticket){
	cout << "Admin Feedback Menu\n" << endl;
	int choice = 0;
	while (choice!=4){
		cout << "What would you like to do?" << endl;
		cout << "1. Select a ticket" << endl;
		cout << "2. Show all tickets" << endl;
		cout << "3. Show unresolved tickets" << endl;
		cout << "4. Go back\n" << endl;
		cout << "Input here: ";
		cin >> choice;
		cout << endl;
		string ID;
		switch(choice){
			case 1:				
				bool exists;
				cout << "Select a ticket: ";
				cin >> ID;
				exists = ticket.DisplayTicket(ID);
				if(exists){
					cout << endl;
					ticket.AdmEdit(ID);
				}
				break;
			case 2:
				ticket.DisplayAll();
				break;
			case 3:
				ticket.DisplayUnresolved();
				break;
			case 4:
				break;
			default:
				cout << "Invalid input!\n\n";
				break; 
		}
		cout << endl;
	}
}

void CusFeedback(string Name, Ticket ticket){
	cout << "Customer Feedback Menu\n" << endl;
	int choice = 0;
	while (choice!=5){
		cout << "What would you like to do?" << endl;
		cout << "1. Select a ticket" << endl;
		cout << "2. Show all tickets" << endl;
		cout << "3. Show unresolved tickets" << endl;
		cout << "4. Make new ticket" << endl;
		cout << "5. Go back\n" << endl;
		cout << "Input here: ";
		cin >> choice;
		cout << endl;
		string ID;
		if (choice == 1) {
		    bool exists;
		    cout << "Select a ticket: ";
		    cin >> ID;
		    exists = ticket.DisplayTicket(ID);
		    if (exists) {
		        cout << endl;
		        ticket.CusEdit(ID);
		    }
		}
		else if (choice == 2) {
		    ticket.DisplayAll(Name);
		}
		else if (choice == 3) {
		    ticket.DisplayUnresolved(Name);
		}
		else if (choice == 4) {
		    string Institution, Query;
		    cout << "Insert institution name: ";
		    cin.ignore();
		    getline(cin, Institution);
		    cout << "Insert your query: ";
		    getline(cin, Query);
		    ticket.CreateNewTicket(Name, Institution, Query);
		}
		else if (choice == 5) {
		    // Do nothing
		}
		else {
		    cout << "Invalid input!\n\n";
		}
		cout << endl;
	}
}


struct user{
	string username;
	string password;
	string email;
	user* NextAddress;

	user(){};
};

class UserList {
public:
    user* usHead;
    UserList() {usHead = nullptr;}

    ~UserList() {
        user* current = usHead;
        while (current != nullptr) {
            user* temp = current;
            current = current->NextAddress;
            delete temp;
        }
    }

    user* createNewUserNode(string username, string password, string email){
		user* newnode = new user;
		newnode -> username = username;
		newnode -> password = password;
		newnode -> email = email;
		newnode-> NextAddress = NULL;
		return newnode;
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

    // Function to display all users in the linked list
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
	cout<<"succesfully registered"<<endl;

	}
};




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

void partialSearch( string searchValue){
	Institution * current = head;
	
	while(current->NextAddress != NULL){
		if(current->Name.find(searchValue) != string::npos){
			cout<<endl;
			cout << "Rank: " << current->Rank << endl;
			cout << "Name: " << current->Name << endl;
			cout << "LocationCode: " << current->LocationCode << endl;
			cout << "Location: " << current->Location << endl;
			cout << "ArScore: " << current->ArScore << endl;
			cout << "ArScore: " << current->ArScore << endl;
			cout << "ErScore: " << current->ErScore << endl;
			cout << "ErRank: " << current->ErRank << endl;
			cout << "FsrScore: " << current->FsrScore << endl;
			cout << "FsrRank: " << current->FsrRank << endl;
			cout << "CpfScore: " << current->CpfScore << endl;
			cout << "CpfRank: " << current->CpfRank << endl;
			cout << "IfrScore: " << current->IfrScore << endl;
			cout << "IfrRank: " << current->IfrRank << endl;
			cout << "IsrScore: " << current->IsrScore << endl;
			cout << "IsrRank: " << current->IsrRank << endl;
			cout << "IrnScore: " << current->IrnScore << endl;
			cout << "IrnRank: " << current->IrnRank << endl;
			cout << "GerScore: " << current->GerScore << endl;
			cout << "GerRank: " << current->GerRank << endl;
			cout << "ScoreScaled: " << current->ScoreScaled << endl;
		}
		current = current-> NextAddress;
	}
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


