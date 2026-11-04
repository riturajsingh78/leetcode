class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int i = 0;

        while( i < nums.size() ){
            int j = i+1;
              while( j < nums.size()){
                if(nums[i] + nums[j] == target) {
                return {i,j};
                }
                j++;
              }
    
                i++;
             }
        return {};

    }
};