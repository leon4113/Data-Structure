#include <iostream>
#include <string>
#include <fstream>
#include "sort_uni_name.hpp"

using namespace std;

struct University {
    string name;
    int students;

    University() {}
    University(const string& n, int s) : name(n), students(s) {}
};

const int size = 1400;
University universities[size];

void AddFavourite(string uniname){
	int index=0;
	while(index<size){
		if(universities[index]->name == uniname){
			universitites[index]->students++;
			cout << "Successfully added to favorites!\n\n";
			return;
		}
		index++;	
	}
	cout << "University name not found\n\n";
	return;
}

void FeedbackMenu(){
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

int main() {
    ifstream inputFile("modified_output.txt");
    if (!inputFile) {
        cout << "Failed to open file." << endl;
        return 1;
    }

    
    int index = 0;
    string line;
    getline(inputFile, line); // Skip the header line

    while (getline(inputFile, line) && index < size) {
        istringstream iss(line);

        string tokens[22]; // Assuming there are 22 fields in each line

        for (int i = 0; i < 22; i++) {
            getline(iss, tokens[i], ',');
        }

        // Assuming the format of each line is: Rank,Institution,LocationCode,Location,ArScore,...
        if (tokens[1].size() > 0) {
            string name = tokens[1];
            int students = 0; // You can add code to extract the number of students from the appropriate field

            universities[index] = University(name, students);
            index++;
        }
    }

    inputFile.close();
    return 0;
}
