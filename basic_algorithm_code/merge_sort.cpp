#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    void merge_sort (int data[], int n) {
        do_merge_sort(data, 0, n);
    }

    void do_merge_sort (int data[], int start, int end) {
        if (start + 1 >= end) {
            return ;
        }
        int mid = (start + end) / 2;
        do_merge_sort(data, start, mid);
        do_merge_sort(data, mid, end);
        merge(data, start, mid, end);
        return;
    }

    void merge(int data[], int start, int mid, int end) {
        int *sorted = new int[end - start];
        int i = start, j = mid, k = 0;
        while (i < mid && j < end) {
            sorted[k++] = data[i] < data[j] ? data[i++]: data[j++];
        }
        while (i < mid) {
            sorted[k++] = data[i++];
        }
        while (j < end) {
            sorted[k++] = data[j++];
        }
        memcpy(data + start, sorted, (end - start) * sizeof(data[0]));
        delete sorted;
    }

    void do_test() {
        // int data[] = {2, 1, 3, 9, 8};

        int data[] = {1, 2, 9, 8, 7, 6, -1, 10};
        merge_sort(data, 8);
        for (int i = 0; i < 8; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution *solution = new Solution();
    solution->do_test();
    delete solution;
    return 0; 
}
