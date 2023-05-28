#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE 50

int temp=0;
class graph 
{
    public:
    int V;
    bool e[MAX_SIZE][MAX_SIZE];
    graph()
    {
        V = MAX_SIZE;
        for(int i = 0; i < MAX_SIZE; i++)
            for (int j=0; j < MAX_SIZE; j++)
                e[i][j] = false;
    }
    graph (int vertices)
    {
         V = vertices;
        for(int i = 0; i < vertices; i++)
            for (int j=0; j < vertices; j++)
                e[i][j] = false;
    }
};

void addEdge(graph *g, int u, int v)
{
    g->e[u][v] = true;
    
}

void printGraph(graph *g)
{
    for(int i = 0; i < g->V; i++)
    {
        for(int j = 0; j < g->V; j++)
            cout << g->e[i][j] << " ";
        cout << endl;
    }
}

void BFS (graph *g,int s, bool *visited , int *dist, bool *bfs_done)
{
    queue<int> q;
    q.push(s);
    visited[s] =true;
    bfs_done[s]= true;
    dist[s]=0;
    int temp2;
    while(!q.empty())
    {   
        temp2= q.front();
        for (int i=0;i<g->V;i++)
        {
            if(g->e[temp2][i] && !visited[i])
            {
                dist[i] = dist[temp2] +1;
                visited[i] =true;
                q.push(i);
            }
        }
        q.pop();
    }
}
void reset(bool *visited , bool *bfs_done, int v)
{
    for (int i=0;i<v;i++)
    {
        visited[i] = false;
        bfs_done[i] = false;
    }
    temp=0;
}
int main ()
{   
    
    int v,e;
    cout  <<"No of vertices :";
    cin >>v;
    cout << "No of edges :";
    cin >> e;
    graph g(v);
    int dist[v];
    for  (int i=0; i<e ;i++)
    {   int u,v;
        // cout <<"The edge"<< i+1 <<" source:";
        cin >> u;
        // cout <<"The edge"<< i+1 <<" destination:";
        cin >> v;
        addEdge(&g,u,v);
    }
    bool visited[v],bfs_done[v];
    reset(visited,bfs_done,v);    
    BFS(&g,0,visited,dist,bfs_done);
    for (int i=1;i<v;i++)
        cout<<dist[i]<<endl;
    return 0;
}