#include <iostream>
using namespace std;

int main()
{
    int num;
    bool p = 1;
    cout << "Enter num: ";
    cin >> num;

    if (num <= 1)
    {
        p = 0;
    }
    else if (num == 2)
    {
        p = 1;
    }
    else
    {
        for (int i = 2; i < num; ++i)
        {
            if (num % i == 0)
            {
                p = 0;
                break;
            }
            else
            {
                p = 1;
            }
        }
    }
    cout << "Is prime number? " << p << endl;

    return 0;
}