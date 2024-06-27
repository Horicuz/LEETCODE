#include <bits/stdc++.h>

using namespace std;

double minimumAverage(vector<int> &nums)
{
    int n = nums.size();
    cout << n << endl;

    double avg;
    double min_double = 100;

    for (int i = 0; i < n / 2; i++)
    {
        int max = 0;
        int min = 51;
        auto max_ptr = nums.begin();
        auto min_ptr = nums.begin();

        int size = nums.size();
        for (int j = 0; j < size; j++)
        {
            if (nums[j] > max)
            {
                max = nums[j];
                max_ptr += j;
            }
            if (nums[j] < min)
            {
                min = nums[j];
                min_ptr += j;
            }
        }
        avg = (max + min) / 2;
        if (avg < min_double)
        {
            min_double = avg;
        }
        nums.erase(max_ptr);
        nums.erase(min_ptr);
    }

    return avg;
}

int main()
{
    // nums = [7,8,3,4,15,13,4,1]
    vector<int> nums = {7, 8, 3, 4, 15, 13, 4, 1};
    cout << minimumAverage(nums) << endl;
    return 0;
}