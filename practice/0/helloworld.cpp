#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> msg = {
        "hello", "it's", "too", "hard..", "help", "me..."
    };

    for (const string &word : msg) {
        cout << word << " ";
    }
    cout << endl;
}