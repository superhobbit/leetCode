Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]



  vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> res;
      vector<int> result;
      vector<int> test;
      if (nums.empty()) return res;
      test = nums;
      std::sort(test.begin(),test.end());
      vector<int>::iterator front = test.begin();
      vector<int>::iterator end = test.end();

      end--;
      while (front-test.begin() != end-test.begin()){
          if (*front + *end > target){
              end--;
              continue;
          }
          else if (*front + *end < target){
              front++;
              continue;
          }else{
              res.push_back(*front);
              res.push_back(*end);
              break;
          }
      }
      for (vector<int>::iterator b = nums.begin(); b != nums.end(); b++){
          if (*b == res[0]) {
              result.push_back(b-nums.begin());
              continue;
          }
          if (*b == res[1]) {
              result.push_back(b-nums.begin());
              continue;
          }
      }
      std::sort(result.begin(),result.end());
      return result;
  }


