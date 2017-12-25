#include<iostream>
using namespace std;

int minimum(int a,int b,int c){
	return (a<b && a<c)?a:(b<c?b:c);
}

int main(int argc, char const *argv[])
{
	string str1,str2;
	cin>>str1>>str2;
	int m = str1.length();
	int n = str2.length();

	int** dp = new int*[m+1];

	for(int i=0;i<=m;i++){
		dp[i] = new int[n+1];
		dp[i][0]=i;
	}

	for(int j=0;j<=n;j++){
		dp[0][j]=j;
	}	

	for (int i = 1; i <=m; ++i)
	{
		for(int j=1;j<=n;j++){
			if(str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else{
				dp[i][j] = 1+ minimum(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
			}
		}
	}

	cout<<dp[m][n]<<endl;
	return 0;
}