#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
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
    ////void make_array(TreeNode* root, int*& arr, int& ind)
    //void make_array(TreeNode* root, vector<int>& arr, int& ind)
    //{
    //    queue<TreeNode*> que;
    //    que.push(root);
    //    int i = 0, p = 1, pi = 0;
    //    bool b = 0;

    //    while (!que.empty())
    //    {
    //        TreeNode* temp = que.front();
    //        que.pop();

    //        if (i == 0 && temp == NULL)
    //            b = 1;

    //        if (temp)
    //        {
    //            if (temp->left)
    //            {
    //                que.push(temp->left);
    //                b = 0;
    //            }
    //            else
    //                que.push(NULL);
    //            if (temp->right)
    //            {
    //                que.push(temp->right);
    //                b = 0;
    //            }
    //            else
    //                que.push(temp->right);
    //            //arr[ind++] = temp->val;
    //            arr.push_back(temp->val);
    //            ++i;
    //        }
    //        else
    //        {    //arr[ind++] = -1;
    //            arr.push_back(-1);
    //            ++i;

    //            que.push(NULL);
    //            que.push(NULL);
    //        }

    //        if (i == p)
    //        {
    //            if (b)
    //                break;
    //            i = 0;
    //            p = pow(2, ++pi);
    //        }
    //    }
    //}

    //int sumEvenGrandparent(TreeNode* root)
    //{
    //    int sum = 0;
    //    TreeNode* prev = NULL;
    //    TreeNode* grand = NULL;
    //    //int* arr = new int[100];
    //    vector<int> arr;
    //    int ind = 0;
    //    make_array(root, arr, ind);

    //    //for (int i = 3; i < ind; ++i)
    //    for (int i = 3; i < arr.size(); ++i)
    //    {
    //        if (arr[i] != -1)
    //        {
    //            int grind = 0;
    //            if (i % 2 != 0)
    //                grind = i / 2;
    //            else
    //                grind = (i / 2) - 1;

    //            if (grind % 2 != 0)
    //                grind = grind / 2;
    //            else
    //                grind = (grind / 2) - 1;

    //            if (arr[grind] % 2 == 0)
    //                sum += arr[i];
    //        }
    //    }
    //    return sum;
    //}

    /*
    ///////////// Sol 1:
    int solve(TreeNode* root, int parent, int gParent) 
    {
        if (!root)
            return 0;

        // Iterate over the child with updated values of parent and grandparent.
        return solve(root->left, root->val, parent)
            + solve(root->right, root->val, parent)
            + (gParent % 2 ? 0 : root->val);
    }

    int sumEvenGrandparent(TreeNode* root) 
    {
        return solve(root, -1, -1);
    }

    //////////// Solution - 2 ////////////
    int sumEvenGrandparent(TreeNode* root, int parent = -1, int gParent = -1)
    {
        // Iterate over the child with updated values of parent and grandparent.
        return root ? solve(root->left, root->val, parent)
                    + solve(root->right, root->val, parent)
                    + (gParent % 2 ? 0 : root->val) : 0;
    }
    */

    ///////////// Solution - 3 /////////////
    int sum = 0;
    
    void dfs(TreeNode* current, TreeNode* parent, TreeNode* grandParent) 
    {
        if (current == NULL) 
            return; // base case 
        if (grandParent != NULL && grandParent->val % 2 == 0)
            sum += current->val;
        
        dfs(current->left, current, parent);// ( newChild, parent, GrandParent)
        dfs(current->right, current, parent);
    }

    int sumEvenGrandparent(TreeNode* root) 
    {
        sum = 0;
        dfs(root, NULL, NULL);
        return sum;
    }
    
};

// Helper function to create a binary tree from a vector of values
TreeNode* createTree(const vector<int>& values, int index = 0) 
{
    if (index >= values.size() || values[index] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(values[index]);
    root->left = createTree(values, 2 * index + 1);
    root->right = createTree(values, 2 * index + 2);
    return root;
}

int main() 
{
    Solution solution;

    // Test case 3
    TreeNode* root3 = new TreeNode(50, nullptr, new TreeNode(54,
        new TreeNode(98),
        new TreeNode(6, nullptr, new TreeNode(34))));
    cout << "Sum of nodes with even-valued grandparent (Example 3): "
        << solution.sumEvenGrandparent(root3) << endl;

    // Example 1
    vector<int> tree1 = { 6, 7, 8, 2, 7, 1, 3, 9, -1, 1, 4, -1, -1, -1, 5 };
    TreeNode* root1 = createTree(tree1);
    cout << "Sum of nodes with even-valued grandparent (Example 1): "
        << solution.sumEvenGrandparent(root1) << endl;

    // Example 2
    vector<int> tree2 = { 1 };
    TreeNode* root2 = createTree(tree2);
    cout << "Sum of nodes with even-valued grandparent (Example 2): "
        << solution.sumEvenGrandparent(root2) << endl;

    return 0;
}
