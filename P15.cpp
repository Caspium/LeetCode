#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        // sort the array
        sort(nums.begin(), nums.end());
        // loop through the array
        for (int i = 0; i < nums.size(); i++)
        {
            // if the current number is greater than 0, break
            if (nums[i] > 0)
                break;
            // if the current number is the same as the previous one, skip
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // set the left and right pointers
            int left = i + 1;
            int right = nums.size() - 1;
            // while the left pointer is less than the right pointer
            while (left < right)
            {
                // if the sum of the three numbers is 0
                if (nums[i] + nums[left] + nums[right] == 0)
                {
                    // add the triplet to the result
                    result.push_back({nums[i], nums[left], nums[right]});
                    // move the left pointer to the right
                    left++;
                    // move the right pointer to the left
                    right--;
                    // if the left pointer is the same as the previous one, move it to the right
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    // if the right pointer is the same as the previous one, move it to the left
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
                // if the sum is less than 0, move the left pointer to the right
                else if (nums[i] + nums[left] + nums[right] < 0)
                    left++;
                // if the sum is greater than 0, move the right pointer to the left
                else
                    right--;
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = s.threeSum(nums);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}