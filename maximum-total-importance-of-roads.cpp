#include <bits/stdc++.h>

using namespace std;

long long maximumImportance(int n, vector<vector<int>> &roads)
{
    vector<long long> importance(n, 0);
    int size = roads.size();
    for (int i = 0; i < size; i++)
    {
        importance[roads[i][0]]++;
        importance[roads[i][1]]++;
    }

    long long max_importance = 0;
    sort(importance.begin(), importance.end());

    for (int i = 1; i <= n; i++)
    {
        max_importance += i * importance[i - 1];
    }
    return max_importance;
}

int main()
{
    // n = 5, roads = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
    vector<vector<int>> roads = {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}};
    cout << maximumImportance(5, roads) << endl;
    return 0;
}
