#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sort(vector<int>& arr)
    {
        int size = arr.size();
        for (int i = 0; i < size; ++i)
        {
            bool b = 0;
            for (int j = 0; j < size - i - 1; ++j)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    b = 1;
                }
            }
            if (!b)
                break;
        }
    }

    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& res, bool& b)
    {
        if (b)
            res.push_back(node);
        b = 1;
        vis[node] = 1;

        for (int i = 0; i < adj[node].size(); ++i)
        {
            if (vis[adj[node][i]] == 0)
                dfs(adj[node][i], adj, vis, res, b);
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> res(n);
        vector<vector<int>> edges2(edges.size());
        for (int i = 0; i < edges.size(); ++i)
        {
            edges2[i].push_back(edges[i][1]);
            edges2[i].push_back(edges[i][0]);
        }

        vector<int> vis(n, 0);

        //Adjacency list:
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); ++i)
        {
            adj[edges2[i][0]].push_back(edges2[i][1]);
        }

        for (int i = 0; i < n; ++i)
        {
            bool b = 0;
            dfs(i, adj, vis, res[i], b);
            for (int j = 0; j < n; ++j)
                vis[j] = 0;
            sort(res[i]);
        }

        return res;
    }
};

int main()
{
    Solution obj;

    int n = 8;
    vector<vector<int>> vec = { {0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7}, {4, 6} };

    vec = obj.getAncestors(n, vec);

    cout << "Result:\n";
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec[i].size(); ++j)
            cout << vec[i][j] << "  ";
        cout << endl;
    }
  

    return 0;
}