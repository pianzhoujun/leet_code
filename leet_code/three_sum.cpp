#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) 
    {
        vector< vector<int> > res;
        if (nums.size() <= 2) {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2;  ++i) {
            if (i > 0 && nums[i] == nums[i-1]) 
                continue;
        	int left = i + 1;
        	int right = nums.size() - 1;
        	int target = -nums[i];
        	while (left < right ) {
        		int sum = nums[left] + nums[right];
        		if (sum == target) {
        			vector<int> tmp;
        			tmp.push_back(nums[i]);
        			tmp.push_back(nums[left]);
        			tmp.push_back(nums[right]);
        			res.push_back(tmp);
                    while (left < right && nums[left] == nums[left + 1]) left ++;
                    while (left < right && nums[right] == nums[right - 1]) right --;
                    left ++;
                    right --;
        		}
        		else if (sum < target) {
        			 ++ left;
        		}
        		else {
        			-- right;
        		}
        	}
        }
        return res;
    }

    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];
        int diff = abs(closest - target);
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum == target) {
                    return target;
                }

                if (diff > abs(sum - target)) {
                    closest = sum;
                    diff = abs(sum - target);
                }
                sum > target ? --right: ++left;
            }
        }
        return closest;
    }

    void test_threeSum()  
    {
    	// int list[] = {-1, 0, 1, 2, -1, -4};
        //int list[] = {0,0,0,0};
        int list[] = {1,-4,-4,2,0,0,-2,3,3,-3,-4};
    	vector<int> vec(list, list + sizeof(list)/sizeof(list[0]));
        vector< vector<int> > res = threeSum(vec);
    	
    	for (vector< vector<int> >::iterator iter = res.begin(); iter != res.end(); ++iter) {
    		for(vector<int>::iterator it = iter->begin();it != iter->end();  ++it) {
    			cout << *it << " ";
    		}
    		cout << endl;
    	}
    }

    void test_threeSumCloset()
    {
//        int list[] = {1,-4,-4,2,0,0,-2,3,3,-3,-4};
        int list[] = {0, 2, 1, -3};
        vector<int> vec(list, list + sizeof(list)/sizeof(list[0]));
        cout << threeSumClosest(vec, 1) << endl;
    } 

};


int main(void)
{
	Solution *solution = new Solution();
	solution->test_threeSumCloset();
	delete solution;
	return 0;
}
