Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.


A painful question, finally got it right.

vector<int> lexicalOrder(int n) {
    vector<int> result;
    if (!n) return result;
    int cur = 1;
    for (int i = 1; i <= n; ++i){
        result.push_back(cur);
        if (cur*10 <= n){
            cur *= 10;
        }else if (cur%10 != 9 && cur < n){
            cur++;
        }else {
            while((cur/10)%10 == 9){
                cur /= 10;
            }
            cur /= 10;
            cur += 1;
        }
    }
    return result;
}
