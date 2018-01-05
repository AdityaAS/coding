#include<iostream>
using namespace std;
#define maximum(a,b,c) ((a>b && a>c)?a:(b>c)?b:c)

int main(int argc, char const *argv[])
{
	
	string str1,str2;
	cin>>str1>>str2;
	int m = str1.length();
	int n = str2.length();

	int lcs[2][n+1];

	int b=1;
	int index;

	for(int i=m;i>=0;i--){
		index = 1-b;
		for(int j=n;j>=0;j--){
			if(i==m || j==n){
				lcs[index][j]=0;
			}
			else{
				if(str1[i] == str2[j]){
					lcs[index][j] = 1+ lcs[b][j+1];
				}
				else
					lcs[index][j] = lcs[b][j+1];
				lcs[index][j] = maximum(lcs[index][j],lcs[b][j],lcs[index][j+1]);
			}
		}
		b=1-b;
	}
	cout<<lcs[index][0]<<endl;
	return 0;
}