#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    //void DFS(int node, long long& cnt, int** adjl, int*& vis)
    void DFS(int node, long long& cnt, vector<vector<int>> adjl, vector<int>& vis)
    {
        vis[node] = 1;
        ++cnt;
        //cout << node << "  ";
        //for (int i = 0; adjl[node][i] != -1; ++i)
        for (int i = 0; i < adjl[node].size(); ++i)
        {
            if (vis[adjl[node][i]] == 0)
                DFS(adjl[node][i], cnt, adjl, vis);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges)
    {
        //Making adjacency list
        /*
        int a = n + 1, b = n + 1;
        int** adj = new int* [a];
        for (int i = 0; i < a; ++i)
        {
            adj[i] = new int[b];
            for (int j = 0; j < b; ++j)
                adj[i][j] = -1;
        }

        for (int i = 0; i < edges.size(); ++i)
        {
            for (int j = 0; ; ++j)
            {
                if (adj[edges[i][0]][j] == -1)
                {
                    adj[edges[i][0]][j] = edges[i][1];
                    break;
                }
            }
            for (int j = 0; ; ++j)
            {
                if (adj[edges[i][1]][j] == -1)
                {
                    adj[edges[i][1]][j] = edges[i][0];
                    break;
                }
            }
        }
        */
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); ++i)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        //Doing rest
        long long ans = ((long long)n * (n - 1)) / 2;
        //int* vis = new int[n];
        //for (int i = 0; i < n; ++i)
        //    vis[i] = 0;
        vector<int> vis(n, 0);

        for (int i = 0; i < n; ++i)
        {
            long long count = 0;
            if (vis[i] == 0)
            {
                //cout << "\nDFS: ";
                DFS(i, count, adj, vis);
                ans -= (count * (count - 1)) / 2;
            }
        }
        return ans;
    }
};

int main()
{
    int n = 7;
    vector<vector<int>> vec = { {0, 2},{0, 5},{2, 4},{1, 6},{5, 4} };
    Solution obj;

    long long count = obj.countPairs(n, vec);

    cout << endl << count << endl;

}