// Task 3: Write "Hello Everybody" in welcome.txt, then replace
// "body" with "one" and write the final result "Hello Everyone"
// in the same file.
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // 1) Write the sentence
    ofstream out("welcome.txt");
    out << "Hello Everybody";
    out.close();

    // 2) Read it back
    ifstream in("welcome.txt");
    string text;
    getline(in, text);
    in.close();

    // 3) Replace "body" with "one"
    size_t pos = text.find("body");
    if (pos != string::npos) {
        text.replace(pos, 4, "one");
    }

    // 4) Write the final result in the same file
    ofstream out2("welcome.txt");
    out2 << text;
    out2.close();

    cout << "Final result in welcome.txt: " << text << endl;
    return 0;
}
