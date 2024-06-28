#include <bits/stdc++.h>

using namespace std;

double minimumAverage(vector<int> &nums)
{
    int n = nums.size();

    double avg;
    double min_double = 100.00;

    for (int i = 0; i < n / 2; i++)
    {
        double max = 0;
        double min = 51;
        int max_index;
        int min_index;

        int size = nums.size();
        for (int j = 0; j < size; j++)
        {
            if (nums[j] >= max)
            {
                max = nums[j];
                max_index = j;
            }
            if (nums[j] < min)
            {
                min = nums[j];
                min_index = j;
            }
        }

        cout << "max: " << max << " min: " << min << endl;
        avg = (max + min) / 2;

        if (avg < min_double)
        {
            min_double = avg;
        }

        if (max_index > min_index)
        {
            nums.erase(nums.begin() + max_index);
            nums.erase(nums.begin() + min_index);
        }
        else
        {
            nums.erase(nums.begin() + min_index);
            nums.erase(nums.begin() + max_index);
        }
    }

    return min_double;
}

int main()
{
    // =[1,9,8,3,10,5]
    vector<int> nums = {1, 9, 8, 3, 10, 5};
    cout << minimumAverage(nums) << endl;
    return 0;
}