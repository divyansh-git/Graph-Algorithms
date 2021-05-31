#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
using namespace std;
class Graph
{
    public:
    unordered_map<int,list<pair<int,int> > > g;
    void addEdge(int a, int b, int w, int bidir=1)
    {
        g[a].push_back(make_pair(b,w));
        if(bidir)
        g[b].push_back(make_pair(a,w));
    }
    bool bfs(int source,int parent,vector<int>&visited)
    {
        queue<pair<int,int> > q;
        q.push(make_pair(source,parent));
        while(!q.empty())
        {
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
            for(auto nbr: g[node])
            {
                if(!visited[nbr.first])
                {
                    visited[nbr.first]=1;
                    q.push(make_pair(nbr.first,node));
                }
                else if(nbr.first!=par)
                return true;
            }
        }
        return false;
    }
    bool cycle_detection_undirected_BFS(int n)
    {
        vector<int>visited(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
            if(bfs(i,-1,visited))
            return true;
            }
        }
        return false;
    }

};
int main()
{
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif
    Graph g;
    int n,e,a,w,b;
    bool bidir;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b>>w>>bidir;
        g.addEdge(a,b,w,bidir);
    }
    if(g.cycle_detection_undirected_BFS(n))
    cout<<"Cycle is present\n";
    else
    cout<<"Cycle is not present\n";
    return 0;
}