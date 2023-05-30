#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string addZeroBetweenCommas(const string& input) {
    string result;
    size_t pos = 0;
    size_t prevPos = 0;
    bool inQuotes = false;

    while (pos < input.length()) {
        if (input[pos] == '"') {
            inQuotes = !inQuotes;
        } else if (input[pos] == ',' && inQuotes) {
            // Skip commas inside double quotes
            ++pos;
            continue;
        }

        result += input[pos];
        ++pos;
    }

    return result;
}

int main() {
    string filename;
    cout << "Enter the name of the CSV file: ";
    cin >> filename;

    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening input file: " << filename << endl;
        return 1;
    }

    string line;
    string fullInput;
    while (getline(inputFile, line)) {
        fullInput += line + '\n';
    }

    string result = addZeroBetweenCommas(fullInput);

    string outputFilename = "modified_output.txt";
    ofstream outputFile(outputFilename);
    if (!outputFile) {
        cerr << "Error creating output file: " << outputFilename << endl;
        return 1;
    }

    outputFile << result;

    cout << "Modified text has been written to: " << outputFilename << endl;

    return 0;
}
