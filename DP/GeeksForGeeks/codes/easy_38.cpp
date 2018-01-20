#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int maximum(int a,int b){
	return a>b?a:b;
}

int main(int argc, char const *argv[])
{
	int N,temp;
	cin>>N;
	vector<int> arr;
	vector<int> dp(N,0);
	for(int i=0;i<N;i++){
		cin>>temp;
		arr.push_back(temp);
	}


	dp[0] =1;
	int max =1;
	for(int i=1;i<N;i++){
		dp[i] =1;
		for(int j=0;j<i;j++){
			int val = abs(arr[i]-arr[j]);
			if(val==1)
				dp[i] = maximum(dp[i],dp[j]+1);
		}

		max = maximum(dp[i],max);
	}

	cout<<max<<endl;

	return 0;
}