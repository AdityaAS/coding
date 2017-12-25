#include<iostream>
using namespace std;

int minimum(int a,int b,int c){
	return (a<b && a<c)?a:(b<c?b:c);
}

int main(int argc, char const *argv[])
{
	int sum;
	int setLength;
	cin>>sum;
	cin>>setLength;
	int *arr = new int[setLength];
	for (int i = 0; i < setLength; ++i)
	{
		cin>>arr[i];
	}
	bool **dp = new bool*[setLength+1];
	for(int i=0;i<=setLength;i++){
		dp[i] = new bool[sum+1];
	}

	//Index 0 sum not zero
	for(int j=1;j<=sum;j++)
		dp[0][j]=false;

	//Sum 0
	for(int i=0;i<=setLength;i++)
		dp[i][0] = true;

	for(int j=1;j<=sum;j++){
		for(int i=1;i<=setLength;i++){
			int index =i-1;
			if(j<arr[index])
				dp[i][j] = dp[i-1][j];
			else{
				dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[index]];
			}
		}
	}
	cout<<dp[setLength][sum]<<endl;
	return 0;
}