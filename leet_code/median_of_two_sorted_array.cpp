#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>
#include <ostream>
#include <fstream>

using namespace std;

class Solution {

    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
        {
            int totoal_num  = nums1.size() + nums2.size();
            if (totoal_num & 0x01)
                return get_kth(nums1, nums2, totoal_num/2 + 1);
            else 
                return double(get_kth(nums1, nums2, totoal_num/2) + get_kth(nums1, nums2, totoal_num/2 + 1)) / 2;
        }

        int lengthOfLongestSubstring(string s) 
        {
            if (s.size() <= 1)
                return s.size();

            vector<int> hash(256, -1);
            int max_len = 0;
            int start = -1;
            for (int i = 0; i < s.size(); ++i) {
                if (hash[s[i]] > start) {
                    start = hash[s[i]];
                }
                hash[s[i]] = i;
                max_len = max(max_len, i - start);
            }
            return max_len;
        }
        
        string longestPalindrome(string s) {
            if (s.size() <= 1) return s;
            int start = 0;
            int max_len = 1;
            for (int mid = 0; mid < s.size();) {
                if (max_len >= s.size() - mid) break;
                int left, right;
                left = right = mid;
                while (right < s.size() - 1 && s[right] == s[right + 1]) ++right;
                mid = right + 1;
                while (left > 0 && right < s.size() - 1 && s[left - 1] == s[right + 1]) {
                    --left; 
                    ++right;
                }
                if (right - left > max_len) {
                    max_len = right - left;
                    start = left;
                }
            }
            return s.substr(start, max_len);
        }

        string zigzarg_convert(string s, int num_rows) {
            if (num_rows <= 1)
                return s;
            int step = 1;
            int cur_row = 0;
            for (int index = 0; index < s.size(); ++index) {
                res_rows[cur_row].push_back(s[index]);
                if (cur_row == 0) 
                    step = 1;
                else if(cur_row == num_rows - 1) 
                    step = -1;
                cur_row += step;
            }
            string res;
            for (vector<string>::iterator iter = res_rows.begin(); iter != res_rows.end(); ++iter) res += *iter;
            return res;
        }

    private:
        int get_kth(vector<int> &array_a, vector<int> &array_b, int k)
        {
            if(array_a.size() > array_b.size()) {
                return get_kth(array_b, array_a, k);
            }

            if (array_a.size() == 0) {
                return array_b[k - 1];
            }
            
            if (k == 1) {
                return min(array_a[0], array_b[0]);
            }
            
            int index_a = min(k/2, int(array_a.size()));
            int index_b = k - index_a;
            if (array_a[index_a - 1] < array_b[index_b - 1]) {
                vector<int> array_a_slice(array_a.begin() + index_a, array_a.end());
                return get_kth(array_a_slice, array_b, k - index_a);
            }
            else if (array_a[index_a - 1] > array_b[index_b - 1]) {
                vector<int> array_b_slice(array_b.begin() + index_b, array_b.end());
                return get_kth(array_a, array_b_slice, k - index_b);
            }
            else
                return array_a[index_a - 1];
        }
};


class UnitTest
{
public:
    UnitTest() {
        try {
            solution = new Solution();
            this->unit_test_lengthOfLongestSubstring();
            this->unit_test_findMedianSortedArrays();
        }
        catch (exception &except) {
            if (solution)
                delete solution;
            filebuf fp;
            fp.open("./except.out", ios::out);
            ostream output(&fp);
            output << except.what() << endl;
            fp.close();
        }
    }
    ~UnitTest(){
        if (solution){
            delete solution;    
        }
    }

private:

    void unit_test_findMedianSortedArrays() {
        int nums_1[] = {2,3,4,5,6,7,9,10};
        int nums_2[] = {1,8};
        vector<int> nums1(nums_1, nums_1 + sizeof(nums_1)/sizeof(int)), nums2(nums_2, nums_2 + sizeof(nums_2)/sizeof(int));
        assert(solution->findMedianSortedArrays(nums1, nums2) == 5.5);
    }

    void unit_test_lengthOfLongestSubstring() {
        assert(solution->lengthOfLongestSubstring("abcabcbb") == 3);
        assert(solution->lengthOfLongestSubstring("bbbbb") == 1);
        assert(solution->lengthOfLongestSubstring("pwwkew") == 3);
    }

    void unit_test_longestPalindrome() {
        assert(solution->longestPalindrome("babad") == "bab");
        assert(solution->longestPalindrome("cbbd") == "bb");
        assert(solution->longestPalindrome("aaaaaaa") == "aaaaaaa");
    }

    void unit_test_zigzarg_convert() {
        assert(solution->zigzarg_convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    }
    
private:
    Solution *solution;
};

int main(int argc, char const *argv[])
{
    UnitTest ut;      
    return 0;
}

