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

// Function to perform merge operation in merge sort
void merge(University* arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    University* leftArr = new University[leftSize];
    University* rightArr = new University[rightSize];

    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }

    for (int j = 0; j < rightSize; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < leftSize && j < rightSize) {
        if (compareUniversities(leftArr[i], rightArr[j])) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;
}

// Function to perform merge sort
void mergeSort(University* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
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

        string rank;
        getline(iss, rank, ',');

        string name;
        getline(iss, name, ','); // Extract the institution name from the second field

        // Assuming the format of each line is: Rank,Institution,LocationCode,Location,ArScore,...
        if (!name.empty()) {
            int students = 0; // You can add code to extract the number of students from the appropriate field

            universities[index] = University(name, students);
            index++;
        }
    }

    inputFile.close();

    // Sort the universities based on the name using merge sort
    mergeSort(universities, 0, index - 1);

    // Print the sorted universities
    cout << "Sorted Universities by Name:" << endl;
    for (int i = 0; i < index; i++) {
        cout << i + 1 << ": " << universities[i].name << endl;
    }

    return 0;
}
