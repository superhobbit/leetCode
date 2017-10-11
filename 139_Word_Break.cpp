Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.


答案again。。。
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> words(wordDict.begin(), wordDict.end());
    if (s.size() == 0) return false;
    vector<int>result(s.size()+1,0);
    result[0] = 1;
    for (int i = 0; i < s.size(); ++i){
        for (int j = i; j >= 0; --j){
            if (result[j]){
                string check = s.substr(j,i-j+1);
                if (words.count(check)) {
                    result[i+1] = 1;
                    break;
                }
            }
        }
    }
    return result[s.size()];
}
