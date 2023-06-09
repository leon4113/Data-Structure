#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;

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