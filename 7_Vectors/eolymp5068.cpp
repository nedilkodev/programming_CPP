#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a;
    vector<int> b;
    char c;

    while (cin.get(c) && c != '\n')
    {
        if (c >= '0' && c <= '9')
        {
            a.push_back(c - '0');
        }
    }

    while (cin.get(c) && c != '\n')
    {
        if (c >= '0' && c <= '9')
        {
            b.push_back(c - '0');
        }
    }

    if (a.size() > b.size())
    {
        cout << ">" << endl;
    }
    else if (a.size() < b.size())
    {
        cout << "<" << endl;
    }
    else
    {
        bool areEqual = true;
        for (size_t i = 0; i < a.size(); ++i)
        {
            if (a[i] > b[i])
            {
                cout << ">" << endl;
                areEqual = false;
                break;
            }
            else if (a[i] < b[i])
            {
                cout << "<" << endl;
                areEqual = false;
                break;
            }
        }

        if (areEqual)
        {
            cout << "=" << endl;
        }
    }

    return 0;
}