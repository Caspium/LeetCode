#include <iostream>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int out = 0;
        // if x is negative, reverse it and then reverse the result
        if (x < 0)
            // if x is INT_MIN, return 0
            if (x == INT_MIN)
                return 0;
            else
                out = -1 * reverse(-1 * x);
        else
        {
            while (x != 0)
            {
                out += x % 10;
                x /= 10;
                if (x != 0)
                {
                    // if out is greater than INT_MAX / 10, return 0
                    if (out > INT_MAX / 10)
                        return 0;
                    out *= 10;
                }
            }
        }
        return out;
    }
};

int main()
{
    Solution s;
    int x = 123;
    int result = s.reverse(x);
    cout << result << endl;
    return 0;
}