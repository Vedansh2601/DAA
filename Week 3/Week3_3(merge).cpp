#include<iostream>
using namespace std;
void merge(int arr[],int l, int m, int r)
{
	int n1 = (m-l+1), n2 = r-m;
	int L[n1], R[n2];
	int k = l;
	for(int i = 0; i < n1; i++)
	{
		L[i] = arr[l+i];
	}
	for(int i = 0; i < n2; i++)
	{
		R[i] = arr[m+1+i];
	}
	int i = 0, j =0;
	while(i < n1 && j < n2)
	{
		if(L[i] < R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}
	while(i<n1)
		arr[k++] = L[i++];
	while(j<n2)
		arr[k++] = R[j++];
}
void mergesort(int arr[],int l,int r)
{
	if(l<r)
	{
		int m = l + (r-l)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
void searchin(int arr[],int n)
{
	mergesort(arr,0,n-1);
	for(int i = 0;i< (n-1);i++)
	{
		if(arr[i] == arr[i+1])
		{
			cout << "Found!!\n";
			return;
		}
	}
	cout << "Not Found\n";
}
int main()
{
	int arr[10] = {75,65,1,65,2,6,86,2,75,8};
	searchin(arr,10);
}
