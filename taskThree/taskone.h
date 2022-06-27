#ifndef TASKONE_H
#define TASKONE_H

#include <iostream>
#include <QMap>
#include <QStringList>
#include <QVector>
using namespace std;

class taskone
{
private:
    bool promising(QMap <int,pair<int,int>> car,pair<int,int> m,int cam,int pre_empty,QChar p);
public:
    taskone();
    void backtracking(QMap <int,pair<int,int>> car,int row,int col,int curr,int camera,int end,QVector<int> path,int pre_empty);
    int car_numb;
};

#endif // TASKONE_H
