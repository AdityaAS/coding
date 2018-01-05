#include<iostream>
using namespace std;

int maximum(int a,int b){
	return a>b?a:b;
}

int main(int argc, char const *argv[])
{
	int m,n;
	cin>>m>>n;
	int **mat = new int*[m];
	for(int i=0;i<m;i++){
		mat[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			cin>>mat[i][j];
		}
	}


	for(int j=1;j<n;j++){
		mat[0][j] = mat[0][j]+mat[0][j-1];
	}

	for(int i=1;i<m;i++){
		mat[i][0] = mat[i][0]+mat[i-1][0];
	}	

	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			mat[i][j] = mat[i][j] + maximum(mat[i-1][j],mat[i][j-1]);
		}
	}

	cout<<(mat[m-1][n-1])/((double)(m+n-1))<<endl;
	return 0;
}