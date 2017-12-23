#include <iostream>
#include <cstdlib>

using namespace std;

// Adds value of A[index] to appropriate places in the BIT;
void addValue(int index, int* BIT, int value, int length)
{
	while(index <= length)
	{
		BIT[index] += value;
		index += (index& (-index));
	}
}

// Gets cumulative sum from range 1 to index
int sum(int index, int* BIT, int length){
	int sum = 0;
	while(index > 0)
	{
		sum += BIT[index];
		index -= (index & (-index));
	}
	return sum;
}


int main(int argc, char const *argv[])
{
	
	int asize = 10;
	int tsize = asize+1;	
	
	int* A = (int*)malloc(sizeof(int)*(1+asize));
	int* BIT = (int*)malloc(sizeof(int)*tsize);

	for(int i=1;i<=asize;i++)
	{
		A[i] = i;
		BIT[i]=0;
	}

	for(int i=1;i<=tsize;i++){
		update(i, BIT, A[i], asize);
	}

	for(int i=1;i<=tsize;i++){
		cout << sum(i, BIT, tsize) << " ";
	}
	
	cout << endl;
	int cum = 0;

	for(int i=1;i<=tsize;i++){
		cum += A[i];
		cout << cum << " ";
	}
	cout << endl;

	

	return 0;
}