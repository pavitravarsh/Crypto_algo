
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

string beaufortCipher(const string &input, const string &key) {
    string result, processedKey = toLowerCase(key);
    size_t keyIndex = 0, keyLength = processedKey.length();
    for (char c : input) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            char keyChar = processedKey[keyIndex % keyLength];
            result += static_cast<char>(mod(keyChar - tolower(c) + 26, 26) + base);
            keyIndex++;
        } else result += c;
    }
    return result;
}
