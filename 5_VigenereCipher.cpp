
#include <string>
using namespace std;

string toLowerCase(const string &input) {
    string result = input;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int mod(int a, int b) {
    return (a % b + b) % b;
}

string vigenereEncrypt(const string &plaintext, const string &key) {
    string ciphertext, processedKey = toLowerCase(key);
    size_t keyIndex = 0, keyLength = processedKey.size();
    for (char c : plaintext) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            int shift = processedKey[keyIndex % keyLength] - 'a';
            ciphertext += static_cast<char>(mod(c - base + shift, 26) + base);
            keyIndex++;
        } else ciphertext += c;
    }
    return ciphertext;
}

string vigenereDecrypt(const string &ciphertext, const string &key) {
    string plaintext, processedKey = toLowerCase(key);
    size_t keyIndex = 0, keyLength = processedKey.size();
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            int shift = processedKey[keyIndex % keyLength] - 'a';
            plaintext += static_cast<char>(mod(c - base - shift, 26) + base);
            keyIndex++;
        } else plaintext += c;
    }
    return plaintext;
}
