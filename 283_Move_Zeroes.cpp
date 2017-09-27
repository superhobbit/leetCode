Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.


void moveZeroes(vector<int>& nums) {
    vector<int>::iterator a;
    int *p = &nums.front();
    int *q = &nums.back();
    int count = 0;
    while (p < q){
        a = nums.begin();
        if (*p==0) {
            nums.erase(a+count);
            nums.push_back(0);
            q--;
            continue;
        }
        count++;
        p++;
    }
}
