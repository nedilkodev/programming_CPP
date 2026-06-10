#include <iostream>
#include <string>
using namespace std;

// 5
template <typename T>
void areEqual(T x, T y)
{
    if (x == y)
    {
        cout << "X and Y are equal!" << endl;
    }
    else
    {
        cout << "They r not equal!" << endl;
    }
}

// 10
template <typename T>
int findMaxIndex(const T arr[], int size)
{
    if (size <= 0)
        return 0;

    int maxIndex = 0;
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex + 1;
}

int main()
{
    areEqual(10, 10);
    areEqual("hello", "world!");

    double arr[] = {2.5, 3.1, 7.8, 1.4};
    cout << findMaxIndex(arr, 4); // Виведе: 3

    return 0;
}