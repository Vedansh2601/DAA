#include <bits/stdc++.h>
using namespace std;
vector<int> dijk(vector< pair<int,int> > g[],int s,int n)
{
    vector<int> distance(n,100000);
    vector<bool> visited(n,false);
    set< pair<int,int> > pq;
    
    pq.insert({0,s});
    distance[s] = 0;
    
    while(!pq.empty())
    {
        auto node = *pq.begin();
        int p = node.second;
        int pd = node.first;
        
        pq.erase(pq.begin());
        
        if(visited[p])
            continue;
        
        visited[p] = true;
        
        for(auto child : g[p])
        {
            int c = child.first;
            int cd = child.second;
            
            if(distance[p] + cd < distance[c])
            {
                distance[c] = distance[p] + cd;
                pq.insert({distance[c],c});
            }
        }
        
    }
    return distance;
}
int main()
{
    int n,e;
    cin >> n>>e;
    vector<pair<int,int> > g[n];
    for(int i = 0;i<e;i++)
    {
        int s,d,w;
        cin >> s >> d >> w;
        g[s].push_back({d,w});
    }
    vector<int> distance = dijk(g,0,n);
    int c = 0;
    cout << endl;
    for(int i: distance)
    {
        cout << c<<" : "<<i<<endl;
        c++;
    }
}