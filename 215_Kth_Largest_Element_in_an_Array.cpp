Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.


自己看答案写的快排果然垃圾
int findKthLargest(vector<int>& nums, int k) {
    if (nums.empty()) return 0;
    int low = 0, high = nums.size()-1;
    int res = 0;
    res = partition(nums, low, high);
    while(res != k-1){
        if (res < k-1){
            low = res+1;
            res = partition(nums, low, high);
        }else if (res > k-1){
            high = res-1;
            res = partition(nums, low, high);
        }
    }
    return nums[k-1];
}
int partition(vector<int>& nums, int low, int high){
    int target = low;
    int p = high+1;
    while(1){
        while(target < high && nums[++target] >= nums[low]);
        while(low < p && nums[--p] <= nums[low]);
        if (target >= p) break;
        exchange(nums, target, p);
    }
    exchange(nums, low, p);
    return p;
}
void exchange(vector<int>& nums, int a, int b){
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}
