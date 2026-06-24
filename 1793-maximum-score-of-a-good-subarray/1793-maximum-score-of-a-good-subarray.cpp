class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        
        int n = nums.size();
        int i=k;
        int j=k;
        int currMin = nums[k];
        int result = nums[k];

        while(i> 0 || j<n-1){

            int leftvalue = (i>0) ? nums[i-1]: 0;

            int rightvalue = (j < n-1) ? nums[j+1] :0;

            if(leftvalue < rightvalue){
                j++;
                currMin = min(currMin,nums[j]);

            }
            else{
                i--;
                currMin = min(currMin,nums[i]);
            }
            result =max(result,currMin*(j-i+1));
        }
        return result;

    }
};