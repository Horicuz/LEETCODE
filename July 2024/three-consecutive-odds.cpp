#include <bits/stdc++.h>

using namespace std;

bool threeConsecutiveOdds(vector<int> &arr)
{
    int a = arr.size();
    for (int i = 0; i < a - 2; i++)
    {
        if (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int a, b;
}