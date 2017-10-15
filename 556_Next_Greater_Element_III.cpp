Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:
Input: 12
Output: 21
Example 2:
Input: 21
Output: -1


Again...a very long stupid code, but running time works fine:
int nextGreaterElement(int n) {
    if (n < 10) return -1;
    int tmp = n;
    vector<int>res;
    int index = -1;
    int result = 0;
    while(tmp){
        res.push_back(tmp%10);
        tmp /= 10;
    }
    if (res.front() > *(res.begin()+1)) reverse(res.begin(),res.begin()+2);
    else {
        for (int i = 1; i < res.size(); ++i){
            if (res[i] < res[i-1]){
                reverse(res.begin(),res.begin()+i);
                index = i;
                break;
            }
        }
        for (int i = index; i >= 0; --i){
            if (res[i] > res[index]){
                int tmp = res[i];
                res[i] = res[index];
                res[index] = tmp;
                break;
            }
        }
    }
    for(int i = 0; i < res.size(); ++i){
        result += res[i]*pow(10,i);
    }
    if (result == n) return -1;
    if (result == INT_MIN || result == INT_MAX) return -1;
    return result;
}
