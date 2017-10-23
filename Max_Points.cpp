Delete and Earn 
Given an array of n integers named elements, we can perform several steps on the array. In each step, we choose an elements, from the array and delete it to earn elements; points; however, deleting elements, also deletes any integers equal to elementsi + 1 and elementsi - 1 from elements. For example, if elements = [1, 2, 3, 4J, deleting 2 results in elements becoming [4] and earns us 2 points. 
Complete the maxPoints function in the editor below. It has one parameter: an array of n integers named elements. The function must return a long integer denoting the maximum number of points we can earn by performing steps. 
Input Format The first line contains an integer, n, denoting the number of integers in elements. Each line i of the n subsequent lines (where 0 i < n) contains an integer describing elementsi. 
Constraints • 7 < n < 105 • 1 elements, 105 
Output Format Return a long integer denoting the maximum number of points we can earn by performing steps. 
Sample Input 0 
3 3 4 2 
Sample Output 0 


Pretty similar to LC 70
DP solution:
int maxPoints(vector<int>& elements){
    vector<vector<int>>dp(2,vector<int>(elements.size()+1));
    vector<int>new_elements;
    dp[0][0] = dp[1][0] = 0;
    unordered_map<int,int>maps;
    for (auto a : elements){
        if (maps.find(a) != maps.end()) maps[a]++;
        else maps[a] = 1;
    }
    for (auto it = maps.begin(); it != maps.end(); ++it){
        new_elements.push_back(it->first*it->second);
    }
    for (int i = 0; i < new_elements.size(); ++i){
        dp[0][i+1] = max(dp[1][i],dp[0][i]);
        dp[1][i+1] = dp[0][i]+new_elements[i];
    }
    return max(dp[0][new_elements.size()],dp[1][new_elements.size()]);
}
