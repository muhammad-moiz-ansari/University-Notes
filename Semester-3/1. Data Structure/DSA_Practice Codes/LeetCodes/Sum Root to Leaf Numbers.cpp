#include <iostream>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inorder(TreeNode* r, bool& first, bool& b, long int& sum, int& num)
    {
        if (!r)
            return;

        if (r->val >= 0 && (((r->left && r->left->val < 0) && (r->right && r->right->val < 0)) || (!r->left && (r->right && r->right->val < 0)) || ((r->left && r->left->val < 0) && !r->right)))
            r->val = -1;

        if (first && r->val >= 0)
        {
            num *= 10;
            num += r->val;
        }
        else
            first = 1;

        if (!r->left && !r->right && r->val >= 0)
        {
            r->val = -1;
            b = 0;
        }

        if (b)
            inorder(r->left, first, b, sum, num);
        if (b)
            inorder(r->right, first, b, sum, num);
        if (r->val >= 0 && (((r->left && r->left->val < 0) && (r->right && r->right->val < 0)) || (!r->left && (r->right && r->right->val < 0)) || ((r->left && r->left->val < 0) && !r->right)))
            r->val = -1;
    }
    int sumNumbers(TreeNode* root)
    {
        if (!root)
            return 0;
        long int sum = 0;
        int num;
        bool b = 0, first;
        while (!b)
        {
            b = 1;
            first = 0;
            num = root->val;
            inorder(root, first, b, sum, num);
            if (!b)
                sum += num;
        }
        return sum;
    }
};

// Helper function to create a tree from a vector
TreeNode* createTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1)
        return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main()
{
    Solution solution;

    // Example 2
    vector<int> tree2 = { 4, 9, 0, 5, 1 };
    TreeNode* root2 = createTree(tree2);
    cout << "Sum of Root to Leaf Numbers (Example 2): " << solution.sumNumbers(root2) << endl;

    // Example 1
    vector<int> tree1 = { 1, 2, 3 };
    TreeNode* root1 = createTree(tree1);
    cout << "Sum of Root to Leaf Numbers (Example 1): " << solution.sumNumbers(root1) << endl;

    // Custom Example
    vector<int> tree3 = { 50, -1, 54, 98, 6, -1, -1, -1, 34 };
    TreeNode* root3 = createTree(tree3);
    cout << "Sum of Root to Leaf Numbers (Custom Example): " << solution.sumNumbers(root3) << endl;

    return 0;
}
