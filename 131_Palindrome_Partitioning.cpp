Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]

Memory limit exceeded in leetcode, but work fine on local IDE, don't know why, unsolved, below it is worked funtion:
vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    if (!s.size()) return result;
    vector<string> res;
    result = dfs(result,res,s,0);
    return result;
}
vector<vector<string>> dfs(vector<vector<string>>& result, vector<string>& res, string s, int index){
    if (index == s.size()) result.push_back(res);
    for (int i = index; i < s.size(); ++i){
        if (symetric(s,index,i)){
            res.push_back(s.substr(index,i-index+1));
            dfs(result,res,s,i+1);
            res.pop_back();
        }
    }
    return result;
}
bool symetric(string s, int left, int right){
    while(left < right){
        if (s.at(left) == s.at(right)){
            left++;
            right--;
        }else return false;
    }
    return true;
}


vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    if (!s.size()) return result;
    vector<string> res;
    dfs(result,res,s,0);
    return result;
}
void dfs(vector<vector<string>>& result, vector<string>& res, string s, int index){
    if (index == s.size()) result.push_back(res);
    for (int i = index; i < s.size(); ++i){
        if (symetric(s,index,i)){
            res.push_back(s.substr(index,i-index+1));
            dfs(result,res,s,i+1);
            res.pop_back();
        }
    }
}
bool symetric(string s, int left, int right){
    while(left < right){
        if (s.at(left) == s.at(right)){
            left++;
            right--;
        }else return false;
    }
    return true;
}
