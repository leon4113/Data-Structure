#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>


using namespace std;
using namespace std::chrono;

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


void addDataFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    getline(file, line);  // Read and discard the header line

    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        // Read the CSV values
        int rank;
        string name, locationCode, location;
        double arScore, erScore, fsrScore, cpfScore, ifrScore, isrScore, irnScore, gerScore, scoreScaled;
        string arRank, erRank, fsrRank, cpfRank, ifrRank, isrRank, irnRank, gerRank;

        getline(ss, token, ',');
        rank = stoi(token);
        getline(ss, name, ',');
        getline(ss, locationCode, ',');
        getline(ss, location, ',');
        getline(ss, token, ',');
        arScore = stod(token);
        getline(ss, arRank, ',');
        getline(ss, token, ',');
        erScore = stod(token);
        getline(ss, erRank, ',');
        getline(ss, token, ',');
        fsrScore = stod(token);
        getline(ss, fsrRank, ',');
        getline(ss, token, ',');
        cpfScore = stod(token);
        getline(ss, cpfRank, ',');
        getline(ss, token, ',');
        ifrScore = stod(token);
        getline(ss, ifrRank, ',');
        getline(ss, token, ',');
        isrScore = stod(token);
        getline(ss, isrRank, ',');
        getline(ss, token, ',');
        irnScore = stod(token);
        getline(ss, irnRank, ',');
        getline(ss, token, ',');
        gerScore = stod(token);
        getline(ss, gerRank, ',');
        getline(ss, token);
        scoreScaled = stod(token);

        // Create a new node with the read values
        Institution* newNode = CreateNewNode(rank, name, locationCode, location, arScore, arRank, erScore, erRank,
            fsrScore, fsrRank, cpfScore, cpfRank, ifrScore, ifrRank, isrScore, isrRank,
            irnScore, irnRank, gerScore, gerRank, scoreScaled);

        // Insert the new node into the doubly linked list
        InsertIntoEndofList(newNode);
    }

    file.close();
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
