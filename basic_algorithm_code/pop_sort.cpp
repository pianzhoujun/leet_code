#include <iostream>

using namespace std;

template<typename T>
void swap(T &a, T &b)
{
    cout << "do swaping..." << endl;
    T temp = a;
    a = b;
    b = temp;
    return ;
}

void echo_array(int data[], int len)
{
    if (data == NULL || len <= 0)
        return ;
    for (int i = 0; i < len; ++i)
        cout << data[i] << " ";
    cout << endl;
    return ;
}

void pop_sort(int data[], int len)
{
    if (data == NULL || len <= 0) return ;

    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (data[j] >  data[j + 1])
                ::swap(data[j], data[j + 1]);
        }
    }
}

void unit_test()
{
   int array[] = {1,2,3,4,5};
   pop_sort(array, 5);
   echo_array(array, 5);
    
    int array_1[] = {5,4,3,2,1};
    pop_sort(array_1, 5);
    echo_array(array_1, 5);
}

int main()
{
    unit_test();
    return 0;
}
