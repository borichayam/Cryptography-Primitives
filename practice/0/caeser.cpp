#include <iostream>
#include <string>

using namespace std;

string caesar_encode(string message, int key) {
    for(char &a : message) 
        a = a + key;

    return message;
}

string casesar_decode(string message, int key) {
    for(char &b : message) 
        b = b - key;

    return message;
}

int main() {
    string m = "Caesar's cipher test";

    cout << (m = caesar_encode(m, 3)) << endl;
    cout << casesar_decode(m, 3) << endl;
}