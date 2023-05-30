#include <iostream>
#include <fstream>
#include <algorithm> 
using namespace std;

// Structure to store university data
struct University {
    string name;
    int students;

    University() {}
    University(const string& n, int s) : name(n), students(s) {}
};

// Function to compare universities based on the number of students
bool compareUniversities(const University& u1, const University& u2) {
    return u1.students > u2.students; // Sort in descending order
}

// Function to perform quicksort
void quicksort(University* arr, int left, int right) {
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

int main() {
    ifstream inputFile("favorites_uni.txt");
    if (!inputFile) {
        cout << "Failed to open file." << endl;
        return 1;
    }

    const int size = 1400;
    University universities[size];
    int index = 0;
    string line;
    while (getline(inputFile, line) && index < size) {
        // Assuming the format of each line is: university_name, number_of_students
        size_t commaPos = line.find(',');
        string name = line.substr(0, commaPos);
        int students = stoi(line.substr(commaPos + 1));

        universities[index] = University(name, students);
        index++;
    }

    inputFile.close();

    // Sort the universities based on the number of students using quicksort
    quicksort(universities, 0, index - 1);

    // Print the sorted universities
    cout << "Top 10 Universities:" << endl;
    int count = 0;
    for (int i = 0; i < index; i++) {
        cout << universities[i].name << ": " << universities[i].students << " students" << endl;
        count++;
        if (count >= 10) break;
    }

    return 0;
}
