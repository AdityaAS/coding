class Solution {
public:
    void setZeroes(vector<vector<int>>& A) {
        
        bool lastrow = false;
        bool lastcol = false;
        
        int rowsize = A.size();
        int colsize = A[0].size();
        
        for(int j=0;j<A[0].size();j++){
            if(A[rowsize-1][j] == 0){lastrow=true;break;}        
        }
        for(int j=0;j<A.size();j++){
            if(A[j][colsize-1] == 0){lastcol=true;break;}        
        }
        
        for(int i=0;i<A.size()-1;i++){
            for(int j=0;j<A[i].size()-1;j++){
                if(A[i][j] == 0){
                    A[rowsize-1][j] = 0;
                    A[i][colsize-1] = 0;
                }
            }
        }

        for(int i=0; i<colsize-1; i++){
            if(A[rowsize-1][i] == 0){
                for(int j=0;j<rowsize-1;j++){
                    A[j][i] = 0;
                }
            }
        }
        
        for(int i=0; i<rowsize-1; i++){
            if(A[i][colsize-1] == 0){
                for(int j=0; j<colsize-1; j++){
                    A[i][j] = 0;
                }
            }
        }
        
        if(lastrow){
            for(int i=0;i<colsize;i++){
                A[rowsize-1][i] = 0;
            }
        }
        
        if(lastcol){
            for(int i=0;i<rowsize;i++){
                A[i][colsize-1] = 0;
            }
        }
        
    }
};