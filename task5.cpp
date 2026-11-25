// Task 5 (Lab 2): Write student records (name, id, grade) for any number
// of students while the user enters 'y'. Stop when 'n' is entered.
// Records are added to "students.txt", each record delimited by '$'.
// Format: Name (char[20]), ID (int), Grade (float), delim (char)
// Example: Mohamed Ali, 33, 2 $
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char name[20];
    int id;
    float grade;
    char choice;

    ofstream file("students.txt", ios::app);
    if (!file) {
        cout << "Error: could not open students.txt" << endl;
        return 1;
    }

    do {
        cout << "Enter name: ";
        cin.ignore(0);
        cin >> ws;
        cin.getline(name, 20);
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter grade: ";
        cin >> grade;

        file << name << ", " << id << ", " << grade << " $" << endl;

        cout << "Add more records? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    file.close();
    cout << "Records saved in students.txt" << endl;
    return 0;
}
