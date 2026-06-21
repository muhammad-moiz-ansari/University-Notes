#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;


    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        if (asteroids.empty())
            return asteroids;

        vector<int> result;
        stack<int> st, rst;
        for (int i = 0; i < asteroids.size(); ++i)
            st.push(asteroids[i]);

        int a, b, c;
        bool pusha = 1, pushb = 1, popc1 = 0, popc2 = 0, pushc = 0;
        while (!st.empty())
        {
            if (pusha)
            {
                a = st.top();
                st.pop();
                if (st.empty())
                {
                    rst.push(a);
                    //if (pushb)
                    //    rst.push(b);//////
                    break;
                }
            }
            if (pushb)
            {
                b = st.top();
                st.pop();
            }
            popc2 = popc1;
            popc1 = 0;
            //pushc = 0;
            if ((a < 0 && b < 0) || (a > 0 && b > 0) || (a > 0 && b < 0))
            {
                pusha = 1;
                if (!st.empty())
                { 
                    pushc = 0;
                    c = st.top();
                    if ((a < 0 && c < 0) || (a > 0 && c > 0) || (a > 0 && c < 0))
                    {

                    }
                    else if (abs(a) == abs(c))
                    {
                        if(!(c > 0 && b < 0 && abs(b) > c))
                            pusha = 0;
                        //st.pop();
                        popc1 = 1;
                        pushc = 1;
                    }
                    else if (abs(a) > abs(c))
                    {
                        pusha = 1;
                        //st.pop();
                        popc1 = 1;
                    }
                    else
                    {
                        pusha = 0;
                    }
                    c = a;
                }
                
                if (pusha)
                    rst.push(a);
                a = b;
                pusha = 0;
                pushb = 1;
                if (st.empty())
                    rst.push(b);
            }
            else if (abs(a) == abs(b))
            {
                pusha = 1;
                pushb = 1;
                if (pushc)
                {
                    st.push(c);
                }
            }
            else if (abs(a) > abs(b))
            {
                st.push(a);
                pusha = 1;
                pushb = 1;
            }
            else
            {
                if (!popc2)
                    st.push(b);
                pusha = 1;
                pushb = 1;
            }
        }
        while (!rst.empty())
        {
            result.push_back(rst.top());
            rst.pop();
        }
        return result;
    }

int main()
{
    //vector<int>vec1 = { 5, 10, -5 };
    //vector<int>vec1 = { 5, -5 };
    vector<int>vec1 = { -2, 2, -1, -2 };
    vector<int>res = asteroidCollision(vec1);

    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << "  ";
    cout << endl;

    ///////////////////////////////////////

    vector<int>vec2 = { -2, 1, -1, -1 };
    vector<int>res2 = asteroidCollision(vec2);

    for (int i = 0; i < res2.size(); ++i)
        cout << res2[i] << "  ";
    cout << endl;

    ///////////////////////////////////////

    vector<int>vec3 = { -2, 2, -1, -3 };
    vector<int>res3 = asteroidCollision(vec3);

    for (int i = 0; i < res3.size(); ++i)
        cout << res3[i] << "  ";
    cout << endl;

    ///////////////////////////////////////

    vector<int>vec4 = { -2, 2, -2, -3 };
    vector<int>res4 = asteroidCollision(vec4);

    for (int i = 0; i < res4.size(); ++i)
        cout << res4[i] << "  ";
    cout << endl;

    ///////////////////////////////////////



    return 0;
}