#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &vec, int &left, int &right)
{
    int pivot = vec[left];
    int l = left + 1;
    int r = right;
    while (l <= r)
    {
      if (vec[l] < pivot && vec[r] > pivot) {
        swap(vec[l], vec[r]);
        l++;
        r--;
      }
      if (vec[l] >= pivot)
        l++;
      if (vec[r] <= pivot)
        r--;
    }
    swap(vec[left], vec[r]);
    return r;
}
int kthLargest(vector<int> &vec, int &k)
{
    int left = 0;
    int right = vec.size() - 1;
    int kth;
    while (true)
    {
        int index = partition(vec, left, right);
        if (index == k - 1)
        {
            kth = vec[index];
            break;
        }
        if (index < k - 1)
        {
            left = index + 1;
        }
        else
        {
            right = right - 1;
        }
    }
    return kth;
}
int main()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    int k = 2;
    cout << kthLargest(vec, k) << endl;
}
