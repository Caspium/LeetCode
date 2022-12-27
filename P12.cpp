#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string out = "";
        while (num > 0)
        {
            if (num >= 1000)
            {
                out += "M";
                num -= 1000;
            }
            else if (num >= 900)
            {
                out += "CM";
                num -= 900;
            }
            else if (num >= 500)
            {
                out += "D";
                num -= 500;
            }
            else if (num >= 400)
            {
                out += "CD";
                num -= 400;
            }
            else if (num >= 100)
            {
                out += "C";
                num -= 100;
            }
            else if (num >= 90)
            {
                out += "XC";
                num -= 90;
            }
            else if (num >= 50)
            {
                out += "L";
                num -= 50;
            }
            else if (num >= 40)
            {
                out += "XL";
                num -= 40;
            }
            else if (num >= 10)
            {
                out += "X";
                num -= 10;
            }
            else if (num >= 9)
            {
                out += "IX";
                num -= 9;
            }
            else if (num >= 5)
            {
                out += "V";
                num -= 5;
            }
            else if (num >= 4)
            {
                out += "IV";
                num -= 4;
            }
            else if (num >= 1)
            {
                out += "I";
                num -= 1;
            }
        }
        return out;
    }
};

int main()
{
    Solution s;
    int x = 123;
    string result = s.intToRoman(x);
    cout << result << endl;
    return 0;
}