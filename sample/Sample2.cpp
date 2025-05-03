#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
int main()
{
    int nv,nh,c=0,h,sum = 0,max = -20,mi = -1;
    cin >> nv;
    cin >> nh;
    cin >> h;
    vector <int> vil(nv);
    for(int i = 0; i<nv;i++)
    {
        cin >> vil[i];
        sum += vil[i];
        if(max <= vil[i])
        {
            max = vil[i];
            mi = i;
        }
    }
    if(max > h)
    {
        int s = accumulate(vil.begin(),vil.begin() + (mi + 1),0);
        vil.erase(vil.begin(),vil.begin() + mi + 1);
        c = mi+1;
        sum -= s;
    }
    if((nh*h) >= sum)
    {
        cout << c<<endl;
    }
    else
    {
        int i = 0;
        while(nh*h < sum)
        {
            sum -= vil[i++];
            c++;
        }
        cout << c<<endl;
    }
}