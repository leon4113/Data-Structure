#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

// Structure to store university data
struct University {
    string name;
    int students;

    University() {}
    University(const string& n, int s) : name(n), students(s) {}
};

// Function to compare universities based on the name
bool compareUniversities(const University& u1, const University& u2) {
    return u1.name < u2.name; // Sort in ascending order
}

// Function to perform quicksort
void quicksort(University* arr, int left, int right) {
    if (left >= right) {
        return;
    }

    string pivot = arr[(left + right) / 2].name;
    int i = left;
    int j = right;

    while (i <= j) {
        while (arr[i].name < pivot) {
            i++;
        }

        while (arr[j].name > pivot) {
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

int main() {
    ifstream inputFile("modified_output.txt");
    if (!inputFile) {
        cout << "Failed to open file." << endl;
        return 1;
    }

    const int size = 1400;
    University universities[size];
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

    // Sort the universities based on the name using quicksort
    quicksort(universities, 0, index - 1);

    // Print the sorted universities
    cout << "Sorted Universities by Name:" << endl;
    for (int i = 0; i < index; i++) {
        cout << universities[i].name << ": " << universities[i].students << " students" << endl;
    }

    return 0;
}
