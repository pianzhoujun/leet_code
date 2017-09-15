#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> result;
    	do_generateParenthesis(result, "", n, 0);
    	return result;
    }

    void do_generateParenthesis(vector<string> &result, string str, int n, int m) {
    	if (n == 0 && m == 0) {
    		result.push_back(str);
    		return;
    	}

    	if (n > 0) {
    		do_generateParenthesis(result, str + "(", n - 1, m + 1);
    	}

    	if (m > 0) {
    		do_generateParenthesis(result, str + ")", n, m - 1);
    	}
    }

    void do_test() {
    	vector<string> res = generateParenthesis(3);
    	for (vector<string>::iterator iter = res.begin(); iter != res.end(); ++iter) {
    		cout << *iter << endl;
    	}
    }
};

int main(void) 
{
	Solution *solution = new Solution();
	solution->do_test();
	delete solution;
}