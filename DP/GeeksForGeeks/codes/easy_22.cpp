#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin>>N;
	int* dp = new int[N+1];
	dp[0]=0;
	dp[1]=1;
	dp[2] =2;
	for(int i=3;i<=N;i++){
		dp[i] = dp[i-1]+dp[i-2];
	}
	cout<<dp[N]<<endl;
	return 0;
}