Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?



vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> result;
    if (nums1.size() == 0 || nums2.size() == 0) return result;
    int i = 0;
    int j = 0;
    std::sort(nums1.begin(),nums1.end());
    std::sort(nums2.begin(),nums2.end());
    while(i < nums1.size() && j < nums2.size()){
        if (nums1[i] < nums2[j]) i++;
        else if (nums1[i] > nums2[j]) j++;
        else{
           result.push_back(nums1[i]);
            i++;
            j++;
        } 
    }
    return result;
}


If both nums1 and nums2 are so huge that neither fit into the memory, sort them individually (external sort), then read 2 elements from each array at a time in memory, record intersections.
