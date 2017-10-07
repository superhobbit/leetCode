Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.


Solution with set: not very good
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    set<int> check;
    for (int i = 0; i < n; ++i){
        int a = check.insert(nums[i]).second;
        if (!a) return nums[i];
    }
    return NULL;
}

More efficient solution: with two runners, fast and slow:
int findDuplicate(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    int fast = nums[nums[0]];
    int slow = nums[0];
    while(fast != slow){
        fast = nums[nums[fast]];
        slow = nums[slow];
    }
    fast = 0;
    while (fast != slow){
        fast = nums[fast];
        slow = nums[slow];
    }
    return fast;
}
