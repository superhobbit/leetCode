Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.


recover merge sort, I think it can be done without using extra space.

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> result(nums1.size());
    int j = 0, k = 0, i = 0;

        while(j < m || k < n){
            if (j < m && k < n){
                result[i] = min(nums1[j],nums2[k]);
                if (result[i++] == nums1[j]) ++j;
                else ++k;
            }else{
                result[i++] = j >= m ? nums2[k++] : nums1[j++];
            }
        }

    nums1 = result;
}
