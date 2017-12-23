#include<iostream>
using namespace std;
#define maximum(a,b) (a>b?a:b)

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	int n = str.length();
	int dp[n+1][n+1];

    for (int i=0; i<=n; i++)
    	for (int j=0; j<=n; j++)
        	dp[i][j] = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(str[i]==str[j] && i!=j)
				dp[i][j]= 1 + dp[i-1][j-1];
			else
				dp[i][j] = maximum(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[n][n]<<endl;
	return 0;
}