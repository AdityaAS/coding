#include<iostream>
#include<vector>

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

	dp[0] = arr[0];

	for(int i=1;i<N;i++){
		dp[i] = arr[i]+arr[0];
		for(int j=1;j<i;j++){
			int d = j+1;
			int n = i+1;
			if(n%d==0){
				dp[i] = maximum(dp[i],arr[i]+dp[j]);
			}
		}
	}

	for(int i=0;i<N;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

	return 0;
}