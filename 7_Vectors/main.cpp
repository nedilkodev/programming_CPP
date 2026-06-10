#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Друге завдання
// 5
void findAndPrintMax(const vector<int> &vec)
{
    if (vec.empty())
        return;
    int maxVal = vec[0];
    for (int i = 1; i < vec.size(); ++i)
    {
        if (vec[i] > maxVal)
        {
            maxVal = vec[i];
        }
    }
    cout << "Max value in vector: " << maxVal << endl;
}

// 6
vector<int> filterLessThanAverage(const vector<int> &vec)
{
    vector<int> filteredVec;
    if (vec.empty())
        return filteredVec;

    double sum = 0;
    for (int i = 0; i < vec.size(); ++i)
    {
        sum += vec[i];
    }

    double avg = sum / vec.size();

    for (int i = 0; i < vec.size(); ++i)
    {
        if (vec[i] < avg)
        {
            filteredVec.push_back(vec[i]);
        }
    }
    return filteredVec;
}

// Перше завдання

int main()
{
    vector<int> myvector;
    int myint;

    cout << "Please enter some integers (enter 0 to end):\n";

    for (int i = 0; i < 5; ++i)
    {
        cin >> myint;
        myvector.push_back(myint);
    }

    cout << "myvector stores " << int(myvector.size()) << " numbers.\n";

    for (int i = 0; i < myvector.size(); ++i)
    {
        cout << ' ' << myvector.at(i);
    }

    cout << endl;

    myvector.pop_back();

    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    {
        cout << ' ' << *it;
    }

    cout << endl
         << "First element of vector: " << myvector.front() << endl;
    cout << "Last element of vector: " << myvector.back() << endl;

    cout << "Sorted vector: ";

    sort(myvector.begin(), myvector.end());

    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    {
        cout << ' ' << *it;
    }

    cout << endl
         << "Vector`s size: " << myvector.size() << endl;

    findAndPrintMax(myvector);

    vector<int> lessThanAvgVector = filterLessThanAverage(myvector);
    cout << "Elements less than average:";
    for (int i = 0; i < lessThanAvgVector.size(); ++i)
    {
        cout << ' ' << lessThanAvgVector[i];
    }

    int searchNumber;
    cout << "Look for ur number: ";
    cin >> searchNumber;

    bool foundNumber = false;
    for (int i = 0; i < myvector.size(); ++i)
    {
        if (myvector.at(i) == searchNumber)
        {
            foundNumber = true;
            break;
        }
    }

    if (foundNumber == true)
    {
        cout << "Ur number " << searchNumber << " was found" << endl;
    }
    else
    {
        cout << "Ur number wasn`t found" << endl;
    }

    myvector.clear();

    return 0;
}