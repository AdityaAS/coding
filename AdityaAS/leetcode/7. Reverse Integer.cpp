class Solution {
public:
    int reverse(int A) 
    {
        int a = abs(A);
        long rev = 0;     
    
        while(a != 0){
            int rem = a%10;
            a = a/10;
            // if(rev*10 < (long)rev*10)return 0;
            // if(rev*10 + rem < (long)rev*10 + rem) return 0;
            rev = rev*10 + rem;
            // if(rev < 0) return 0;
        }
        
        if(rev >= INT_MAX || rev < 0) return 0;
        
        if(A<0)return -(int)rev;
        else return (int)rev;
    
    }
};