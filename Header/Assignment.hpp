#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>
using namespace std;
using namespace std::chrono;


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
            cout << endl;
            temp = temp->NextAddress;
        }
    }
}


void writeUsersToFile(user* usHead, const string& fileName) {
    ofstream file(fileName);

    if (file.is_open()) {
        user* temp = usHead;
        while (temp != nullptr) {
            file << temp->username << ", " << temp->password << ", " << temp->email << ", " << "\n";
            temp = temp->NextAddress;
        }
        file.close();
        cout << "Users successfully written to file!" << endl;
    }
    else {
        cout << "Error opening file: " << fileName << endl;
    }
}

bool modifyUser(user* usHead, const string& uname) {
    user* current = usHead;
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
        current = current->NextAddress;
    }
    return false; // User not found
}

// Function to provide the option to modify a user's data
void modifyUserOption(user* usHead) {
    string usernameToModify;
    cout << "Enter username to modify: ";
    getline(cin, usernameToModify);
    if (modifyUser(usHead, usernameToModify)) {
        cout << "User '" << usernameToModify << "' modified successfully." << endl;
    }
    else {
        cout << "User '" << usernameToModify << "' not found." << endl;
    }
}

// Function to delete a user's data from the linked list and remove the corresponding line from the file
bool deleteUser(user*& head, const string& uname) {
    user* current = head;
    user* prev = nullptr;

    while (current != nullptr) {
        if (current->username == uname) {
            if (prev != nullptr) {
                prev->NextAddress = current->NextAddress;
            }
            else {
                head = current->NextAddress;
            }
            delete current;
        }
        prev = current;
        current = current->NextAddress;
    }
    return false; // User not found
}

// Function to provide the option to delete a user's data
void deleteUserOption(user*& head) {
    string usernameToDelete;
    cout << "Enter username to delete: ";
    getline(cin, usernameToDelete);
    if (deleteUser(head, usernameToDelete)) {
        cout << "User '" << usernameToDelete << "' deleted successfully." << endl;
    }
    else {
        cout << "User '" << usernameToDelete << "' not found." << endl;
    }
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

	auto start = high_resolution_clock::now();
	while(current->Name != searchValue && current->NextAddress != NULL){
	current = current-> NextAddress;
	}

	if(current->Name != searchValue){
	return NULL;
	}

	auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by linear search: "<< duration.count() << " microseconds" << endl;
	return current;
}


