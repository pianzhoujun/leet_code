#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	vector<string> res;
    	if (digits.size() == 0) {
    		return res;
    	}
    	queue<string> str_queue;
    	string dict[] = {"abc", "def", "ghi","jkl","mno","pqis","tuv","wxyz"};
    	
    	for (int j = 0; j < dict[digits[0] - '2'].size(); ++j) {
    		string tmp(1, dict[digits[0] - '2'][j]);
    		str_queue.push(tmp);
    	}

    	for (int i = 1; i < digits.size(); ++ i) {
    		int size = str_queue.size();
    		for (int k = 0; k < size; ++ k) {
    			string str = str_queue.front();
    			str_queue.pop();
    			for (int j = 0; j < dict[digits[i] - '2'].size(); ++j) {
    				str_queue.push(str + dict[digits[i] - '2'][j]);
    			}
    		}
    	}

    	
    	while (!str_queue.empty()) {
    		 res.push_back(str_queue.front());
    		 str_queue.pop();
    	}
    	return res;
    }

    void do_test() {
    	vector<string> res;
    	res = letterCombinations("23");
    	for (vector<string>::iterator iter = res.begin(); iter != res.end(); ++ iter) {
    		cout << *iter <<" ";
    	}
    	cout << endl;
    }
};

int main(void)
{
	Solution *solution = new Solution();
	solution->do_test();
	delete solution;
	return 0;
}