#include<iostream>
using namespace std;
void ssort(int a[], int n, int &c, int &s)
{
	int i,j,m;
	c = 0;
	s = 0;
	for(i=0;i<n;i++)
	{
		m = i;
		j = i+1;
		while(j < n)
		{
			if(a[j] < a[m])
			{
				m = j;
			}
			c++;
			j++;
		}
		if(i != m)
		{
			int temp = a[i];
			a[i] = a[m];
			a[m] = temp;
			s++;
		}
	}
}
int main()
{
	int a[20],x,n,c,s;
	cout << "Enter no of arrays - ";
	cin >> x;
	for(int i = 0; i < x; i++)
	{
		c=0;
		s=0;
		cout << "Enter size of " << (i+1) << " array - ";
		cin >> n;
		cout << "Enter elements - ";
		for(int j = 0; j < n; j++)
		{
			cin >> a[j];
		}
		ssort(a,n,c,s);
		cout << "Sorted array - ";
		for(int j = 0; j < n; j++)
		{
			cout << a[j] << " ";
		}
		cout << "\nComparision - " << c;
		cout << "\nShifts - " << s <<"\n";
	}
}
