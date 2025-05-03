#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int e,n,c=0;
    cin >> e;
    cin >> n;
    vector <int> vec(n);
    for(int i = 0; i<n;i++)
    {
        cin >> vec[i];
    }
    sort(vec.rbegin(),vec.rend());
    vector <int> fill(n,2);
    for(int i = 0; i<n;i++)
    {
        if(vec[i] <= e && fill[i] > 0)
        {
            e -= vec[i];
            fill[i]--;
            c++;
            i--;
            if(e == 0)
            {
                break;
            }
        }
    }
    if(e != 0)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << c;
    }
}