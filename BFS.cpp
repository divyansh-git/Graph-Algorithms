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
    void BFS_helper(int source,vector<int> &visited)
    {
        queue<int> q;
        visited[source]=1;
        q.push(source);
        while(!q.empty())
        {
            int temp=q.front();
            cout<<q.front()<<" ";
            q.pop();
        for(auto node: g[temp])
        {
            if(!visited[node.first])
            {
                visited[node.first]=1;
                q.push(node.first);
            }
        }
        }
    }
    void BFS(int n)
    {
        vector<int> visited(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            BFS_helper(i,visited);
        }
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
    g.BFS(n);
    return 0;
}
