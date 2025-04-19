#include <iostream>
#include <string>
using namespace std;

string caesarEncrypt(string text, int key) {
    string result = "";

    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char enc = (c - base + key) % 26 + base;
            result += enc;
        } else {
            result += c; // keep non-alphabet characters unchanged
        }
    }

    return result;
}

string caesarDecrypt(string cipher, int key) {
    string result = "";

    for (char c : cipher) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            char dec = (c - base - key + 26) % 26 + base;
            result += dec;
        } else {
            result += c;
        }
    }

    return result;
}

int main() {
    string text;
    int key;

    cout << "Enter plaintext: ";
    getline(cin, text);
    cout << "Enter key (0-25): ";
    cin >> key;

    string encrypted = caesarEncrypt(text, key);
    cout << "\nEncrypted Text: " << encrypted << endl;

    string decrypted = caesarDecrypt(encrypted, key);
    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}
