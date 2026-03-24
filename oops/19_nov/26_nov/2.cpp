// create a high precision stop watch and use it to measure time for different sorting algorithms like inserion ,selection ,bubble and quick sort
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
void insertionSort(vector<int> &arr)
{
    for (size_t i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void selectionSort(vector<int> &arr)
{
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        size_t minIdx = i;
        for (size_t j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}
void bubbleSort(vector<int> &arr)
{
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        for (size_t j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main()
{
    vector<int> data = {64, 34, 25, 12, 22, 11, 90, 88, 76, 45, 23, 67, 89, 54, 32};
    vector<int> arr;
    // Insertion Sort
    arr = data;
    auto start = chrono::high_resolution_clock::now();
    insertionSort(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> insertionSortDuration = end - start;
    cout << "Insertion Sort Time: " << insertionSortDuration.count() << " ms\n"; // Selection Sort
    arr = data;
    start = chrono::high_resolution_clock::now();
    selectionSort(arr);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> selectionSortDuration = end - start;
    cout << "Selection Sort Time: " << selectionSortDuration.count() << " ms\n"; // Bubble Sort
    arr = data;
    start = chrono::high_resolution_clock::now();
    bubbleSort(arr);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> bubbleSortDuration = end - start;
    cout << "Bubble Sort Time: " << bubbleSortDuration.count() << " ms\n";
    // Quick Sort using STL
    arr = data;
    start = chrono::high_resolution_clock::now();
    sort(arr.begin(), arr.end());
    end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> quickSortDuration = end - start;
    cout << "Quick Sort (STL) Time: " << quickSortDuration.count() << " ms\n";
    return 0;
}