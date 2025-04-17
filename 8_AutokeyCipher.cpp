
#include <string>
using namespace std;

int mod(int a, int b) {
    return (a % b + b) % b;
}

string toLowerCase(const string &input) {
    string result = input;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

string autokeyEncrypt(const string &plaintext, const string &initialKey) {
    string ciphertext, fullKey = toLowerCase(initialKey);
    for (char c : plaintext)
        if (isalpha(c)) fullKey += tolower(c);
    size_t keyIndex = 0;
    for (char c : plaintext) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            int shift = fullKey[keyIndex] - 'a';
            ciphertext += static_cast<char>(mod(c - base + shift, 26) + base);
            keyIndex++;
        } else ciphertext += c;
    }
    return ciphertext;
}

string autokeyDecrypt(const string &ciphertext, const string &initialKey) {
    string plaintext, fullKey = toLowerCase(initialKey);
    size_t keyIndex = 0;
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            int shift = fullKey[keyIndex] - 'a';
            char plainChar = static_cast<char>(mod(c - base - shift, 26) + base);
            plaintext += plainChar;
            fullKey += tolower(plainChar);
            keyIndex++;
        } else plaintext += c;
    }
    return plaintext;
}
