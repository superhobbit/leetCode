Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


Code is very long and stupid:
int threeSumClosest(vector<int>& nums, int target) {
    vector<vector<int>>result;
    vector<int>res1(4,INT_MAX);
    vector<int>res2(4,INT_MAX);
    std::sort(nums.begin(),nums.end());
    bool smaller = false;
    bool bigger = false;
    bool combal = false;
    int minV = INT_MAX;
    if (!nums.size()) return 0;
    for(int i = 0; i < nums.size()-2; ++i){
        int low = i+1;
        int high = nums.size()-1;
        while(low < high){
            if (nums[i]+nums[low]+nums[high] == target) return target;
            if (nums[i]+nums[low]+nums[high] < target){
                smaller = true;
                if (bigger) {
                    if (combal) {
                        low++;
                        continue;
                    }
                    res2[0] = nums[i];
                    res2[1] = nums[low];
                    res2[2] = nums[high];
                    res2[3] = abs(nums[i]+nums[low]+nums[high]-target);
                    result.push_back(res1);
                    result.push_back(res2);
                    combal = true;
                    //break;
                }else{
                    res1[0] = nums[i];
                    res1[1] = nums[low];
                    res1[2] = nums[high];
                    res1[3] = abs(nums[i]+nums[low]+nums[high]-target);                        
                }
                low++;
            }else{
                bigger = true;
                if (smaller) {
                    if (combal) {
                        high--;
                        continue;
                    }
                    res2[0] = nums[i];
                    res2[1] = nums[low];
                    res2[2] = nums[high];
                    res2[3] = abs(nums[i]+nums[low]+nums[high]-target);
                    result.push_back(res1);
                    result.push_back(res2);
                    combal = true;
                    //break;
                }else{
                    res1[0] = nums[i];
                    res1[1] = nums[low];
                    res1[2] = nums[high];
                    res1[3] = abs(nums[i]+nums[low]+nums[high]-target);                        
                }                    
                high--;
            }
        }
        if (!smaller || !bigger) result.push_back(res1);
        smaller = bigger = combal = false;
    }
    for (int i = 0; i < result.size(); ++i){
        minV = min(minV,result[i][3]);
    }
    for (int i = 0; i < result.size(); ++i){
        if (result[i][3] == minV) return result[i][0]+result[i][1]+result[i][2];
    }
    return 0;
}


A more elegent solution:
int threeSumClosest(vector<int>& nums, int target) {
    int minV = INT_MAX;
    int sum;
    int res;
    std::sort(nums.begin(),nums.end());
    if (nums.size() < 3) return accumulate(nums.begin(),nums.end(),0);
    for (int i = 0; i < nums.size()-2; ++i){
        int low = i+1;
        int high = nums.size()-1;
        while(low < high){
            sum = nums[i]+nums[low]+nums[high];
            if (sum == target) return sum;
            if (sum < target) low++;
            else high--;
            minV = min(minV,abs(sum-target));
            if (abs(sum-target) <= minV) res = sum;
        }
    }
    return res;
}
