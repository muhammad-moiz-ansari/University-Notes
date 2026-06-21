#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution 
{
public:
    void DFS(Node* node, vector<int>& vis, vector<Node*>& clones)
    {
        if (node->val == vis.size() + 1)
            vis.push_back(1);
        else if (node->val > vis.size())
            vis.resize(node->val);
        vis[node->val - 1] = 1;


        for (int i = 0; i < node->neighbors.size(); ++i)
        {
            if (clones[node->neighbors[i]->val - 1] == NULL)
                clones[node->neighbors[i]->val - 1] = new Node(node->neighbors[i]->val);
            clones[node->val - 1]->neighbors.push_back(clones[node->neighbors[i]->val - 1]);
        }
        for (int i = 0; i < node->neighbors.size(); ++i)
        {
            if (node->neighbors[i]->val > vis.size())
                vis.resize(node->neighbors[i]->val);
            if (vis[node->neighbors[i]->val - 1] == 0)
                DFS(node->neighbors[i], vis, clones);
        }
    }

    Node* cloneGraph(Node* node)
    {
        if (node == NULL)
            return node;
        if (node->neighbors.size() == 0)
        {
            Node* newnode = new Node(node->val);
            return newnode;
        }

        vector<int> vis(1, 0);
        vector<Node*> clones(200, NULL);

        clones[0] = new Node(1);

        DFS(node, vis, clones);

        return clones[0];
    }
};


// Helper function to print the graph for verification
void printGraph(Node* node) {
    if (!node) return;

    vector<int> visited(101, 0);
    queue<Node*> q;
    q.push(node);
    visited[node->val] = 1;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << "Node " << curr->val << ": ";
        for (Node* neighbor : curr->neighbors) {
            cout << neighbor->val << " ";
            if (!visited[neighbor->val]) {
                visited[neighbor->val] = 1;
                q.push(neighbor);
            }
        }
        cout << endl;
    }
}


int main() 
{
    // Example 1
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = { node2, node4 };
    node2->neighbors = { node1, node3 };
    node3->neighbors = { node2, node4 };
    node4->neighbors = { node1, node3 };

    Solution solution;
    Node* clonedGraph1 = solution.cloneGraph(node1);

    cout << "Original Graph (Example 1):\n";
    printGraph(node1);
    cout << "\nCloned Graph (Example 1):\n";
    printGraph(clonedGraph1);

    // Example 2
    Node* singleNode = new Node(1);

    Node* clonedGraph2 = solution.cloneGraph(singleNode);

    cout << "\nOriginal Graph (Example 2):\n";
    printGraph(singleNode);
    cout << "\nCloned Graph (Example 2):\n";
    printGraph(clonedGraph2);

    // Example 3
    Node* emptyGraph = nullptr;

    Node* clonedGraph3 = solution.cloneGraph(emptyGraph);

    cout << "\nOriginal Graph (Example 3):\n";
    printGraph(emptyGraph);
    cout << "\nCloned Graph (Example 3):\n";
    printGraph(clonedGraph3);

    return 0;
}