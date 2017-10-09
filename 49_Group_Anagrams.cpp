Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.


vector<vector<string>> groupAnagrams(vector<string>& strs) {

    vector<string> sorted = strs;
    vector<vector<string>> result;
    if (strs.size() == 0) return result;
    map<string,vector<string>> mapping;
    for (int i = 0; i < strs.size(); ++i){
        std::sort(sorted[i].begin(),sorted[i].end());
        mapping[sorted[i]].push_back(strs[i]);
    }
    for (auto m : mapping){
        result.push_back(m.second);
    }
    return result;
}
