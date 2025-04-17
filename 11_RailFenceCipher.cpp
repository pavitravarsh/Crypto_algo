
#include <string>
#include <vector>
using namespace std;

string railFenceEncrypt(const string &plaintext, int rails) {
    if (rails <= 1)
        return plaintext;

    vector<string> fence(rails, "");
    int rail = 0;
    bool goingDown = false;

    for (char c : plaintext) {
        fence[rail] += c;
        if (rail == 0 || rail == rails - 1)
            goingDown = !goingDown;
        rail += goingDown ? 1 : -1;
    }

    string ciphertext;
    for (const string &s : fence)
        ciphertext += s;

    return ciphertext;
}

string railFenceDecrypt(const string &ciphertext, int rails) {
    if (rails <= 1)
        return ciphertext;

    vector<vector<char>> fence(rails, vector<char>(ciphertext.length(), '.'));
    int rail = 0;
    bool goingDown = false;

    for (size_t i = 0; i < ciphertext.length(); i++) {
        fence[rail][i] = '*';
        if (rail == 0 || rail == rails - 1)
            goingDown = !goingDown;
        rail += goingDown ? 1 : -1;
    }

    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (size_t j = 0; j < ciphertext.length(); j++) {
            if (fence[i][j] == '*' && index < ciphertext.length()) {
                fence[i][j] = ciphertext[index++];
            }
        }
    }

    string plaintext;
    rail = 0;
    goingDown = false;

    for (size_t i = 0; i < ciphertext.length(); i++) {
        plaintext += fence[rail][i];
        if (rail == 0 || rail == rails - 1)
            goingDown = !goingDown;
        rail += goingDown ? 1 : -1;
    }

    return plaintext;
}
