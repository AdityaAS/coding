#include <iostream>
#include <vector>

using namespace std;

int* merge(int* A, int low, int high, int mid)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int* res = (int*) malloc(sizeof(int)*(alen+blen));
	
	while(i<alen && j<blen)
	{
		if(A[i] < B[j]){
			res[k++] = A[i++];
		}
		else{
			res[k++] = B[j++];
		}
	}

	if(i!=alen){
		while(j < blen)	res[k++] = B[j++];
	}
	else{
		while(i < alen) res[k++] = A[i++];
	}
	return res;
}

void mergesort(int* A, int low, int high)
{
	if(low < high){
		int mid = (low+high)/2;
		mergesort(A, low, mid);
		mergesort(A, mid+1, high);
		merge(A, low, high, mid);
	}
}

int main(int argc, char const *argv[])
{
	int k;
	cin >> k;
	
	int* A = (int*)malloc(sizeof(int)*k);
	int ind = 0;
	
	while(k--)
	{
		int t;
		cin >> t;
		A[ind++] = t;
	}

	mergesort(A, 0, k-1);

	//Insertion Sort begins...
	for(int i=1; i<A.size(); i++)
	{

		int temp = A[i];
		int j = i-1;

		while(j>=0 && temp < A[j])
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = temp;
	}
    
    for(int i=0;i<A.size();i++){
    	cout << A[i] << " ";
    }
    cout << endl;
}