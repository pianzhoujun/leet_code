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
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int totoal_num  = nums1.size() + nums2.size();
            if (totoal_num & 0x01)
                return get_kth(nums1, nums2, totoal_num/2 + 1);
            else 
                return double(get_kth(nums1, nums2, totoal_num/2) + get_kth(nums1, nums2, totoal_num/2 + 1)) / 2;
        }

        int lengthOfLongestSubstring(string s) {
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
            if (num_rows <= 1) return s;
            vector<string> res_rows(num_rows, "");
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

        int reverse_integer(int x) {
            int ret_val = 0;
            while (x) {
                int tmep_value = ret_val;
                ret_val = ret_val * 10 + x % 10;
                if (tmep_value != (ret_val - x % 10) / 10) return 0; // overflow
                x /= 10;
            }
            return ret_val;
        }

        bool isPalindrome(int x) {
            if (x < 0 || (x != 0 && x % 10 == 0)) return false;
            int right = 0;
            while (x > right) {
                right = right * 10 + x % 10;
                x /= 10;
            }
            return (right == x || right == x/10);
        }

        int myAtoi(string str) {
            int base = 0, i = 0, sign = 1;
            int MAX_INT = 2147483647, MIN_INT = -2147483648;
            while(str[i] == ' ' && i < str.size()) ++i;
            if (i == str.size()) return 0;
            if (str[i] == '+' || str[i] == '-') sign = str[i++] == '-'? -1 : 1;
            while ( i < str.size() && str[i] >= '0' && str[i] <= '9') {
                if (base > MAX_INT / 10 || (base == MAX_INT / 10 && str[i] - '0' > MAX_INT % 10)) {
                    return sign == 1? MAX_INT: MIN_INT;
                }
                base = base * 10 + str[i++] - '0';
            }
            return sign * base;
        }

        // bool isMatch(string s, string p) {
        //     if (s.empty() && p.empty()) {
        //         return true;
        //     }
            
        //     bool dp[s.length() + 1][p.length() + 1];
        //     dp[0][0] = true;

        //     for (int i = 0; i < p.length(); ++i) {
        //         if (p.charAt(i) == '*' && dp[0][i - 1]) 
        //             dp[0][i + 1] = true;
        //     }

        //     for (int i = 0; i < s.length(); ++i) {
        //         for (int j = 0; j < p.length(); ++j) {
        //             if (p.charAt(j) == '.' || p.charAt[j] == s.charAt(i)) {
        //                 dp[i+1][j+1] = dp[i][j];
        //             }
        //             else { // p.charAt(j) == '*'
        //                 if (p.charAt(j-1) != s.charAt(i) && p.charAt(j-1) != '.') {
        //                     dp[i+1][j+1] = dp[i+1][j-1];
        //                 }
        //                 else {
        //                     dp[i+1][j+1] = dp[i+1][j] || dp[i][j+1] || dp[i+1][j-2];
        //                 }
        //             }
        //         }
        //     }
        //     return dp[s.length()][p.length()];
        // }

        int maxArea(vector<int>& height) {
            int max_area = 0, left = 0, right = height.size() - 1;

            while(left < right) {
                max_area = max(max_area, min(height[left], height[right]) * (right - left));
                if (height[left] < height[right])
                    ++left;
                else
                    --right;
            }

            return max_area;
        }

        string intToRoman(int num) {
            string value[4][10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
                                    "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
                                    "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
                                    "", "M", "MM", "MMM"};
            string roman;
            roman.append(value[3][num /1000 % 10]);
            roman.append(value[2][num /100 % 10]);
            roman.append(value[1][num /10 % 10]);
            roman.append(value[0][num % 10]);
            return roman;
        }

        int romanToInt(string roman) {
            if (roman.size() == 0) {
                return 0;
            }

            int int_val = 0, i = 0;
            int state = 0;
            while (i < roman.size()) {
                if (state == 0) {
                    if (roman[i] == 'M') {
                        int_val += 1000;
                    } 
                    else {
                        state = 1;
                        --i;
                    }
                }
                else if (state == 1) {
                    if (roman[i] == 'C') {
                        if (roman[i+1] == 'D') {
                            int_val += 400;
                            ++ i;
                        }
                        else if (roman[i+1] == 'M') {
                            int_val += 900;
                            ++i;
                        }
                        else {
                            int_val += 100;   
                        }
                    }
                    else if (roman[i] == 'D') {
                        int_val += 500;
                    }
                    else {
                        -- i;
                        state = 2;
                    }
                }
                else if (state == 2) {
                    if (roman[i] == 'X') {
                        if (roman[i + 1] == 'L') {
                            int_val += 40;
                            ++i;
                        }
                        else if (roman[i + 1] == 'C') {
                            int_val += 90;
                            ++i;
                        }
                        else {
                            int_val += 10;   
                        }
                    }
                    else if (roman[i] == 'L') {
                        int_val += 50;
                    }
                    else {
                        -- i;
                        state = 3;
                    }
                }
                else if (state == 3) {
                    if (roman[i] == 'I') {
                        if (i == roman.size() - 1) {
                            int_val += 1;
                        }
                        else if (roman[i + 1] == 'I') {
                            int_val += 1;   
                        }
                        else if (roman[i + 1] == 'V') {
                            int_val += 4;
                            ++i;
                        }
                        else if (roman[i + 1] == 'X') {
                            int_val += 9;
                            ++i;
                        }
                    }
                    else if (roman[i] == 'V') {
                        int_val += 5;
                    }
                    else {
                        break;
                    }
                }
                ++ i;
            }
            return int_val;
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
            this->do_unit_test();
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

    void do_unit_test() {
        // this->unit_test_lengthOfLongestSubstring();
        // this->unit_test_findMedianSortedArrays();
        // this->unit_test_zigzarg_convert();
        // this->unit_test_reverse_integer();
        // this->unit_test_palindrome();
        this->unit_test_ramon_to_int();
    }

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
        cout << solution->zigzarg_convert("PAYPALISHIRING", 3) << endl;
        cout << "PAHNAPLSIIGYIR" << endl;
    }

    void unit_test_reverse_integer() {
        cout << solution->reverse_integer(123) << endl;
        cout << solution->reverse_integer(-123) << endl;
        cout << solution->reverse_integer(0xFFFFFFFF) << endl;
    }

    void unit_test_palindrome() {
        cout << solution->isPalindrome(123321) << endl;
        cout << solution->isPalindrome(123445) << endl;
    }

    void unit_test_ramon_to_int() {
        cout << solution->romanToInt("I") << endl;
        cout << solution->romanToInt("II") << endl;
        cout << solution->romanToInt("III") << endl;
        cout << solution->romanToInt("IV") << endl;
        cout << solution->romanToInt("V") << endl;
        cout << solution->romanToInt("VII") << endl;
        cout << solution->romanToInt("VII") << endl;
        cout << solution->romanToInt("VIII") << endl;
        cout << solution->romanToInt("IX") << endl;

        cout << solution->romanToInt("X") << endl;
        cout << solution->romanToInt("XI") << endl;
        cout << solution->romanToInt("XII") << endl;
        cout << solution->romanToInt("XIII") << endl;
        cout << solution->romanToInt("XIV") << endl;
        cout << solution->romanToInt("XV") << endl;
        cout << solution->romanToInt("XVI") << endl;
        cout << solution->romanToInt("XVII") << endl;
        cout << solution->romanToInt("XVIII") << endl;
        cout << solution->romanToInt("XIX") << endl;

        cout << solution->romanToInt("XX") << endl;
        cout << solution->romanToInt("XXX") << endl;
        cout << solution->romanToInt("XL") << endl;
        cout << solution->romanToInt("L") << endl;
        cout << solution->romanToInt("LX") << endl;
        cout << solution->romanToInt("LXX") << endl;       
    }

    
private:
    Solution *solution;
};

int main(int argc, char const *argv[])
{
    UnitTest ut;      
    return 0;
}

