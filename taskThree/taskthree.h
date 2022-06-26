#ifndef TASKTHREE_H
#define TASKTHREE_H

#include <bits/stdc++.h>
using namespace std;

class taskThree
{
private:
    map<char, string> sign;
    vector<pair<int, pair<char, char>>> edgelist;
    int vertex;
    vector<int> parent;
    vector<int> rank;
    int find(char);
    void unite(char, char);
    void addEdge(char, char, int);
    void print(string, string);

public:
    taskThree();
    void kruskals_mst();
};

#endif // TASKTHREE_H
