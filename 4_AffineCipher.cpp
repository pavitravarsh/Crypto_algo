
#include <string>
using namespace std;

int mod(int a, int b) {
    return (a % b + b) % b;
}

int gcdExtended(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0; *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    return (g != 1) ? -1 : mod(x, m);
}

string affineEncrypt(const string &plaintext, int a, int b) {
    string ciphertext;
    if (modInverse(a, 26) == -1)
        return "Error: a must be coprime with 26.";
    for (char c : plaintext) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            int x = c - base;
            ciphertext += static_cast<char>(mod(a * x + b, 26) + base);
        } else ciphertext += c;
    }
    return ciphertext;
}

string affineDecrypt(const string &ciphertext, int a, int b) {
    string plaintext;
    int aInv = modInverse(a, 26);
    if (aInv == -1)
        return "Error: a must be coprime with 26.";
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            int y = c - base;
            plaintext += static_cast<char>(mod(aInv * (y - b), 26) + base);
        } else plaintext += c;
    }
    return plaintext;
}
