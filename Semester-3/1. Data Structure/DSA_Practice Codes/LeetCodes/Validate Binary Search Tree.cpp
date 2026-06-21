#include <iostream>
//#include "Basic Codes/BinaryTree.cpp";
#include "D:\Documents\Semester-3\1. Data Structure\DSA_Practice Codes\Basic Codes\BinaryTree.cpp"
#include "D:\Documents\Semester-3\1. Data Structure\DSA_Practice Codes\Basic Codes\BST.cpp"
#include "D:\Documents\Semester-3\1. Data Structure\DSA_Practice Codes\Basic Codes\Sorting.cpp"
#include <algorithm>
#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //Wrong solution old
    /*void check(Node<int>* root, bool& b)
    {
        if (!root)
            return;

        if (root->left && root->left->val >= root->val)
        {
            b = 0;
            return;
        }
        if (root->right && root->right->val <= root->val)
        {
            b = 0;
            return;
        }
        check(root->left, b);
        check(root->right, b);
    }
    bool isValidBST(Node<int>* root)
    {
        bool b = 1;
        check(root, b);
        return b;
    }*/

   /* bool isequal(int* arr1, int* arr2, int size)
    {
        for (int i = 0; i < size; ++i)
            if (arr1[i] != arr2[i])
                return 0;
        return 1;
    }
    void make_array(NodeT<int>* root, int*& arr1, int*& arr2, int& ind)
    {
        if (!root)
            return;

        make_array(root->left, arr1, arr2, ind);
        arr1[ind] = root->data;
        arr2[ind++] = root->data;
        make_array(root->right, arr1, arr2, ind);
    }
    bool isValidBST(NodeT<int>* root)
    {
        int* arr1 = new int[100], * arr2 = new int[100], ind = 0;

        make_array(root, arr1, arr2, ind);

        bubblesort(arr2, ind);

        if (isequal(arr1, arr2, ind))
            return 1;
        else
            return 0;
    }*/

    //////////////////////////////  Solution by Vectors  //////////////////////////////

    //void make_array(NodeT<int>* root, vector<int>& arr1, vector<int>& arr2)
    //{
    //    if (!root)
    //        return;
    //
    //    make_array(root->left, arr1, arr2);
    //    arr1.push_back(root->data);
    //    arr2.push_back(root->data);
    //    make_array(root->right, arr1, arr2);
    //}
    //bool isValidBST(NodeT<int>* root)
    //{
    //    if ((!root) || (root && !root->left && !root->right))
    //        return 1;
    //
    //    vector<int> arr1, arr2;
    //    make_array(root, arr1, arr2);
    //    sort(arr2.begin(), arr2.end());
    //
    //    for (int i = 0; i < arr2.size() - 1; ++i)
    //    {
    //        if (arr2[i] == arr2[i + 1])
    //            return 0;
    //    }
    //    
    //    return arr1 == arr2 ? 1 : 0;
    //}

    //////////////////////////////  Recursion  //////////////////////////////

    bool isValidBST(NodeT<int>* root, long minVal = LONG_MIN, long maxVal = LONG_MAX)
    {
        if (!root)
            return true;
        if (root->data <= minVal || root->data >= maxVal)
            return false;
        return isValidBST(root->left, minVal, root->data) && isValidBST(root->right, root->data, maxVal);
    }
};

int main()
{
    Solution sol;

    BST<int> bst;
    bst.insert(1);
    bst.insert(4);
    bst.insert(7);
    bst.insert(0);
    bst.insert(2);
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.printin();

    Tree<int> tree;
    tree.insert(5);
    tree.insert(1);
    tree.insert(4);
    tree.root->right->left = new NodeT<int>(3);
    tree.root->right->right = new NodeT<int>(6);
    tree.printin();

    cout << "Is valid: " << sol.isValidBST(tree.root) << endl;

    ///////////////////////////////////////////////////

    Tree<int> tree2;
    tree2.insert(2);
    tree2.insert(1);
    tree2.insert(4);
    tree2.root->right->left = new NodeT<int>(3);
    tree2.root->right->right = new NodeT<int>(6);
    tree2.printin();

    cout << "Is valid: " << sol.isValidBST(tree2.root) << endl;

    return 0;
}