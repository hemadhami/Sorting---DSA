#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;
void insertionsort(int arr[], int size)
{
    int temp, j, i;
    for (i = 1; i < size; i++)
    {
        int i, j, temp;
        for (i = 1; i < size; i++)
        {
            temp = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = temp;
        }
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
    insertionsort(ptr, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"Array after sorting:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << "\t";
    }
    cout << endl
         << "Time taken : "
         << duration.count() << " microseconds" << endl;

    return 0;
}