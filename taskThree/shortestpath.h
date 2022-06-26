#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include <bits/stdc++.h>
#include <QMap>
#include <QString>
#include <QVector>
using namespace std;
#define INF 1000000000

class shortestPath
{
private:
    QMap<pair<int, int>, int> graph;
    QMap<int, QString> loc;
    QVector<int> min_path;
    int min_cost, vertex;
    bool promising(QVector<int>, int, int, int);

public:
    shortestPath();
    void shortst_path(QVector<int>, int, int, int);
    void print();
};

#endif // SHORTESTPATH_H
