#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    //string removeStars(string s)
    //{
    //    string res;
    //    stack<char> st;
    //    int ind = s.size() - 1, scount = 0;
    //    while (ind >= 0)
    //    {
    //        if (s[ind] == '*')
    //            ++scount;
    //        else
    //        {
    //            if (scount > 0)
    //                --scount;
    //            else
    //                res.push_back(s[ind]);
    //        }
    //        --ind;
    //    }
    //    reverse(res.begin(), res.end());
    //    return res;
    //}
    
    /*string removeStars(string s)
    {
        string res;
        stack<char> st;
        stack<char> rst;
        int ind = s.size() - 1, scount = 0;
        while (ind >= 0)
        {
            if (s[ind] == '*')
                ++scount;
            else
            {
                if (scount > 0)
                    --scount;
                else
                    rst.push(s[ind]);
            }
            --ind;
        }
        while (!rst.empty())
        {
            res.push_back(rst.top());
            rst.pop();
        }
        return res;
    }*/

    string removeStars(string s)
    {
        string c = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
                c.pop_back();
            else
                c += s[i];
        }
        return c;
    }
};

int main()
{
    Solution sol;

    string s1 = "abb*cdfg*****x*";
    cout << sol.removeStars(s1);

	return 0;
}