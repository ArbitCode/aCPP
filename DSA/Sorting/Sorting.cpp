#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// select mini, swap with i.
void selection_sort(vector<int> &vec)
{
    int n = vec.size();
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;
        for (int j = i; j < n; j++)
        {
            if (vec[j] < vec[mini])
                mini = j;
        }
        swap(vec[i], vec[mini]);
    }
}

void bubble_sort(vector<int> &vec)
{
    int n = vec.size();
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
        }
    }
}

void insertion_sort(vector<int> &vec)
{
    int n = vec.size();
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j >= 1 && vec[j - 1] > vec[j])
            swap(vec[j - 1], vec[j]);
    }
}

int partition(vector<int> &vec, int low, int high)
{
    int pviot = vec[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (vec[i] <= pviot && i <= high - 1)
            i++;
        while (vec[j] > pviot && j >= low + 1)
            j--;
        if (i < j)
            swap(vec[i], vec[j]);
    }
    swap(vec[low], vec[j]);
    return j;
}
void quick_sort(vector<int> &vec, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(vec, low, high);
        quick_sort(vec, low, pIndex - 1);
        quick_sort(vec, pIndex + 1, high);
    }
}
void merge(vector<int> &vec, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (vec[left] <= vec[right])
        {
            temp.push_back(vec[left]);
            left++;
        }
        else
        {
            temp.push_back(vec[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(vec[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(vec[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
        vec[i] = temp[i - low];
}
void merge_sort(vector<int> &vec, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    merge_sort(vec, low, mid);
    merge_sort(vec, mid + 1, high);
    merge(vec, low, mid, high);
}

int main()
{
    vector<int> vec = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    merge_sort(vec, 0, vec.size() - 1);
    for (auto val : vec)
        cout << val << " ";
}
