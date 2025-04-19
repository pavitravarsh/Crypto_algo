#include <iostream>
#include <string>
using namespace std;

string augustEncrypt(string text) {
    string result = "";
    int key = 1; // Fixed shift for August Cipher

    for (char c : text) {
        if (isupper(c)) {
            result += 'A' + (c - 'A' + key) % 26;
        } else if (islower(c)) {
            result += 'a' + (c - 'a' + key) % 26;
        } else {
            result += c; // Keep spaces and symbols unchanged
        }
    }

    return result;
}

string augustDecrypt(string text) {
    string result = "";
    int key = 1; // Fixed shift

    for (char c : text) {
        if (isupper(c)) {
            result += 'A' + (c - 'A' - key + 26) % 26;
        } else if (islower(c)) {
            result += 'a' + (c - 'a' - key + 26) % 26;
        } else {
            result += c;
        }
    }

    return result;
}

int main() {
    string message;

    cout << "Enter message: ";
    getline(cin, message);

    string encrypted = augustEncrypt(message);
    cout << "Encrypted (August Cipher): " << encrypted << endl;

    string decrypted = augustDecrypt(encrypted);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
