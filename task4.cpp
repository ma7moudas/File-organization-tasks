// Task 4 (Lab 1):
// 1) User enters number of persons, then (name, age) for each one.
//    Save them in a file as a string and an integer.
// 2) Load all persons from the file into a vector of Person,
//    find the youngest and oldest, and save them in a results file.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    // ---------- Step 1: write persons to file ----------
    int n;
    cout << "How many persons do you want to add? ";
    cin >> n;
    cin.ignore();

    ofstream out("persons.txt");
    if (!out) {
        cout << "Error: could not create persons.txt" << endl;
        return 1;
    }
    for (int i = 0; i < n; i++) {
        string name;
        int age;
        cout << "Person " << i + 1 << " name: ";
        getline(cin, name);
        cout << "Person " << i + 1 << " age: ";
        cin >> age;
        cin.ignore();
        out << name << endl;   // string
        out << age << endl;    // integer
    }
    out.close();

    // ---------- Step 2: load into vector ----------
    vector<Person> people;
    ifstream in("persons.txt");
    Person p;
    while (getline(in, p.name) && (in >> p.age)) {
        in.ignore();
        people.push_back(p);
    }
    in.close();

    if (people.empty()) {
        cout << "No data found." << endl;
        return 1;
    }

    // find youngest and oldest
    Person youngest = people[0], oldest = people[0];
    for (size_t i = 1; i < people.size(); i++) {
        if (people[i].age < youngest.age) youngest = people[i];
        if (people[i].age > oldest.age)   oldest = people[i];
    }

    // save in results file
    ofstream res("results.txt");
    res << "Youngest person: " << youngest.name << ", age " << youngest.age << endl;
    res << "Oldest person: "   << oldest.name   << ", age " << oldest.age   << endl;
    res.close();

    cout << "Results saved in results.txt" << endl;
    cout << "Youngest: " << youngest.name << " (" << youngest.age << ")" << endl;
    cout << "Oldest: "   << oldest.name   << " (" << oldest.age   << ")" << endl;
    return 0;
}
