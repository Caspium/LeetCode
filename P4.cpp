#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // find the shorter vector
        vector<int> combined;

        while ((nums1.size() > 0) && (nums2.size() > 0))
        {
            if (nums1.at(0) < nums2.at(0))
            {
                combined.push_back(nums1.at(0));
                nums1.erase(nums1.begin());
            }
            else
            {
                combined.push_back(nums2.at(0));
                nums2.erase(nums2.begin());
            }
        }

        // add the rest of the longer vector to the combined vector
        if (nums1.size() > 0)
        {
            for (int i = 0; i < nums1.size(); i++)
            {
                combined.push_back(nums1.at(i));
            }
        }
        else
        {
            for (int i = 0; i < nums2.size(); i++)
            {
                combined.push_back(nums2.at(i));
            }
        }

        // find the median
        // if the combined vector has an odd number of elements
        if (combined.size() % 2)
        {
            return combined.at(combined.size() / 2);
        }
        // if the combined vector has an even number of elements
        else
        {
            return (combined.at(combined.size() / 2) + combined.at((combined.size() / 2) - 1)) / 2.0;
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4, 5};
    double result = s.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;
    return 0;
}