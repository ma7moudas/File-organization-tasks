// Task 6 (Student Task): Manage grades stored in grades.txt
// 1) Create the file and write five integer grades.
// 2) Read and print the grades using a correct reading loop.
// 3) Ask the user for a grade to delete, then create a temporary file without it.
// 4) Replace the original file and show a success or error message.
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

void printGrades(const char* title) {
    ifstream in("grades.txt");
    int g;
    cout << title << endl;
    while (in >> g) {          // correct reading loop
        cout << g << " ";
    }
    cout << endl;
    in.close();
}

int main() {
    // 1) Create the file and write five integer grades
    ofstream out("grades.txt");
    int grades[5];
    cout << "Enter 5 integer grades: ";
    for (int i = 0; i < 5; i++) {
        cin >> grades[i];
        out << grades[i] << endl;
    }
    out.close();

    // 2) Read and print
    printGrades("Grades before deletion:");

    // 3) Ask for a grade to delete, write the rest to a temp file
    int toDelete;
    cout << "Enter a grade to delete: ";
    cin >> toDelete;

    ifstream in("grades.txt");
    ofstream temp("temp.txt");
    int g;
    bool found = false;
    while (in >> g) {
        if (g == toDelete && !found) {   // delete first match only
            found = true;
        } else {
            temp << g << endl;
        }
    }
    in.close();
    temp.close();

    // 4) Replace the original file
    if (!found) {
        remove("temp.txt");
        cout << "Error: grade " << toDelete << " was not found." << endl;
    } else {
        if (remove("grades.txt") == 0 && rename("temp.txt", "grades.txt") == 0) {
            cout << "Success: grade " << toDelete << " was deleted." << endl;
        } else {
            cout << "Error: could not replace the original file." << endl;
        }
    }

    printGrades("Grades after deletion:");
    return 0;
}
