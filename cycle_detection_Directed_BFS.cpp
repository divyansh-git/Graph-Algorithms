#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
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
    bool topoSort(vector<int> &inDegree,int n)
    {
        int counter=0;
        queue<int> q;
        for(int i=1;i<=n;i++)
        {
            if(inDegree[i]==0)
            q.push(i);
        }
        while(!q.empty())
        {
            int source=q.front();
            q.pop();
            counter++;
            for(auto nbr: g[source])
            {
                inDegree[nbr.first]--;
                if(inDegree[nbr.first]==0)
                q.push(nbr.first);
            }
        }
        if(counter==n)
        return true;
        return false;
    }
    bool cycle_detection_directed_BFS(int n)
    {
        vector<int> inDegree(n+1,0);
        unordered_map<int,list<pair<int,int> > >::iterator itr;
        for(itr=g.begin();itr!=g.end();itr++)
        {
            for(auto node: g[itr->first])
            {
                inDegree[node.first]++;
            }
        }
       if(topoSort(inDegree,n))
       cout<<"Cycle is not there\n";
       else
       cout<<"Cycle is there\n";
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
    g.cycle_detection_directed_BFS(n);
    
    return 0;
}
