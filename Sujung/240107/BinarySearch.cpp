class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int en = nums.size()-1;
        while(st <= en){
            int idx = (st+en) /2;
            if(target == nums[idx]) return idx;
            if(target < nums[idx]) en = idx - 1;
            if(target > nums[idx]) st = idx + 1; 
        }
        return -1;
    }
};
