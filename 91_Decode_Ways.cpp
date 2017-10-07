A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

正DP：
int numDecodings(string s) {
    if (s.size() == 0 || s.at(0) == '0') return false;
    vector<int> result(s.size()+1);
    result[0] = 1;
    result[1] = 1;
    for (int i = 2; i <= s.size(); ++i){
        if (s.at(i-1) == '0' && s.at(i-2) == '0') return false;
        else if (s.at(i-1) == '0') {
            if (s.at(i-2) == '1' || s.at(i-2) == '2') result[i] = result[i-2];
            else return false;
        }
        else if (s.at(i-2) == '0') result[i] = result[i-1];
        else if (s.at(i-2) == '1') result[i] = result[i-1]+result[i-2];
        else if (s.at(i-2) == '2'){
            if (s.at(i-1) <= '6') result[i] = result[i-1]+result[i-2];
            else result[i] = result[i-1];
        }
        else result[i] = result[i-1];
    }
    return result[s.size()];
}

反DP：
int numDecodings(string s) {
    if (s.size() == 0 || s.at(0) == '0') return false;
    int n = s.size();
    vector<int> result(n+1,0);
    result[n] = 1;
    if (s.at(n-1) == '0') result[n-1] = 0;
    else result[n-1] = 1;
    for (int i = n-2; i >= 0; i--){
        if (s.at(i)=='0') continue;
        if (s.at(i)=='1') result[i] = result[i+1]+result[i+2];
        else if (s.at(i)=='2'){
            if (s.at(i+1)<='6') result[i] = result[i+1]+result[i+2];
            else result[i] = result[i+1];
        }
        else result[i] = result[i+1];
    }
    return result[0];
}
