class Solution {
public:
    bool isPalindrome(int A) {
        
        if(A<0)return false;
        
        if(A/10 == 0)return true;
        
        string num = to_string(abs(A));
        string revnum = num;
        
        reverse(revnum.begin(), revnum.end());

        if(num == revnum)return true;
        else return false;
    }
};