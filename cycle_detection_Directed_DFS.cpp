#include<iostream>
#include<unordered_map>
#include<list>
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
    bool DFS_helper(int source,vector<int> &visited,vector<int> &dfs_visited)
    {
        visited[source]=1;
        dfs_visited[source]=1;
        for(auto node: g[source])
        {
            if(!visited[node.first])
            {
                visited[node.first]=1;
               if(DFS_helper(node.first,visited,dfs_visited))
               return true;
            }
            else if(dfs_visited[node.first])
            return true;
        }
        dfs_visited[source]=0;
        return false;
    }
    bool cycle_detection_directed_DFS(int n)
    {
        vector<int> visited(n+1,0);
        vector<int> dfs_visited(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
            if(DFS_helper(i,visited,dfs_visited))
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
    if(g.cycle_detection_directed_DFS(n))
    cout<<"Cycle is present\n";
    else
    cout<<"Cycle is not present\n";
    return 0;
}
