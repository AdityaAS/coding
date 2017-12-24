#include<iostream>
#include<vector>
#define minimum(a,b,c) ((a<b && a<c)?a:(b<c?b:c))
using namespace std;

int main(int argc, char const *argv[])
{
	vector<int> arr;
	int n,first_index=0,second_index=0,third_index=0;
	cin>>n;
	int term =n;
	arr.push_back(1);
	n--;
	while(n>=0){
		int first = arr[first_index]*2;
		int second = arr[second_index]*3;
		int third = arr[third_index]*5;

		int min = minimum(first,second,third);
		if(first == min)
			first_index++;
		if(second==min)
			second_index++;
		if(third == min)
			third_index++;

		arr.push_back(min);
		n--;

	}
	cout<<arr[term-1]<<endl;
	return 0;
}