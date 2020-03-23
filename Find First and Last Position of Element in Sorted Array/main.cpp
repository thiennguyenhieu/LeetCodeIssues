/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

class Solution {
    int findFirstPos(vector<int>& nums, int target)
    {
       int left = 0;
       int right = nums.size() - 1;

       int mid = 0;
       int firstPos = nums.size();

       while (left <= right)
       {
          mid = left + (right - left) / 2;

          if (nums[mid] >= target)
          {
             firstPos = mid;
             right = mid - 1;
          }
          else
          {
             left = mid + 1;
          }
       }

       return firstPos;
    }
    
public:    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first_pos = findFirstPos(nums, target);
        int last_pos = findFirstPos(nums, target + 1) - 1;

        if (first_pos <= last_pos)
          return {first_pos, last_pos};
        
        return {-1, -1};
    }
};
