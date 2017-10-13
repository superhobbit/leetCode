Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
Related problem: Reverse Words in a String II


Answer again is pretty good:
void rotate(vector<int>& nums, int k) {
    if (k >= nums.size()) k %= nums.size();
    reverse_nums(nums,0,nums.size()-k-1);
    reverse_nums(nums,nums.size()-k,nums.size()-1);
    reverse_nums(nums,0,nums.size()-1);
}
void reverse_nums(vector<int>& nums, int left, int right){
    while(left <= right){
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
}
