#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j)
        {
            max_area = max(max_area, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return max_area;
    }
};

int main()
{
    Solution s;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = s.maxArea(height);
    cout << result << endl;
    return 0;
}