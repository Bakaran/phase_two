#ifndef SHORTESTCYCLE_H
#define SHORTESTCYCLE_H

#include <bits/stdc++.h>
#include <QMap>
#include <QString>
#include <QVector>
using namespace std;
#define INF 1000000000

class shortestCycle
{
private:
    QMap<pair<int, int>, int> graph;
    QMap<int, QString> loc;
    QVector<int> states, answerVector;
    int vertex;
    void tsp(QVector<bool>, int, int, int, int &, int, QVector<int>);
public:
    shortestCycle();
    void shortst_cycle(int);
    void add_states(int);

};

#endif // SHORTESTCYCLE_H
