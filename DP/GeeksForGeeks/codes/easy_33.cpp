#include<iostream>
using namespace std;

int maximum(int a,int b){
	return a>b?a:b;
}

int main(int argc, char const *argv[])
{
	int m,n;
	cin>>m>>n;
	int **matrix = new int*[m];
	for(int i=0;i<m;i++){
		matrix[i] = new int[n];
		for(int j=0;j<n;j++)
			cin>>matrix[i][j];
	}

	for(int i=1;i<m;i++){
		matrix[i][0] = matrix[i-1][0]+ matrix[i][0];
	}

	int max = INT_MIN;

	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			matrix[i][j] = maximum(matrix[i-1][j],matrix[i-1][j-1])+matrix[i][j];

			if(i==m-1){
				max = maximum(max,matrix[i][j]);
		}
		}

	}

	cout<<max<<endl;
	return 0;
}