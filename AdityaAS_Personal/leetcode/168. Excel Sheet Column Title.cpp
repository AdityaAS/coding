class Solution {
public:
    
    char title(int num){
        // if(num == 0) return 'Z';
        return 'A' + num;
    }
    
    string convertToTitle(int A) {
        string result = "";
        while(A > 0)
        {
            A = A-1;
            result = result + title(A%26);
            A = A/26;
        }
        reverse(result.begin(), result.end());
        return result;

    }
    
};