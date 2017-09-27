Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

slower solution:
int trap(vector<int>& height) {
    int water = 0;
    if (height.empty()) return 0;
    vector<int>left;
    vector<int>right;
    for(int i = 0; i < height.size(); i++){
        left.push_back(maxLeft(i,height));
        right.push_back(maxRight(i,height));
    }
    for (int i = 0; i < height.size(); i++){
        water += std::min(left[i],right[i])-height[i];
    }
    return water;
}
int maxLeft(int i,vector<int>& height){
    if (i == 0) return height[0];
    return std::max(maxLeft(i-1,height),height[i]);
}
int maxRight(int i,vector<int>& height){
    if (i == height.size()-1) return height.back();
    return std::max(maxRight(i+1,height),height[i]);
}


faster solution:
//instead of using new vector to store leftMax and rightMax, we use two variables to store the max value from left and right, each time compare the maxLeft and maxRight, and use the minimum max to minus current value, and we get the water in that element.
int trap(vector<int>& height) {
    int water = 0;
    if (height.empty()) return 0;
    int low = 0, high = height.size()-1;
    int maxLeft = 0, maxRight = 0;
    while(low < high){
        if (height[low] < height[high]){
            if (height[low]>maxLeft) maxLeft = height[low];
            else water += maxLeft - height[low];
            low++;
        }else{
            if (height[high]>maxRight) maxRight = height[high];
            else water += maxRight - height[high];
            high--;
        }
    }
    return water;
}
