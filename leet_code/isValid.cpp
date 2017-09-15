#include <stack>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
    	if (s.size() <= 1 || s.size() % 2 == 1) {
    		return false;
    	}      

    	stack<char> bank;
    	map<char, int> hash_map;
    	hash_map['('] = 1;
    	hash_map['['] = 2;
    	hash_map['{'] = 3;
    	hash_map[')'] = -1;
    	hash_map[']'] = -2;
    	hash_map['}'] = -3;
    	
    	for (int i = 0; i < s.size(); ++i) {
    		if (hash_map[s[i]] > 0) {
    			bank.push(s[i]);
    		}
    		else {
    			if (bank.empty()) {
    				return false;
    			}
    			char ch = bank.top();
    			bank.pop();
    			if (hash_map[ch] + hash_map[s[i]] != 0) {
    				return false;
    			}
    		}
    	}

    	return bank.empty() ? true: false;
    }

    void do_test() {
    	cout << isValid("[]") << endl;
    	cout << isValid("[(){}]") << endl;
    	cout << isValid("[)") << endl;
    	cout << isValid("([)]") << endl;
    }
};


int main()
{
	Solution *solution = new Solution();
	solution->do_test();
	delete solution;
	return 0;
}