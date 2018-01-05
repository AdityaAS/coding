#include<iostream>
#include<cmath>
using namespace std;
int maximum(int a,int b){
	return a>b?a:b;
}
int main(int argc, char const *argv[])
{
	int m,n;
	cin>>m>>n;
	int** arr = new int*[m];
	for (int i = 0; i < m; ++i)
	{
		arr[i] = new int[n];
	}
	int ** dp = new int*[m];
	for(int i=0;i<m;i++){
		dp[i] = new int[n];
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			dp[i][j]=1;
		}
	}

	for(int j=1;j<n;j++){
		int diff = abs(arr[0][j]-arr[0][j-1]);
		if(diff==1){
			dp[0][j] = dp[0][j-1]+1;
		}
	}

	for(int i=1;i<m;i++){
		int diff = abs(arr[i][0]-arr[i-1][0]);
		if(diff==1){
			dp[i][0] = dp[i-1][0]+1;
		}
	}	

	int diff;
	int max =0;
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			diff = abs(arr[i-1][j] -arr[i][j]);
			dp[i][j]=0;
			if(diff==1){
				dp[i][j] = dp[i-1][j];
			}
			diff = abs(arr[i][j-1]-arr[i][j]);
			if(diff==1){
				dp[i][j] = maximum(dp[i][j-1],dp[i][j]);
			}
			dp[i][j] +=1;

			max = maximum(max,dp[i][j]);
		}
	}
	cout<<max<<endl;
	return 0;
}