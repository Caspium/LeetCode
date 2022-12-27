#include <string>
#include <iostream>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int mult = 1;
        int out = 0;
        bool char_encounter = false;
        for (int i = 0; i < s.length(); i++)
        {
            if (char_encounter && !('0' <= s[i] && s[i] <= '9'))
                return out;
            if (s[i] == ' ')
                continue;
            if (s[i] == '+')
            {
                char_encounter = true;
                continue;
            }
            else if (s[i] == '-')
            {
                mult = -1;
                char_encounter = true;
                continue;
            }
            else if ('0' <= s[i] && s[i] <= '9')
            {
                char_encounter = true;
                if (out > INT_MAX / 10)
                    return INT_MAX;
                else if (out < INT_MIN / 10)
                    return INT_MIN;
                out *= 10;
                if (out > INT_MAX - (s[i] - '0'))
                    return INT_MAX;
                else if (out < INT_MIN + (s[i] - '0'))
                    return INT_MIN;
                out += (s[i] - '0') * mult;
            }
            else
                break;
        }
        return out;
    }
};

int main()
{
    Solution s;
    string x = "-38";
    int result = s.myAtoi(x);
    cout << result << endl;
    return 0;
}