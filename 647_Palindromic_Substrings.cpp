Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


DP solution:
    int countSubstrings(string s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size(),0));
        int count = 0;
        for (int i = 0; i < s.size(); ++i){
            for (int j = i; j >= 0; --j){
                dp[j][i] = (s.at(i) == s.at(j) && (i-j < 2 || dp[j+1][i-1]));
                if (dp[j][i]) count++;
            }
        }
        return count;
    }
    
    
General solution: use single element as center, and find odd and even results seperetly:
class Solution {
public:
    int count;
    int countSubstrings(string s) {
        if (s.size() == 0) return 0;
        count = 0;
        for (int i = 0; i < s.size(); ++i){
            helper(s,i,i);
            helper(s,i,i+1);
        }
        return count;
    }
    void helper(string s, int left, int right){
        while(left >= 0 && right < s.size() && s.at(left) == s.at(right)){
            count++;
            left--;
            right++;
        }
    }
};
