Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


int lengthOfLongestSubstring(string s) {
    if (s.length() == 0) return 0;
    map<char, int> total;
    int j = 0, maxI = 0;
    for (int i = 0; i < s.length(); i++){
        if (total.find(s[i])!=total.end()){
            j = std::max(j,total.find(s[i])->second+1);
            total.erase(total.find(s[i]));
        }
        total.insert(pair<char,int>(s[i],i));
        maxI = std::max(maxI,i-j+1);
    }
    return maxI;
}


More efficient way:
int lengthOfLongestSubstring(string s) {
    if (s.length() == 0) return 0;
    int next = 0, maxV = 0;
    bool exist[256] = {false};
    for (int i = 0; i < s.size(); ++i){
        if(!exist[s[i]]){
            maxV = max(maxV,i-next+1);
            exist[s[i]] = true;
        }else{
            while(exist[s[i]]){
                exist[s[next++]] = false;
            }
            exist[s[i]] = true;
        }
    }
    return maxV;
}
