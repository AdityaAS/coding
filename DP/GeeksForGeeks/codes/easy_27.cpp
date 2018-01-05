#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,r,p;
	cin>>n;
	cin>>r;
	int value =1;
	for(int i=0;i<r;i++){
		value = value*(n-i);
	}
	cout<<value<<endl;
	return 0;
}