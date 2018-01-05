#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,r,p;
	cin>>n;
	cin>>r;
	cin>>p;
	int** dp = new int*[n+1];
	for(int i=0;i<=n;i++)
		dp[i] = new int[n+1];

	for (int i = 1; i <=n; ++i)
	{
		dp[i][0]=1;
		dp[i][i]=1;
		for(int j=1;j<i;j++){
			dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%p;
		}
	}
	cout<<dp[n][r]<<endl;
	return 0;
}