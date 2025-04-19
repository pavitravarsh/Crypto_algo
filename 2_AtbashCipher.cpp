#include <iostream>
#include <string>
using namespace std;

string atbashCipher(string text) {
    string result = "";

    for (char c : text) {
        if (isupper(c)) {
            result += 'A' + (25 - (c - 'A'));
        } else if (islower(c)) {
            result += 'a' + (25 - (c - 'a'));
        } else {
            result += c; 
        }
    }

    return result;
}

int main() {
    string text;

    cout << "Enter text for Atbash cipher: ";
    getline(cin, text);

    string output = atbashCipher(text);
    cout << "Atbash Output: " << output << endl;

    return 0;
}
