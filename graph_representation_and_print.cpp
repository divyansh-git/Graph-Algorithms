#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class Graph
{
    public:
    unordered_map<int,list<pair<int,int> > > g;
    void addEdge(int a, int b, int w, bool bidir=true)
    {
        g[a].push_back(make_pair(b,w));
        if(bidir)
        g[b].push_back(make_pair(a,w));
    }
    void print()
    {
        unordered_map<int,list<pair<int,int> > >::iterator itr;
        for(itr=g.begin();itr!=g.end();itr++)
        {
            cout<<itr->first<<" -->";
            for(auto node: g[itr->first])
            {
                cout<<"("<<node.first<<","<<node.second<<") ";
            }
            cout<<"\n";
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
    g.addEdge(1,2,1);
    g.addEdge(2,4,1);
    g.addEdge(4,7,1);
    g.addEdge(7,3,1);
    g.addEdge(7,9,1);
    g.addEdge(9,8,1);
    g.addEdge(8,1,1);
    g.addEdge(2,5,1,false);
    g.addEdge(5,6,1,false);
    g.addEdge(6,3,1,false);
    g.addEdge(2,3,1,false);
    g.print();
    return 0;
}
