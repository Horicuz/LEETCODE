#include <bits/stdc++.h>

using namespace std;

// dfs using a list of adiacency

// find the numberf of connected components using dfs using a list of adiacency

void dfs(vector<vector<int>> &matrix, int node, vector<bool> &visited, int type)
{
    visited[node] = true;
    size_t j = matrix[node].size();
    if (type == 5)
    {
        for (size_t i = 0; i < j; i++)
        {
            if (matrix[node][i] >= 4 && matrix[node][i] != type && !visited[i])
            {
                dfs(matrix, i, visited, type);
            }
        }
    }
    else
    {
        for (size_t i = 0; i < j; i++)
        {
            if (matrix[node][i] != 0 && matrix[node][i] != type && !visited[i])
            {
                dfs(matrix, i, visited, type);
            }
        }
    }
}

int findConnectedComponents(vector<vector<int>> &matrix, int type)
{
    long unsigned int n = matrix.size();
    vector<bool> visited(n, false);
    int components = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(matrix, i, visited, type);
            components++;
        }
    }

    return components;
}

int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
{
    bool Alice, Bob;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int size = edges.size();
    // sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b)
    //      { return a[0] < b[0]; });

    for (int i = 0; i < size; i++)
    {
        matrix[edges[i][1] - 1][edges[i][2] - 1] += edges[i][0] + 1;
        matrix[edges[i][2] - 1][edges[i][1] - 1] += edges[i][0] + 1;
    }

    Alice = (findConnectedComponents(matrix, 3) == 1);
    Bob = (findConnectedComponents(matrix, 2) == 1);

    if (Alice == false || Bob == false)
    {
        return -1;
    }
    else
    {
        int nrofislands = findConnectedComponents(matrix, 5);
        return (size - (n + nrofislands - 2));
    }
}

int main()
{
    // n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
    vector<vector<int>> edges = {{3, 1, 2}, {3, 2, 3}, {1, 1, 3}, {1, 2, 4}, {1, 1, 2}, {2, 3, 4}};
    cout << maxNumEdgesToRemove(4, edges) << endl;
    return 0;
}