#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &parent, char i)
{
    if (parent[i - 'a'] == -1)
        return i - 'a';

    return parent[i - 'a'] = find(parent, parent[i - 'a'] + 'a');
}
void unite(vector<int> &parent,vector<int> &rank, char x, char y)
{
    int s1 = find(parent, x);
    int s2 = find(parent, y);

    if (s1 != s2) {
        if (rank[s1] < rank[s2]) {
            parent[s1] = s2;
            rank[s2] += rank[s1];
        }
        else {
            parent[s2] = s1;
            rank[s1] += rank[s2];
        }
    }
}

class Graph {
    vector<pair<int, pair<char, char>>> edgelist;
    int V;
    vector<int> parent;
    vector<int> rank;

public:
    Graph(int V) {
        this->V = V;
        for (int i = 0; i < V; i++) {
            parent.push_back(-1);
            rank.push_back(1);
        }
    }

    void addEdge(char x, char y, int w)
    {
        edgelist.push_back({w, {x, y}});
    }

    void kruskals_mst()
    {
        sort(edgelist.begin(), edgelist.end());
        int ans = 0;
        for (auto edge : edgelist) {
            char x = edge.second.first;
            char y = edge.second.second;
            int w = edge.first;
            if (find(parent, x) != find(parent, y)) {
                unite(parent, rank, x, y);
                ans += w;
                cout << x << " -- " << y << " == " << w
                     << endl;
            }
        }
        cout << "Minimum Cost Spanning Tree: " << ans << endl;
    }
};
int main()
{
    Graph g(10);
    g.addEdge('a', 'b', 3);
    g.addEdge('a', 'f', 9);
    g.addEdge('b', 'c', 2);
    g.addEdge('b', 'e', 9);
    g.addEdge('f', 'e', 8);
    g.addEdge('c', 'd', 2);
    g.addEdge('c', 'g', 9);
    g.addEdge('e', 'g', 7);
    g.addEdge('e', 'i', 9);
    g.addEdge('d', 'h', 20);
    g.addEdge('g', 'i', 5);
    g.addEdge('h', 'j', 9);
    g.addEdge('a', 'd', 6);
    g.addEdge('b', 'd', 4);
    g.addEdge('b', 'f', 9);
    g.addEdge('f', 'c', 16);
    g.addEdge('f', 'j', 18);
    g.addEdge('c', 'e', 8);
    g.addEdge('e', 'd', 11);
    g.addEdge('e', 'j', 10);
    g.addEdge('d', 'g', 9);
    g.addEdge('g', 'h', 4);
    g.addEdge('h', 'i', 1);
    g.kruskals_mst();
    return 0;
}
