#include <vector>
#include <string> 
#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int value(char ch){
        int val = ch - 'A';
        return val + 1;
    }

    int titleToNumber(string A) {
        
        reverse(A.begin(), A.end());
        
        int result = 0;
        
        for(int i=0;i<A.size();i++){
            result = result + pow(26, i) * value(A[i]);
        }
        
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.titleToNumber("ZZ") << endl;
    return 0;
}