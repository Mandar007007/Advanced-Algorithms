#include <vector>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int left, int right)
{
    // Finding random element in range [left, right]
    int random_number = left + (rand() % (right - left + 1));

    // Swap random element with the last element so we can apply our simple quicksort
    swap(arr[random_number], arr[right]);

    // Normal quicksort
    int i = left - 1, x = arr[right];
    for (int j = left; j <= right - 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void randomized_quick_sort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        // Finding pivot element
        int pivotIndex = partition(arr, left, right);

        // D&C
        randomized_quick_sort(arr, left, pivotIndex - 1);
        randomized_quick_sort(arr, pivotIndex + 1, right);
    }
}

int main()
{
    // Generate random number every time
    srand((unsigned)time(NULL));

    // Given array
    vector<int> arr = {1, 2, 4, 1, 5, 4, 7, 5, 9, 4};
    int n = arr.size();
    cout << "Original Array: ";
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    // Sorting the array using ranomized quicksort algorithm
    randomized_quick_sort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
