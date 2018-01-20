#include<iostream>
#include<vector>
using namespace std;

int maximum(int a,int b){
	return a>b?a:b;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int t;
	vector<vector<int> > triangle;

	for(int i=0;i<n;i++){
		vector<int> temp;
		for(int j=0;j<=i;j++){
			cin>>t;
			temp.push_back(t);
		}
		triangle.push_back(temp);
	}


	for(int i=1;i<n;i++){
		int size =triangle[i].size();

		for(int j=0;j<size;j++){
			int left =j-1;
			int leftMax = INT_MIN;
			if(left>=0){
				leftMax = triangle[i-1][left];
			}

			int right = j;
			int rightMax = INT_MIN;
			if(right<triangle[i-1].size()){
				rightMax = triangle[i-1][right];
			}

			triangle[i][j]= triangle[i][j]+ maximum(leftMax,rightMax);

		}
	}

	// for(int i=0;i<n;i++){
	// 	int size = triangle[i].size();
	// 	for(int j=0;j<size;j++){
	// 		cout<<triangle[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	int max = INT_MIN;
	int i = triangle.size()-1;
	for(int j=0;j<triangle[i].size();j++){
		max = maximum(max,triangle[i][j]);
	}
	cout<<max<<endl;
	return 0;
}