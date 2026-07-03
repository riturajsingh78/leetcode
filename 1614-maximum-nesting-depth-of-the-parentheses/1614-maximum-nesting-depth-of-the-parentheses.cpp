class Solution {
public:
    int maxDepth(string s) {
        
        int n = s.size();
        int depth = 0;
        int ans = 0;

        for(char ch: s){
             if(ch=='('){
                depth++;
                ans = max(ans,depth);
             }
             else if(ch==')'){
                depth--;
             }
            
        }
    
       return ans;
    }
};