// Task 2: Read the list of fruits from "fruit.txt",
// then print the message "Fresh Fruits" in the same file.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Create the file with the fruits list (as given in the task)
    ofstream create("fruit.txt");
    create << "Apple" << endl;
    create << "Orange" << endl;
    create << "Banana" << endl;
    create.close();

    // Read the list contents from the file
    ifstream in("fruit.txt");
    if (!in) {
        cout << "Error: could not open fruit.txt" << endl;
        return 1;
    }
    string line;
    cout << "Fruits list:" << endl;
    while (getline(in, line)) {
        cout << line << endl;
    }
    in.close();

    // Append the message to the same file
    ofstream out("fruit.txt", ios::app);
    out << "Fresh Fruits" << endl;
    out.close();

    cout << "\"Fresh Fruits\" was added to fruit.txt" << endl;
    return 0;
}
