#include <bits/stdc++.h>
using namespace std;

void bellman(vector<pair<int,pair<int,int> > > g,int v,int e)
{
    vector<int> distance(v,INT_MAX);
    vector<int> parent(v,-1);
    distance[0] = 0;
    for(int i = 0; i < v-1; i++)
    {
        for(auto edge : g)
        {
            int s = edge.first, d = edge.second.first, w = edge.second.second;
            if((distance[s] != INT_MAX) && (distance[s] + w) < distance[d])
            {
                distance[d] = distance[s] + w;
                parent[d] = s;
            }
        }
    }
    for(auto edge : g)
        {
            int s = edge.first, d = edge.second.first, w = edge.second.second;
            if((distance[s] != INT_MAX) && (distance[s] + w) < distance[d])
            {
               cout << "Negative Cycle";
            }
        }
    for(int i = 0;i<v;i++)
    {
        if(parent[i] != -1)
            cout << parent[i] << " - " << i << " weight to reach "<<i<<" : "<<distance[i]<<endl;
    }
}
int main()
{
    int v,e;
    cin >> v >> e;
    vector<pair<int,pair<int,int> > > g;
    for(int i =0;i<e;i++)
    {
        int s,d,w;
        cin >> s >> d >> w;
        g.push_back({s, {d,w} });
    }
    bellman(g,v,e);
}