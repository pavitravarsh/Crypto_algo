
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string toLowerCase(const string &input) {
    string result = input;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

string removeSpaces(const string &input) {
    string result;
    for (char c : input)
        if (c != ' ') result += c;
    return result;
}

string myszkowskiEncrypt(const string &plaintext, const string &key) {
    string pt = removeSpaces(plaintext), k = toLowerCase(key);
    map<char, vector<int>> keyMap;
    for (int i = 0; i < k.size(); i++) keyMap[k[i]].push_back(i);

    vector<int> numKey(k.size());
    int rank = 1;
    for (char c = 'a'; c <= 'z'; c++)
        if (keyMap.count(c))
            for (int i : keyMap[c]) numKey[i] = rank++;
    
    int cols = k.size();
    int rows = (pt.length() + cols - 1) / cols;
    vector<vector<char>> grid(rows, vector<char>(cols, 'x'));
    int idx = 0;
    for (int i = 0; i < rows && idx < pt.length(); i++)
        for (int j = 0; j < cols && idx < pt.length(); j++)
            grid[i][j] = pt[idx++];

    string ct;
    for (int r = 1; r < rank; r++)
        for (int j = 0; j < cols; j++)
            if (numKey[j] == r)
                for (int i = 0; i < rows; i++)
                    ct += grid[i][j];
    return ct;
}
