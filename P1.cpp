#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// find the indices of the two numbers that add up to the target
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> solution;

        // iterate through the vector
        for (int i = 0; i < nums.size(); i++)
        {
            int curr = nums.at(i);
            int want = target - curr;

            // if the number we want is in the vector
            if (find(nums.begin(), nums.end(), want) != nums.end())
            {
                // get the index of the number we want
                int index_friend = distance(nums.begin(), find(nums.begin(), nums.end(), want));

                // make sure the indices are not the same
                if (index_friend != i)
                {
                    solution.push_back(i);
                    solution.push_back(distance(nums.begin(), find(nums.begin(), nums.end(), want)));

                    break;
                }
            }
        }
        return solution;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = s.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result.at(i) << endl;
    }
    return 0;
}