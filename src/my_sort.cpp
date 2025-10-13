#include <chrono>
#include <cstdio>
#include <iostream>
#include <random>
#include <utility>

enum SortMethod
{
    BUBBLE = 0,
    SELECTION = 1,
    insertion = 2,
    QUICK = 3,
    MERGE = 4,
    HEAP = 5
};

class Timer
{
public:
    std::chrono::time_point<std::chrono::system_clock> start;

    Timer()
    {
        start = std::chrono::system_clock::now();
    }
    ~Timer()
    {
        auto end = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Used " << duration.count() << " ms\n";
    }
};

// int arr[10] = {7, 2, 1, 3, 9, 6, 5, 8, 4, 0};

// int n = sizeof(arr) / sizeof(int);

const int n = 10000;

int arr[n];

std::random_device              rd;
std::mt19937                    gen(rd());
std::uniform_int_distribution<> dis(0, 9999);

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // std::swap(arr[j], arr[j + 1])
                int temp = arr[j];   // a = a + b
                arr[j] = arr[j + 1]; // b = a - b
                arr[j + 1] = temp;   // a = a - b
            }
        }
    }
}

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--; // j=0 结束循环
        }
        arr[j + 1] = key; // 插入key
    }
}

int partition(int *arr, int left, int right)
{
    int pivot = arr[left];
    // int i = left - 1;

    // for (int j = left; j < right; j++)
    // {
    //     if (arr[j] <= pivot)
    //     {
    //         i++;

    //     }
    // }
    while (left < right)
    {
        while (left < right && arr[right] >= pivot)
        {
            right--;
        }
        arr[left] = arr[right];
        while (left < right && arr[left] <= pivot)
        {
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    return left;
}

void quickSort(int *arr, int left, int right)
{
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d", arr[i]);
    // }
    // puts("");
    int pivot;
    if (left < right)
    {
        pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

// 合并两个子区间(left,mid) (mid+1,right)
void merge(int *arr, int left, int mid, int right)
{
    int *temp = new int[right - left + 1];
    int  i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[i++] = arr[k++];

        else
            temp[j++] = arr[k++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int p = 0; p < k; p++)
        arr[left + p] = temp[p];

    delete[] temp;
}

void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void heapify(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int *arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)

        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

#define SORT_METHOD 0

int main()
{
    for (int i = 0; i < n; i++)
        arr[i] = dis(gen);

    Timer t;

#if SORT_METHOD == 0
    std::cout << "Using Bubble sort...\n";

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
        std::cout << arr[i] << "\n";

#elif SORT_METHOD == 1
    std::cout << "Using Selection sort...\n";

    selectionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << "\n";
    }

#elif SORT_METHOD == 2
    std::cout << "Using Insertion sort...\n";
    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << "\n";
    }
#elif SORT_METHOD == 3
    std::cout << "Using Quick sort...\n";
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << "\n";
    }
#elif SORT_METHOD == 4
    std::cout << "Using Merge sort...\n";
    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << "\n";
    }
#else
    std::cout << "Using Heap sort...\n";
#endif
}