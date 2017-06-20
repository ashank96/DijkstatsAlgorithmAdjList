
#include<iostream>
#include<list>

using namespace std;

class AdjNode{
    int w;
    int v;
public:
    AdjNode(int w,int v){
        this->w=w;
        this->v=v;
    }
    int getW(){
        return w;
    }
    int getV(){
        return v;
    }
};

class Graph{
    int V;
    list<AdjNode>*adj;
public:
    Graph(int V){
        this->V=V;
        adj=new list<AdjNode>[V];
    }
    void addEdge(int u,int v,int w){
        AdjNode node(w,v);
        adj[u].push_back(node);
    }
    int extract_minDist_index(int*d,bool*spSet){
        int smallest=INT_MAX;
        int index=0;
        for(int i=0;i<V;i++)
            if(spSet[i]==false&&smallest>d[i]){
                smallest=d[i];
                index=i;
            }
       // cout<<index;
        return index;
    }

    void Dijkstra(int s){
        int d[V];
        bool spSet[V];
        int parent[V];
        for(int i=0;i<V;i++){
            d[i]=INT_MAX;
            spSet[i]=false;
            parent[i]=-1;
        }
        d[s]=0;
        int counter=0;//keeps record of the no. of vertices processed
        while(counter!=V-1){
            int u=extract_minDist_index(d,spSet);
            spSet[u]=true;
            for(list<AdjNode>::iterator i=adj[u].begin();i!=adj[u].end();i++)
                    if(spSet[i->getV()]==false&&d[i->getV()]>d[u]+i->getW()){
                        d[i->getV()]=d[u]+i->getW();
                        parent[i->getV()]=u;
                    }
            counter++;
            }
        for(int i=0;i<V;i++)
            cout<<d[i]<<"  parent(="<<i<<") ="<<parent[i]<<endl;
    }

};

int main(){

     int V=9;

    Graph g(V);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(1, 0, 4);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 1, 8);
    g.addEdge(3, 5, 14);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 2, 7);
    g.addEdge(4, 3, 9);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(5, 2, 4);
    g.addEdge(5, 4, 10);
    g.addEdge(5, 3, 14);
    g.addEdge(6, 8, 6);
    g.addEdge(6, 7, 1);
    g.addEdge(6,5,2);
    g.addEdge(7, 8, 7);
    g.addEdge(7, 1, 11);
    g.addEdge(7, 0, 8);
    g.addEdge(7, 6, 1);
    g.addEdge(8, 7, 7);
    g.addEdge(8, 2, 2);
    g.addEdge(8, 6, 6);

    g.Dijkstra(0);



}
