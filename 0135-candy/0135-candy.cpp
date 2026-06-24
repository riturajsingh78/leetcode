class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
          
        if(n==0) return 0;
        if(n==1) return 1;

        vector<int>L2R (n,1);
        vector<int>R2L (n,1);
         

         for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                L2R[i]=L2R[i]+L2R[i-1];
            }
         }
         for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                R2L[i]=R2L[i]+R2L[i+1];
            }
         }
          int sum =0;
         for(int i=0;i<n;i++){
            sum = sum+max(L2R[i],R2L[i]);
         }
         return sum;
    }
};