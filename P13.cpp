#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        // much cheaper than using a map
        int T[256];
        T['I'] = 1;
        T['V'] = 5;
        T['X'] = 10;
        T['L'] = 50;
        T['C'] = 100;
        T['D'] = 500;
        T['M'] = 1000;

        // last char is always added
        int sum = T[s.back()];
        // start from the second last char
        for (int i = s.length() - 2; i >= 0; --i)
        {
            // if prior char is smaller, then subtract
            if (T[s[i]] < T[s[i + 1]])
            {
                sum -= T[s[i]];
            }
            // otherwise add
            else
            {
                sum += T[s[i]];
            }
        }

        return sum;
    }
};

int main()
{
    Solution s;
    string str = "III";
    int result = s.romanToInt(str);
    cout << result << endl;
    return 0;
}