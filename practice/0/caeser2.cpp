#include <iostream>
#include <string>

using namespace std;

string caesar_encode(string message, int key) {
    key = ((key % 26) +26) %26;

    for(char &a : message) {
        if ('a' <= a && a <= 'z') {
            a = 'a' + (a-'a'+key)%26;
        }else if ('A' <= a && a <= 'Z') {
            a = 'A' + (a-'A'+key)%26;
        }
    }

    return message;
}

string casesar_decode(string message, int key) {
    return caesar_encode(message, -key);
}

int main() {
    string m = "Caesar's cipher test";

    cout << (m = caesar_encode(m, 3)) << endl;
    cout << casesar_decode(m, 3) << endl;
}