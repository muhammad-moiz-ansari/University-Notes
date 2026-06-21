#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis)
    {
        vis[node] = 1;

        for (int i = 0; i < adj[node].size(); ++i)
        {
            if (vis[adj[node][i]] == 0)
                dfs(adj[node][i], adj, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);

        //Adjacency list:
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (isConnected[i][j])
                {
                    for (int k = 0; k < n; ++k)
                        if (isConnected[i][k] == 1 && j != k)
                            adj[j].push_back(k);
                }
            }
        }

        //Check:
        int count = 0;
        for (int i = 0; i < n; ++i)
        {
            if (vis[i] == 0)
            {
                ++count;
                dfs(i, adj, vis);
            }
        }
        return count;
    }
};

int main()
{
    Solution obj;

    int count = 0;
    //int n = 3;
    vector<vector<int>> vec = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

    count = obj.findCircleNum(vec);

    cout << "Result: " << count << endl;

    return 0;
}