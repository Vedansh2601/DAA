#include<iostream>
#include<vector>
using namespace std;
int changes(vector<int>& v, int n)
{
    int l,r = (n/2) + 1,c = 0;
    if(n%2 == 0)
    {
        l = (n/2) - 2;
    }
    else
    {
        l = (n/2) - 1;
    }
    while(l >=0 && r < n)
    {
        if((v[l+1] - v[l]) != 1)
        {
            c++;
            v[l] = v[l+1] - 1;
        }
        if((v[r-1] - v[r]) != 1)
        {
            c++;
            v[r] = v[r-1] - 1;
        }
        r++;
        l--;
    }
    return c;
}
int main()
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i = 0;i<n;i++)
    {
        cin >> v[i];
    }
    cout << changes(v,n);
}