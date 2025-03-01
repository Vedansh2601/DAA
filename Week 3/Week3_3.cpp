#include <bits/stdc++.h>
#include<vector>
using namespace std;
int position(vector<int>& arr, int l,int h)
{
	int p = arr[h];
	int i = l-1,j = l;
	for(j = l; j < h; j++)
	{
		if(arr[j] < p)
			swap(arr[++i],arr[j]);
	}
	swap(arr[i+1],arr[h]);
	return(i+1);
}
void qsort(vector<int>& arr,int l,int h)
{
	if(l<h)
	{
	    int pi = position(arr,l,h);
	    qsort(arr,l,pi-1);
	    qsort(arr,pi+1,h);
	}
}
void checkduplicate(vector<int> arr)
{
    int f = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == arr[i+1])
        {
            f = 1;
            break;
        }
    }
    if(f)
        cout << "Yes\n";
    else
        cout << "No\n";
}
int main()
{
	vector<int> arr = {4,6,3,2,88,4,6,1,3,8,99};
	int n = arr.size();	
	qsort(arr,0,n-1);
	checkduplicate(arr);
	 for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

