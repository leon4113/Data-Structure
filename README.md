
---

# Data Structure and Administrative Management System

## Project Description

This project combines a variety of C++ implementations of common data structures with a basic administrative management system. The system includes user management, ticket tracking, and university data handling functionalities, demonstrating practical applications of data structures in managing and organizing data efficiently.

## Features

1. **Data Structures Implementations:**
   - Array
   - Linked List
   - Stack
   - Queue
   - Tree
   - Graph
   - Hash Table
   - Heap

   These data structures are implemented in C++ and are designed to provide efficient data management solutions for various applications.

2. **Administrative Management System:**
   - **User Management:** Handles user information, including usernames, passwords, and email addresses.
   - **Ticket Tracking:** Manages a simple ticketing system.
   - **University Data Management:** Stores and processes information about universities.

## Installation

### Prerequisites

Ensure you have the following installed:

- C++ Compiler (GCC, Clang, or similar)
- Basic knowledge of C++ programming

### Compilation

To compile the project files, use the following commands:

```bash
g++ -o admin admin.cpp admin.hpp
g++ -o assignment Assignment.cpp Assignment.hpp
g++ -o clean clean_dataset.cpp
```

### Running the Program

Once compiled, you can run the programs using:

```bash
./admin
./assignment
./clean
```

Ensure that the accompanying text files (`users.txt`, `Tickets.txt`, `Favorite_uni.txt`, `Institution.csv`) are in the same directory as the compiled binaries.

## Usage

### User Management

The system reads user data from `users.txt`, which contains records of users with their usernames, passwords, and email addresses.

### Ticket Tracking

The `Tickets.txt` file stores and manages tickets, which are handled by the ticket tracking system.

### University Data Management

The `Favorite_uni.txt` and `Institution.csv` files store and manage data related to universities. The system can be extended to manipulate and analyze this data.

## Files

- **`admin.hpp` and `admin.cpp`**: Handle administrative functions.
- **`Assignment.hpp` and `Assignment.cpp`**: Implement core data structures and algorithms.
- **`clean_dataset.cpp`**: A utility for processing and cleaning datasets.
- **`users.txt`**: Contains user information.
- **`Tickets.txt`**: Stores ticketing system data.
- **`Favorite_uni.txt`**: Manages favorite university data.
- **`Institution.csv`**: Contains university information.

## Contributing

Contributions are welcome! If you have suggestions or improvements, feel free to fork this repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License.
