#include <iostream>
#include <string>

using namespace std;

string caeser_encode(string message, int key) {
    for (char &c : message) c += key;
    return message;
}

string caesar_decode(string message, int key) {
    for (char &c : message) c -= key;
    return message;
}

int main() {
    string m = "Caesar's cipher test";
    cout << (m = caeser_encode(m, 5)) << endl;
    cout << caesar_decode(m, 5) << endl;
}