
#include <string>
#include <vector>
using namespace std;

string removeSpaces(const string &input) {
    string result;
    for (char c : input) {
        if (c != ' ') result += c;
    }
    return result;
}

string routeEncrypt(const string &plaintext, int rows, int cols, const string &route) {
    string text = removeSpaces(plaintext);
    while (text.size() < rows * cols) text += 'x';

    vector<vector<char>> grid(rows, vector<char>(cols));
    int idx = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            grid[i][j] = text[idx++];

    string result;
    if (route == "zigzag") {
        for (int i = 0; i < rows; i++) {
            if (i % 2 == 0)
                for (int j = 0; j < cols; j++) result += grid[i][j];
            else
                for (int j = cols - 1; j >= 0; j--) result += grid[i][j];
        }
    } else {
        for (int j = 0; j < cols; j++)
            for (int i = 0; i < rows; i++)
                result += grid[i][j];
    }
    return result;
}

string routeDecrypt(const string &ciphertext, int rows, int cols, const string &route) {
    vector<vector<char>> grid(rows, vector<char>(cols));
    int idx = 0;

    if (route == "zigzag") {
        for (int i = 0; i < rows; i++) {
            if (i % 2 == 0)
                for (int j = 0; j < cols; j++) grid[i][j] = ciphertext[idx++];
            else
                for (int j = cols - 1; j >= 0; j--) grid[i][j] = ciphertext[idx++];
        }
    } else {
        for (int j = 0; j < cols; j++)
            for (int i = 0; i < rows; i++)
                grid[i][j] = ciphertext[idx++];
    }

    string result;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result += grid[i][j];
    return result;
}
