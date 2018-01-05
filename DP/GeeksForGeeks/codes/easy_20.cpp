#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int* dp = new int[n+1];
	dp[0]=1;
	dp[1]=1;

	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i] += (dp[j-1]*dp[i-j]);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}