#include <bits/stdc++.h>

using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    int a = nums1.size();
    int b = nums2.size();
    vector<int> res;
    vector<int> hash(1001, 0);

    if (a < b)
    {
        return intersect(nums2, nums1);
    }
    else
    {
        for (int i = 0; i < a; i++)
        {
            hash[nums1[i]]++;
        }

        for (int i = 0; i < b; i++)
        {
            if (hash[nums2[i]] > 0)
            {
                res.push_back(nums2[i]);
                hash[nums2[i]]--;
            }
        }
    }

    return res;
}

int main()
{
    // Input: nums1 = [1,2,2,1], nums2 = [2,2]

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> res = intersect(nums1, nums2);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}