class Solution {
public:
    long long sumAndMultiply(int n) {
         int revn = 0;
        int sum = 0;

        //reversing the number
        while(n>0){
            int digit = n%10;
            revn = revn*10 + digit;
            n /= 10;
            sum += digit;
        }

        int ans = 0;

        // just taking the non-zero digits in account
        while(revn > 0){
            int digit = revn%10;
            if(digit > 0) ans = ans*10 + digit;
            revn /= 10;
        }
        
        return 1LL*ans*sum;
    }
};