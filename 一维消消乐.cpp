void removeNodes(string& s, int n, string &res){
    int index = 0, last = 0, i = 0, count = 0;
    while(i < s.size()){
        while(s[index] == s[i]) {
            count++; i++;
        }
        if(count <= 2){
            while(index < i) s[last++] = s[index++];
        }
        count = 0;
        index = i;
    }
    if(last == n) {
        res = s;
        return;
    }
    string tmp = s.substr(0,last);
    removeNodes(tmp,last,res);
}
