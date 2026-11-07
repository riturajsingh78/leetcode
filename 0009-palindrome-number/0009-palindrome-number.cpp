class Solution {
public:
    bool isPalindrome(long x) {
        long ori =x;
        if(x < 0) return false;
        long rev = 0;
        while(x!=0){
            long digit = x % 10;
            rev = rev * 10 + digit;
            x = x/10;
        }

        return (rev == ori);
            
    }

};