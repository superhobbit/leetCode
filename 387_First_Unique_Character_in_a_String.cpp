Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.


int firstUniqChar(string s) {
    vector<int>frequency(256,0);
    for (int i = 0; i < s.size(); ++i){
        frequency[s.at(i)]++;
    }
    for (int i = 0; i < s.size(); ++i){
        if (frequency[s.at(i)] == 1) return i;
    }
    return -1;
} 
