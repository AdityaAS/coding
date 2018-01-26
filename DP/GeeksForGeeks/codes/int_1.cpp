#include<iostream>
using namespace std;

int maximum(int a,int b){
	return a>b?a:b;
}

int main(int argc, char const *argv[])
{
	int N;
	cin>>N;
	int* val = new int[N];
	int* W = new int[N];

	for(int i=0;i<N;i++)
		cin>>val[i];

	for(int i=0;i<N;i++)
		cin>>W[i];
	int w;
	cin>>w;

	int K[N+1][w+1];

	for(int i=0;i<=N;i++){
		for(int j=0;j<=w;j++){
			if(i==0 || j==0)
				K[i][j]=0;

			else{

				if(W[i-1]<=j){
					K[i][j] = maximum(K[i-1][j-W[i-1]]+val[i-1],K[i-1][j]);
				}
				else{
					K[i][j] = K[i-1][j];
				}
			}
		}
	}

	cout<<K[N][w];
	return 0;
}