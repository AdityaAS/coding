#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin>>N;
	int* dp = new int[N+1];
	int* values = new int[3];
	values[0]=3;
	values[1]=5;
	values[2]=10;

	for(int i=1;i<=N;i++)
		dp[i]=0;
	dp[0]=1;

	for(int i=0;i<3;i++){
		for(int j=1;j<=N;j++){
			int val = j-values[i];
			if(val>=0){
				dp[j] += dp[val];
			}
		}
	}
	cout<<dp[N]<<endl;
	return 0;
}