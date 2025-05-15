#include<bits/stdc++.h>
using namespace std;

void fknapsack(vector<pair<int,pair<int,int> > >& s,int w)
{
    double wt = 0.0;
    sort(s.begin(),s.end(),[](pair<int,pair<int,int> > a , pair<int,pair<int,int> > b ){
        return (((double)a.second.first/a.second.second) > ((double)b.second.first/b.second.second));
    });
    vector<bool> visited(s.size(),false);
    int i = 0;
    for(auto p : s)
    {
        if(p.second.second <= w)
        {
            visited[i] = true;
            wt += p.second.first;
            w -= p.second.second;
        }
        else
        {
            visited[i] = true;
            wt += ((double)p.second.first/p.second.second) * w;
            w = 0;
            break;
        }
        i++;
    }
    cout << "Maximum value - " <<wt<<endl;
    cout << "index values - "<<endl;
    for (int j = 0; j < s.size(); j++)
    {
        if (visited[j])
        {
            cout << s[j].first << " - " << s[j].second.second << endl;
        }
    }
}

int main()
{
    int n,wt;
    cin >> n;
    vector<pair<int,pair<int,int> > > s;
    int w[n];
    int v[n];
    for(int i = 0;i<n;i++)
    {
        cin >> w[i];
    }
    for(int i = 0;i<n;i++)
    {
        cin >> v[i];
        s.push_back({i+1,{v[i],w[i]}});
    }
    cin >> wt;
    fknapsack(s,wt);
}