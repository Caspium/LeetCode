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
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ' || s[i] == '+')
                continue;
            else if (s[i] == '-')
            {
                mult = -1;
                continue;
            }
            else if ('0' <= s[i] && s[i] <= '9')
            {
                if (mult * out > INT_MAX / 10)
                    return INT_MAX;
                else if (mult * out < INT_MIN / 10)
                    return INT_MIN;
                out *= 10;
                out += s[i] - '0';
            }
            else
                break;
        }
        return out * mult;
    }
};