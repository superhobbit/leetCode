Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.


Answer's solution is much better:

int removeDuplicates(vector<int>& nums) {
    if (!nums.size()) return nums.size();
    int record = 0;
    for (int i = 1; i < nums.size(); ++i){
        if (nums[record] == nums[i]) continue;
        nums[++record] = nums[i];
    }
    return record+1;
}
