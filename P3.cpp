#include <string>
#include <iostream>
using namespace std;

// find the longest substring without repeating characters
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int longest_length = 0;
        // iterate through the string
        for (int i = 0; i < s.length(); i++)
        {
            string temp = "";
            // iterate through the string again
            for (int j = i; j < s.length(); j++)
            {
                // if the character is not in the temp string, add it
                if (temp.find(s[j]) == string::npos)
                {
                    temp += s[j];
                }
                else
                {
                    break;
                }
            }
            // update if the temp string is longer than the longest string
            if (temp.length() > longest_length)
            {
                longest_length = temp.length();
            }
        }
        return longest_length;
    }
};

// test
int main()
{
    Solution s;
    string str = "abcabcbb";
    int result = s.lengthOfLongestSubstring(str);
    cout << result << endl;
    return 0;
}