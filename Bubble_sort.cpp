#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
void bubble_sort(int arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        for (int j=0;j<size-i;j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int *ptr, size;
    cout<<"Enter the size of array"<<endl;
    cin>>size;
    ptr = new int[size];
    cout<<"Enter elements of array"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>ptr[i];
    }
    cout<<"Array before sorting:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<ptr[i]<< "\t";
    }
    auto start = high_resolution_clock::now();
    bubble_sort(ptr, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout <<"Array after sorting:"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << "\t";
    }
    cout << endl
         << "Time taken : "
         << duration.count() << " microseconds" << endl;
    return 0;
}