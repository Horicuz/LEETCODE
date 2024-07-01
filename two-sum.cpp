#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{

    int a = nums.size();
    for (int i = 0; i < a; i++)
    {
        int diff = target - nums[i];
        if (seen[diff] != -1)
        {

            return {seen[diff], i};
        }
        else
            seen[nums[i]] = i;
    }

    return {1, 1};
}

int main()
{
    // Input: nums = [2,7,11,15], target = 9
    // Output: [0,1]

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}