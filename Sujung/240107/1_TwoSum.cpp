class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answers;
        bool flag = false;
        for(int i = 0; i <= nums.size()-1; i++){
            for(int j = 0; j <= nums.size()-1; j++){
                if(!flag && i!=j && nums[i]+nums[j] == target){
                    flag = true;
                    answers.push_back(i);
                    answers.push_back(j);
                }
            }
        }
        return answers;
    }
};