//bidirecional search
Institution* bidirectionalSearch(string searchValue){
	Institution* forwardPtr = head;
    Institution* backwardPtr = tail;
	
	auto start = high_resolution_clock::now();
	while(forwardPtr != NULL && backwardPtr != NULL && 
	forwardPtr != backwardPtr && forwardPtr->PrevAddress != backwardPtr){
		// Check if forward pointer has reached the target
		if (forwardPtr->Name == searchValue) {

            auto stop = high_resolution_clock::now();
    		auto duration = duration_cast<microseconds>(stop - start);
			cout << "Time taken by bidirectional search: "<< duration.count() << " microseconds" << endl;
			return forwardPtr;
        }

        // Check if backward pointer has reached the target
        if (backwardPtr->Name == searchValue) {
            auto stop = high_resolution_clock::now();
    		auto duration = duration_cast<microseconds>(stop - start);
			cout << "Time taken by bidirectional search: "<< duration.count() << " microseconds" << endl;
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
			cout << "ScoreScaled: " << current->ScoreScaled << endl<<endl;
		}
		current = current-> NextAddress;
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

Institution* partition(Institution* head, Institution* tail) {
    string pivot = tail->Name;
    Institution* i = head->PrevAddress;

    for (Institution* j = head; j != tail; j = j->NextAddress) {
        if (j->Name <= pivot) {
            i = (i == nullptr) ? head : i->NextAddress;
            swap(i->Name, j->Name);
        }
    }

    i = (i == nullptr) ? head : i->NextAddress;
    swap(i->Name, tail->Name);
    return i;
}

void quicksort(Institution* head, Institution* tail) {
    if (tail != nullptr && head != tail && head != tail->NextAddress) {
        Institution* pivot = partition(head, tail);

        quicksort(head, pivot->PrevAddress);
        quicksort(pivot->NextAddress, tail);
    }
}

void quicksortUniversities() {
    // Count the number of institutions
    int count = 0;
    Institution* current = head;
    while (current != nullptr) {
        count++;
        current = current->NextAddress;
    }

    // Start timer
    auto start = high_resolution_clock::now();
    // Sort the linked list using QuickSort algorithm
    quicksort(head, tail);
    // Stop timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by QuickSort: " << duration.count() << " microseconds" << endl;

    // Reassign the head and tail pointers after sorting
    current = head;
    while (current->NextAddress != nullptr) {
        current->NextAddress->PrevAddress = current;
        current = current->NextAddress;
    }
    tail = current;
}


Institution* merge(Institution* head1, Institution* head2) {
    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }

    Institution* result;
    if (head1->Name <= head2->Name) {
        result = head1;
        result->NextAddress = merge(head1->NextAddress, head2);
        result->NextAddress->PrevAddress = result;
    } else {
        result = head2;
        result->NextAddress = merge(head1, head2->NextAddress);
        result->NextAddress->PrevAddress = result;
    }

    return result;
}

void splitList(Institution* head, Institution** front, Institution** back) {
    Institution* slow = head;
    Institution* fast = head->NextAddress;

    while (fast != nullptr) {
        fast = fast->NextAddress;
        if (fast != nullptr) {
            slow = slow->NextAddress;
            fast = fast->NextAddress;
        }
    }

    *front = head;
    *back = slow->NextAddress;
    slow->NextAddress = nullptr;
    if (*back != nullptr) {
        (*back)->PrevAddress = nullptr;
    }
}

void mergeSort(Institution** headRef) {
    Institution* head = *headRef;
    Institution* front;
    Institution* back;

    if (head == nullptr || head->NextAddress == nullptr) {
        return;
    }

    splitList(head, &front, &back);

    mergeSort(&front);
    mergeSort(&back);

    *headRef = merge(front, back);
}

void mergeSortUniversities() {
    // Count the number of institutions
    int count = 0;
    Institution* current = head;
    while (current != nullptr) {
        count++;
        current = current->NextAddress;
    }

    // Start timer
    auto start = high_resolution_clock::now();
    // Sort the linked list using MergeSort algorithm
    mergeSort(&head);
    // Stop timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by MergeSort: " << duration.count() << " microseconds" << endl;

    // Reassign the tail pointer after sorting
    current = head;
    while (current->NextAddress != nullptr) {
        current->NextAddress->PrevAddress = current;
        current = current->NextAddress;
    }
    tail = current;
}

Institution* mergeByArScore(Institution* left, Institution* right) {
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;
    
    Institution* result = nullptr;
    
    if (left->ArScore >= right->ArScore) {
        result = left;
        result->NextAddress = mergeByArScore(left->NextAddress, right);
    } else {
        result = right;
        result->NextAddress = mergeByArScore(left, right->NextAddress);
    }
    
    return result;
}

// Function to merge two sorted linked lists based on FsrScore
Institution* mergeByFsrScore(Institution* left, Institution* right) {
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;
    
    Institution* result = nullptr;
    
    if (left->FsrScore >= right->FsrScore) {
        result = left;
        result->NextAddress = mergeByFsrScore(left->NextAddress, right);
    } else {
        result = right;
        result->NextAddress = mergeByFsrScore(left, right->NextAddress);
    }
    
    return result;
}

// Function to merge two sorted linked lists based on ErScore
Institution* mergeByErScore(Institution* left, Institution* right) {
    if (left == nullptr)
        return right;
    if (right == nullptr)
        return left;
    
    Institution* result = nullptr;
    
    if (left->ErScore >= right->ErScore) {
        result = left;
        result->NextAddress = mergeByErScore(left->NextAddress, right);
    } else {
        result = right;
        result->NextAddress = mergeByErScore(left, right->NextAddress);
    }
    
    return result;
}

// Function to split the linked list into two halves
void split(Institution* head, Institution** left, Institution** right) {
    Institution* slow = head;
    Institution* fast = head->NextAddress;

    while (fast != nullptr) {
        fast = fast->NextAddress;

        if (fast != nullptr) {
            slow = slow->NextAddress;
            fast = fast->NextAddress;
        }
    }

    *left = head;
    *right = slow->NextAddress;
    slow->NextAddress = nullptr;
}


// Merge sort function for linked list based on ArScore
void mergeSortByArScore(Institution** headRef) {
    Institution* head = *headRef;
    Institution* left = nullptr;
    Institution* right = nullptr;
    
    // Base case: if the list is empty or contains only one node
    if (head == nullptr || head->NextAddress == nullptr)
        return;
    
    // Split the list into two halves
    split(head, &left, &right);
    
    // Recursively sort the two halves
    mergeSortByArScore(&left);
    mergeSortByArScore(&right);
    
    // Merge the sorted halves based on ArScore
    *headRef = mergeByArScore(left, right);
}

// Merge sort function for linked list based on FsrScore
void mergeSortByFsrScore(Institution** headRef) {
    Institution* head = *headRef;
    Institution* left = nullptr;
    Institution* right = nullptr;
    
    // Base case: if the list is empty or contains only one node
    if (head == nullptr || head->NextAddress == nullptr)
        return;
    
    // Split the list into two halves
    split(head, &left, &right);
    
    // Recursively sort the two halves
    mergeSortByFsrScore(&left);
    mergeSortByFsrScore(&right);
    
    // Merge the sorted halves based on FsrScore
    *headRef = mergeByFsrScore(left, right);
}

// Merge sort function for linked list based on ErScore
void mergeSortByErScore(Institution** headRef) {
    Institution* head = *headRef;
    Institution* left = nullptr;
    Institution* right = nullptr;
    
    // Base case: if the list is empty or contains only one node
    if (head == nullptr || head->NextAddress == nullptr)
        return;
    
    // Split the list into two halves
    split(head, &left, &right);
    
    // Recursively sort the two halves
    mergeSortByErScore(&left);
    mergeSortByErScore(&right);
    
    // Merge the sorted halves based on ErScore
    *headRef = mergeByErScore(left, right);
}

// Function to print the linked list with institution name
void printList(Institution* head) {
    Institution* temp = head;
    int count = 0;
    while (temp != nullptr) {
        // Print the desired fields from the node
        cout << "Institution: " << temp->Name << ", ";
        cout << "ArScore: " << temp->ArScore << ", ";
        cout << "FsrScore: " << temp->FsrScore << ", ";
        cout << "ErScore: " << temp->ErScore << endl;
        
		count++;
        temp = temp->NextAddress;

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
    
	
    cout << endl;
}



struct TicketNode {
	string ID;
	string Author;
	string Institution;
	string Query;
	string Reply;
	bool Resolved;
	TicketNode* next;
	
	TicketNode(){
		this->ID = "";
		this->Author = "";
		this->Institution = "";
		this->Query = "";
		this->Reply = "";
		this->Resolved = false;
		this->next = NULL;
	}
	TicketNode(string ID, string Author, string Institution, string Query, string Reply, string Resolved){
		this->ID = ID;
		this->Author = Author;
		this->Institution = Institution;
		this->Query = Query;
		this->Reply = Reply;
		if(Resolved=="Resolved")
			this->Resolved = true;
		else
			this->Resolved = false;
		this->next = NULL;
	}
};

class Ticket {
private:
	TicketNode* head;
public:
	Ticket(){
		head = NULL;
	}	
	
	//Ticket edit functions
	void AddTicket(TicketNode* node){
		if(head == NULL){
			head = node;
		}
		else{
			TicketNode* temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = node;
		}
	}
	void CreateNewTicket(string Author, string Institution, string Query){
		TicketNode* newNode = new TicketNode();
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
	
	//Ticket File Reading
	void ReadFromFile(){
		ifstream file ("Tickets.txt");
		bool header = true;
		string dump;
		string ID;
		string Author;
		string Institution;
		string Query;
		string Reply;
		string Resolved;
		
		while(file.good()){
			if(header){
				getline(file, dump, '\n');
			}
			else{
				getline(file, ID, ',');
				getline(file, Author, ',');
				getline(file, Institution, ',');
				getline(file, Query, ',');
				getline(file, Reply, ',');
				getline(file, Resolved,  '\n');
				
				if(ID == "")
					break;
					
				TicketNode* node = new TicketNode(ID,Author, Institution, Query, Reply, Resolved);
				AddTicket(node);
			}
			header = false;
		}
		file.close();
	}

	//Ticket File Writing
    void WriteToFile(){
        ofstream file("Tickets.txt");

        if(file.is_open()){
            TicketNode* temp = head;
            string resolution="";
            if(temp->Resolved)
                resolution = "Resolved";
            else
                resolution = "Unresolved";
            while(temp!=NULL){
                file << temp->ID << "," << temp->Author << "," << temp->Institution << "," << temp->Query << "," << temp->Reply << "," << resolution << "\n";
            }
        }
        else{
            cout << "Error opening file" << endl;
        }
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

//For Admin Login, use this function
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

//For Customer Login, use this function
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


struct Favorite {
    string name;
    int students;

    Favorite() {}
    Favorite(const string& n, int s) : name(n), students(s) {}
};

// Function to compare universities based on the number of students
bool compareUniversities(const Favorite& u1, const Favorite& u2) {
    return u1.students > u2.students; // Sort in descending order
}

// Function to perform quicksort
void quicksort(Favorite* arr, int left, int right) {
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
    ifstream inputFile("Favorite_uni.txt");
    if (!inputFile) {
        cout << "Failed to open file." << endl;
        return;
    }

    const int size = 1400;
    Favorite universities[size];
    int index = 0;
    string line;
    while (getline(inputFile, line) && index < size) {
        // Assuming the format of each line is: university_name, number_of_students
        size_t commaPos = line.find(',');
        string name = line.substr(0, commaPos);
        int students = stoi(line.substr(commaPos + 1));

        universities[index] = Favorite(name, students);
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
