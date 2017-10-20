Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]



My stupid solution:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0) return result;
        vector<int> tmp;
        tmp.push_back(nums[0]);
        result.push_back(tmp);
        for (int i = 1; i < nums.size(); ++i){
            for (int j = 0; j < result.size(); ++j){
                result[j].push_back(nums[i]);
            }
            int n = result.size();
            for (int k = 0; k < n; ++k){
                for (int p = 0; p < result[k].size()-1; ++p){
                    result.push_back(result[k]);
                    exchange(result[result.size()-1],p,result[k].size()-1);
                }
            }
        }
        return result;
    }
    void exchange(vector<int>& nums, int left, int right){
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
    }
    


BackTracking in discuss:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        helper(result,nums,0);
        return result;
    }
    void helper(vector<vector<int>>& result, vector<int>& nums, int begin){
        if (begin == nums.size()-1) result.push_back(nums);
        for(int i = begin; i < nums.size(); ++i){
            swap(nums[begin],nums[i]);
            helper(result,nums,begin+1);
            swap(nums[begin],nums[i]);
        }
        
    }
