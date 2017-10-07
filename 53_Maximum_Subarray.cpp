
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
  
  
int maxSubArray(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    int n = nums.size();
    vector<int> result(n);
    result[0] = nums[0];
    int maxV = result[0];
    for (int i = 1; i < n; ++i){
        result[i] = nums[i] + (result[i-1] > 0 ? result[i-1] : 0);
        maxV = max(maxV,result[i]);
    }
    return maxV;
}
