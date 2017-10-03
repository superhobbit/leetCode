Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.


General solution: To start from the end of the array, select the smallest index with the biggest jump distant, till reach to the beginning element.
bool canJump(vector<int>& nums) {
    int check = nums.size()-1;
    for (int i = nums.size()-1; i >= 0; --i){
        if(nums[i]+i >= check) check = i;
    }
    return check == 0;
}
Not very good run time


Faster one:
because we'll only stuck at 0, so when reach to 0, we just see if we can jump through 0.

bool canJump(vector<int>& nums) {
    if (nums.size() < 2) return true;
    for (int i = 0; i < nums.size(); ++i){
        if (nums[i] == 0){
            int j = i;
            int step = 1;
            while(step > nums[j]){
                if (nums[i]+i == nums.size()-1) return true;
                j--;
                step++;
                if (j < 0) return false;
            } 
        }
    }
    return true;
}
