
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string removeSpaces(const string &input) {
    string result;
    for (char c : input) {
        if (c != ' ')
            result += c;
    }
    return result;
}

string ngramEncrypt(const string &plaintext, int n) {
    if (n <= 0)
        return plaintext;

    string text = removeSpaces(plaintext);
    vector<string> ngrams;

    for (size_t i = 0; i < text.length(); i += n) {
        string ngram = text.substr(i, min(n, static_cast<int>(text.length() - i)));
        while (ngram.length() < size_t(n)) {
            ngram += 'x';
        }
        ngrams.push_back(ngram);
    }

    sort(ngrams.begin(), ngrams.end());

    string ciphertext;
    for (const string &ngram : ngrams) {
        ciphertext += ngram;
    }

    return ciphertext;
}

string ngramDecrypt(const string &ciphertext, int n, const string &original) {
    return "N-gram decryption requires additional information about the original ordering.";
}
