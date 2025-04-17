
#include <string>
using namespace std;

string caesarEncrypt(const string &plaintext, int shift)
{
    string ciphertext;
    for (char c : plaintext)
    {
        if (isalpha(c))
        {
            char base = islower(c) ? 'a' : 'A';
            ciphertext += static_cast<char>((c - base + shift) % 26 + base);
        }
        else
        {
            ciphertext += c;
        }
    }
    return ciphertext;
}

string caesarDecrypt(const string &ciphertext, int shift)
{
    return caesarEncrypt(ciphertext, 26 - shift);
}
