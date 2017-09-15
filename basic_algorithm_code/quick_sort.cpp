#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int echo_array(int data[], int start, int end)
{
    if (data == NULL || start > end)    return 0;
    for (int index = start; index <= end; ++ index) cout << data[index] << " ";
    cout << endl;
    return 0;
}

inline int rand_next(int start, int end)
{
    return random()%(end - start + 1) + start;
}


template<typename T>
void swap(T &num_a, T &num_b)
{
    cout << "do swaping... " << endl;
    T temp = num_a;
    num_a = num_b;
    num_b = temp;
}

int quick_partition(int data[], int start, int end)
{
    int index = rand_next(start, end); 
    ::swap (data[index], data[end]);
    int small = start - 1;
    for (index = start; index < end; ++index) {
        if (data[index] < data[end]) {
            ++small;
            if (small != index) {
                ::swap(data[index], data[small]);
            }
        }
    }
    ++small;
    ::swap(data[small], data[end]);
    return small;
}

void do_quick_sort(int data[], int start, int end)
{
    if (start >=  end) 
        return;
    int index = quick_partition(data, start, end);
    if (start < index)
        do_quick_sort(data, start, index - 1);
    if (index < end)
        do_quick_sort(data, index + 1, end);
}

void quick_sort(int data[], int len)
{
    cout << "source: ";
    echo_array(data, 0, len - 1);
    do_quick_sort(data, 0, len - 1);
    cout << "processed: ";
    echo_array(data, 0, len - 1);
}


void unit_test()
{
    int data[] = {1,2,3,4,5}; 
    quick_sort(data, 5);
    
    int data_1[] = {5,4,3,2,1};
    quick_sort(data_1, 5);

    int data_2[] = {1,2,5,3,4};
    quick_sort(data_2, 5);
}

int main()
{
    srand(time(0));
    unit_test();
    return 0;
}
