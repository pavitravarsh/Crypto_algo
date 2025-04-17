
#include <string>
#include <vector>
#include <stdexcept>
#include <cctype>
#include <algorithm>
using namespace std;

int mod(int a, int b) {
    return (a % b + b) % b;
}

vector<vector<int>> getKeyMatrix(const string &key, int n) {
    vector<vector<int>> keyMatrix(n, vector<int>(n, 0));
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            keyMatrix[i][j] = (k < key.length()) ? (tolower(key[k++]) - 'a') : 0;
    return keyMatrix;
}

int determinant(const vector<vector<int>> &matrix, int n) {
    if (n == 2)
        return mod(matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0], 26);

    int det = 0;
    for (int i = 0; i < n; i++) {
        vector<vector<int>> sub(n - 1, vector<int>(n - 1));
        for (int j = 1; j < n; j++)
            for (int k = 0, col = 0; k < n; k++)
                if (k != i)
                    sub[j - 1][col++] = matrix[j][k];
        det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determinant(sub, n - 1);
    }
    return mod(det, 26);
}

int modInverse(int a, int m) {
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

vector<vector<int>> adjoint(const vector<vector<int>> &matrix, int n) {
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            vector<vector<int>> temp(n - 1, vector<int>(n - 1));
            for (int r = 0, tr = 0; r < n; r++) {
                if (r == i) continue;
                for (int c = 0, tc = 0; c < n; c++) {
                    if (c == j) continue;
                    temp[tr][tc++] = matrix[r][c];
                }
                tr++;
            }
            adj[j][i] = mod(((i + j) % 2 == 0 ? 1 : -1) * determinant(temp, n - 1), 26);
        }
    return adj;
}

vector<vector<int>> inverse(const vector<vector<int>> &matrix, int n) {
    int det = determinant(matrix, n);
    int detInv = modInverse(det, 26);
    if (detInv == -1) throw runtime_error("Matrix is not invertible.");

    vector<vector<int>> adj = adjoint(matrix, n);
    vector<vector<int>> inv(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inv[i][j] = mod(adj[i][j] * detInv, 26);
    return inv;
}

string hillEncrypt(const string &plaintext, const string &key, int n) {
    vector<vector<int>> keyMatrix = getKeyMatrix(key, n);
    string pt = plaintext;
    pt.erase(remove(pt.begin(), pt.end(), ' '), pt.end());
    while (pt.length() % n != 0) pt += 'x';

    string ct;
    for (size_t i = 0; i < pt.length(); i += n) {
        vector<int> block(n);
        for (int j = 0; j < n; j++) block[j] = pt[i + j] - 'a';
        for (int r = 0; r < n; r++) {
            int val = 0;
            for (int c = 0; c < n; c++) val += keyMatrix[r][c] * block[c];
            ct += (val % 26) + 'a';
        }
    }
    return ct;
}

string hillDecrypt(const string &ciphertext, const string &key, int n) {
    vector<vector<int>> keyMatrix = getKeyMatrix(key, n);
    vector<vector<int>> invMatrix = inverse(keyMatrix, n);
    string pt;

    for (size_t i = 0; i < ciphertext.length(); i += n) {
        vector<int> block(n);
        for (int j = 0; j < n; j++) block[j] = ciphertext[i + j] - 'a';
        for (int r = 0; r < n; r++) {
            int val = 0;
            for (int c = 0; c < n; c++) val += invMatrix[r][c] * block[c];
            pt += (val % 26) + 'a';
        }
    }
    return pt;
}
