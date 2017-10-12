Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"


DP: answer again:
string longestPalindrome(string s) {
    if (s.size() < 2) return s;
    int n = s.size();
    string results = "";
    vector<vector<bool>>result(n,vector<bool>(n));
    for (int i = 0; i < n; ++i){
        for(int j = 0; j <= i; ++j){
            result[i][j] = (s.at(i) == s.at(j)) && (i-j <= 2 || result[i-1][j+1]);
            if (result[i][j] && results.size() < i-j+1) {
                results = s.substr(j,i-j+1);
            }
        }
    }
    return results;
}
