
#include <string>
using namespace std;

int mod(int a, int b) {
    return (a % b + b) % b;
}

string gronsfeldEncrypt(const string &plaintext, const string &numericKey) {
    string ciphertext;
    size_t keyIndex = 0, keyLength = numericKey.size();
    for (char c : plaintext) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            int shift = numericKey[keyIndex % keyLength] - '0';
            ciphertext += static_cast<char>(mod(c - base + shift, 26) + base);
            keyIndex++;
        } else ciphertext += c;
    }
    return ciphertext;
}

string gronsfeldDecrypt(const string &ciphertext, const string &numericKey) {
    string plaintext;
    size_t keyIndex = 0, keyLength = numericKey.size();
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            int shift = numericKey[keyIndex % keyLength] - '0';
            plaintext += static_cast<char>(mod(c - base - shift, 26) + base);
            keyIndex++;
        } else plaintext += c;
    }
    return plaintext;
}
