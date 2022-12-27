#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";
        // the first string as the initial prefix
        string prefix = strs[0];
        // loop through the rest of the strings
        for (int i = 1; i < strs.size(); i++)
        {
            // while the prefix is not a prefix of the current string
            while (strs[i].find(prefix) != 0) // find() returns the index of the first occurrence of the prefix
            {
                // remove the last character of the prefix
                prefix = prefix.substr(0, prefix.length() - 1);
                // if the prefix is empty, return ""
                if (prefix.empty())
                    return "";
            }
        }

        return prefix;
    }
};

int main()
{
    Solution s;
    vector<string> strs = {"flo", "oflo", "whoflo"};
    string result = s.longestCommonPrefix(strs);
    cout << result << endl;
    return 0;
}