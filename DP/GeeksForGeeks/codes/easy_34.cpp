#include<iostream>
#include<map>
using namespace std;

int maximum(int a,int b,int c,int d){
	int val1 = a>b?a:b;
	int val2 = c>d?c:d;
	return val1>val2?val1:val2;
}

int getMaximum(int N,std::map<int, int>& map){
	if(N==1)
		return 0;
	if(N==2)
		return 1;
	if(N==3)
		return 2;

	if(map.find(N)!=map.end()){
		return map[N];
	}

	int a = getMaximum(N/2,map);
	int b = getMaximum(N/3,map);
	int c = getMaximum(N/4,map);

	int value = (N/2+N/3+N/4); 

	map[N] = maximum(value,a,b,c);

	return map[N];

}
int main(int argc, char const *argv[])
{
	int N;
	cin>>N;
	std::map<int, int> map;
	cout<<getMaximum(N,map)<<endl;
	return 0;
}