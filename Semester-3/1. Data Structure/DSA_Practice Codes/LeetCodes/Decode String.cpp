#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    string decodeString(string s)
    {
        int ind = 0, n = 0, ncount = 0, brcount = 0, instart = 0, incount = 0;
        string incode, res;
        while (ind < s.size())
        {
            if (brcount > 0)
            {
                if (s[ind] == '[')
                    ++brcount;
                else if (s[ind] == ']')
                {
                    --brcount;
                    if (brcount == 0)
                    {
                        incode.append(s, instart, incount);
                        for (int i = 0; i < n; ++i)
                            res.append(decodeString(incode));
                        incount = -1;
                        incode = "";
                        n = 0;
                    }
                }
                ++incount;
            }
            else if (s[ind] >= '0' && s[ind] <= '9')
            {
                if (ncount > 0)
                    n *= 10;
                n += s[ind] - '0';
                ++ncount;
            }
            else if (s[ind] == '[')
            {
                ncount = 0;
                ++brcount;
                instart = ind + 1;
            }
            else
                res += s[ind];
            ++ind;
        }
        return res;
    }
};

int main()
{
    Solution sol;


    //string s1 = "3[a2[c]]";
    string s1 = "3[a]2[bc]";
    cout << sol.decodeString(s1);

    return 0;
}