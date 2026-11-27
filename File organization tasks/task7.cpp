// Task 7: Sort student names in ascending order.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> names = {
        "Hadeer Mahmoud",
        "Youssef Ali",
        "Ahmed Mostafa",
        "Esraa Ebrahim"
    };

    sort(names.begin(), names.end());   // ascending order

    cout << "Names in ascending order:" << endl;
    for (size_t i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
    }

    // Also save the sorted names in a file
    ofstream out("sorted_names.txt");
    for (size_t i = 0; i < names.size(); i++) {
        out << names[i] << endl;
    }
    out.close();

    return 0;
}
