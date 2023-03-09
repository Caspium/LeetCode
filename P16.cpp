#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int sum = 0;
        int closest_sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // if the current number is greater than target, break
            if (nums[i] > target)
                break;
            sum = 0;
            // if the current number is the same as the previous one, skip
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // set the left and right pointers
            int left = i + 1;
            int right = nums.size() - 1;
            // while the left pointer is less than the right pointer
            while (left < right)
            {
                sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < abs(closest_sum - target))
                    closest_sum = sum;

                // if the sum is less than 0, move the left pointer to the right
                else if (nums[i] + nums[left] + nums[right] < target)
                {
                    sum = nums[i] + nums[left] + nums[right];
                    if (i == 0 && left == 1 && right == 2)
                        closest_sum = sum;
                    else if (abs(target - sum) < abs(target - closest_sum))
                        closest_sum = sum;
                    left++;
                    // if the left pointer is the same as the previous one, move it to the right
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                }
                // if the sum is greater than 0, move the right pointer to the left
                else
                {
                    sum = nums[i] + nums[left] + nums[right];
                    if (i == 0 && left == 1 && right == 2)
                        closest_sum = sum;
                    else if (abs(target - sum) < abs(target - closest_sum))
                        closest_sum = sum;
                    right--;
                    // if the right pointer is the same as the previous one, move it to the left
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = s.threeSumClosest(nums, target);
    cout << result << endl;
    return 0;
}