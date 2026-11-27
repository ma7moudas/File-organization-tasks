// Task 1: Accept student's data (Full name, ID, Grade)
// then create a new text file named "Student" and write the data on it.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string fullName;
    int id;
    float grade;

    cout << "Enter full name: ";
    getline(cin, fullName);
    cout << "Enter ID: ";
    cin >> id;
    cout << "Enter grade: ";
    cin >> grade;

    ofstream file("Student.txt");
    if (!file) {
        cout << "Error: could not create file!" << endl;
        return 1;
    }

    file << "Full name: " << fullName << endl;
    file << "ID: " << id << endl;
    file << "Grade: " << grade << endl;
    file.close();

    cout << "Student data was written to Student.txt" << endl;
    return 0;
}
