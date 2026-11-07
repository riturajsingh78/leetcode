class Solution {
public:
    long long reverse(long long x) {
       
       long long rev = 0;
       long long ori = x;
       if(x < 0) 
         x=-x;
       while( x >=1){
        long long num = x%10;
        rev = (rev * 10)+num;
        x=x/10;
       }

       if (rev > INT_MAX || rev < INT_MIN)
            return 0;
        else if(ori < 0) return -rev;    
        else 
          return rev;

    }
};