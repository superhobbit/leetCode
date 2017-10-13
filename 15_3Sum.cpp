Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    std::sort(nums.begin(),nums.end());
    if (nums.size() < 3) return result;
    for (int i = 0; i < nums.size()-2; ++i){
        int low = i+1;
        int high = nums.size()-1;

        while(low < high){
            if (0-nums[i] == nums[low] + nums[high]){
                    while(nums[low+1] == nums[low]) low++;
                    while(nums[high-1] == nums[high]) high--;
                    vector<int> res = {nums[i],nums[low],nums[high]};
                    result.push_back(res);
                    low++;
                    high--;
            }else if (0-nums[i] < nums[low] + nums[high]) high--;
            else low++;
        }
        while (i+1 < nums.size() && nums[i] == nums[i+1]) i++;
    }
    return result;
}
