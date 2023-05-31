#include <iostream>
#include <chrono>
#include <fstream>
#include <sstream>


using namespace std;
using namespace std::chrono;

//masukin ke assignment.hpp
// Function to merge two sorted linked lists based on ArScore
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
    
    while (temp != nullptr) {
        // Print the desired fields from the node
        cout << "Institution: " << temp->Name << ", ";
        cout << "ArScore: " << temp->ArScore << ", ";
        cout << "FsrScore: " << temp->FsrScore << ", ";
        cout << "ErScore: " << temp->ErScore << endl;
        
        temp = temp->NextAddress;
    }
    
    cout << endl;
}


// int main() {

//     // Ask the user for the sorting criterion
//     int choice;
//     cout << "Enter the sorting criterion: " << endl;
//     cout << "1. Sort by Academic Reputation Score" << endl;
//     cout << "2. Sort by Faculty/Student Ratio" << endl;
//     cout << "3. Sort by Employer Reputation Score" << endl;
//     cin >> choice;
    
//     // Sort the linked list based on the user's choice
//     switch (choice) {
//         case 1:
//             mergeSortByArScore(&head);
//             break;
//         case 2:
//             mergeSortByFsrScore(&head);
//             break;
//         case 3:
//             mergeSortByErScore(&head);
//             break;
//         default:
//             cout << "Invalid choice. Sorting by Academic Reputation Score." << endl;
//             mergeSortByArScore(&head);
//             break;
//     }
    
//     // Print the sorted linked list
//     cout << "Sorted Linked List: " << endl;
//     printList(head);
    
//     return 0;
// }