#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
int partition(int arr[], int beg, int end)
{
    int pivot = arr[end];
    int i = (beg - 1);

    for (int j = beg; j <= end - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            int x = arr[i];
            arr[i] = arr[j];
            arr[j] = x;
        }
    }
    int x = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = x;
    return (i + 1);
}

void quicksort(int arr[], int beg, int end)
{
    if (beg < end)
    {

        int p = partition(arr, beg, end);
        quicksort(arr, beg, p - 1);
        quicksort(arr, p + 1, end);
    }
}

int main()
{
    int *ptr, size;
    cout << "Enter the size of array" << endl;
    cin >> size;
    ptr = new int[size];
    cout << "Enter elements of array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> ptr[i];
    }
    cout << "Array before sorting:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << "\t";
    }
    auto start = high_resolution_clock::now();
    quicksort(ptr, 0, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl
         << "Array after sorting:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << "\t";
    }
    cout << endl
         << "Time taken : "
         << duration.count() << " microseconds" << endl;
    return 0;
}