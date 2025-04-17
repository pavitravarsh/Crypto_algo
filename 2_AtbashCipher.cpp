
#include <string>
using namespace std;

string atbashCipher(const string &input)
{
    string result;
    for (char c : input)
    {
        if (isalpha(c))
        {
            char base = islower(c) ? 'a' : 'A';
            result += static_cast<char>(base + 25 - (c - base));
        }
        else
        {
            result += c;
        }
    }
    return result;
}
