
#include <string>
#include <map>
#include <algorithm>
using namespace std;

string toLowerCase(const string &input)
{
    string result = input;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

string augustEncrypt(const string &plaintext, const string &keyword, int shift)
{
    string normalAlphabet = "abcdefghijklmnopqrstuvwxyz";
    string substitutionAlphabet = "";

    string processedKeyword = toLowerCase(keyword);
    for (char c : processedKeyword)
        if (isalpha(c) && substitutionAlphabet.find(c) == string::npos)
            substitutionAlphabet += c;

    for (char c : normalAlphabet)
        if (substitutionAlphabet.find(c) == string::npos)
            substitutionAlphabet += c;

    string shiftedAlphabet = "";
    for (size_t i = 0; i < substitutionAlphabet.size(); i++)
        shiftedAlphabet += substitutionAlphabet[(i + shift) % 26];

    string ciphertext = "";
    for (char c : plaintext)
    {
        if (isalpha(c))
        {
            char base = islower(c) ? 'a' : 'A';
            size_t pos = tolower(c) - 'a';
            char encryptedChar = islower(c) ? shiftedAlphabet[pos] : toupper(shiftedAlphabet[pos]);
            ciphertext += encryptedChar;
        }
        else
            ciphertext += c;
    }

    return ciphertext;
}

string augustDecrypt(const string &ciphertext, const string &keyword, int shift)
{
    string normalAlphabet = "abcdefghijklmnopqrstuvwxyz";
    string substitutionAlphabet = "";

    string processedKeyword = toLowerCase(keyword);
    for (char c : processedKeyword)
        if (isalpha(c) && substitutionAlphabet.find(c) == string::npos)
            substitutionAlphabet += c;

    for (char c : normalAlphabet)
        if (substitutionAlphabet.find(c) == string::npos)
            substitutionAlphabet += c;

    string shiftedAlphabet = "";
    for (size_t i = 0; i < substitutionAlphabet.size(); i++)
        shiftedAlphabet += substitutionAlphabet[(i + shift) % 26];

    map<char, char> decryptMap;
    for (size_t i = 0; i < normalAlphabet.size(); i++)
        decryptMap[shiftedAlphabet[i]] = normalAlphabet[i];

    string plaintext = "";
    for (char c : ciphertext)
    {
        if (isalpha(c))
        {
            char decryptedChar = islower(c) ? decryptMap[c] : toupper(decryptMap[tolower(c)]);
            plaintext += decryptedChar;
        }
        else
            plaintext += c;
    }

    return plaintext;
}
