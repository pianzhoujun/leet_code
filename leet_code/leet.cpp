#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Util{
public:
	static int random_in_range(int start, int end) {
		srand(time(0));
		return random() % (end - start) + start;
	}

	template<typename T>
	static void swap(T &a, T &b) {
		T temp = a;
		a = b;
		b = temp;
	}
};

class Solution {
public:
	void quick_sort(int data[], int len) {
	    if (data == NULL || len <= 1) return;
	    do_quick_sort(data, 0, len - 1);
	}

	void pop_sort(int data[], int len) {
		if (data == NULL || len <= 1) return;
		for (int i = 1; i < len; ++i) {
			for (int j = 0; j < len - i; ++j) {
				if (data[j] > data[j + 1]) {
					Util::swap(data[j], data[j+1]);
				}
			}
		}
	}

	void select_sort(int data[], int len) {
		if (data == NULL || len <= 1) return;
		for (int i = 0; i < len - 1; ++i) {
			int max_index = i;
			for (int j = i + 1; j < len; ++j) {
				if(data[j] > data[max_index]) {
					max_index = j;
				}
			}
			Util::swap(data[i], data[max_index]);
		}
	}

private:
	void do_quick_sort(int data[], int start, int end) {
		if (start >= end) return;
		int index = partition(data, start, end);
		if (start < index) do_quick_sort(data, start, index - 1);
		if (end > index) do_quick_sort(data, index + 1, end);
	}

	int partition(int data[], int start, int end) {
	    int index = Util::random_in_range(start, end);
	    Util::swap(data[index], data[end]);

	    int small = start - 1;
	    for (index = start; index < end; ++index) {
	    	if (data[index] < data[end]) {
	    		++ small;
	    		if (index != small) {
	    			Util::swap(data[index], data[small]);
	    		}
	    	}
	    }
	    ++ small;
	    Util::swap(data[small], data[end]);
	    return small;
	}
};


class UnitTest{
public:
	UnitTest() {
		solution = new Solution();
	}

	~UnitTest() {
		if (solution)
			delete solution;
	}

	void do_unit_test() {
		do_unit_test_quick_sort();
	}

	void do_unit_test_quick_sort() {
		int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
		cout << "pre sort: ";
		for (int x: array) {
			cout << x << " ";
		}
		cout << endl;
		solution->quick_sort(array, sizeof(array)/sizeof(int));
		cout << "done sort: ";
		for (int x: array) {
			cout << x  << " ";
		}
		cout << endl;
	}

private:
	Solution *solution;
};

int main(int argc, char const *argv[])
{
	UnitTest *ut = new UnitTest();
	ut->do_unit_test();
	delete ut;
	return 0;
}