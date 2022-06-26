#include <iostream>
#include <QMap>
using namespace std;
int car_number = -1;
int Size_Of_parking = 4;
QVector <int> qv;
using namespace std;
void backtracking(QMap<int , pair<int,int>> cars,bool visited[16],int camera,int curr,int want,QVector<int> v)
{
    if (want == curr)
    {
        qv.clear();
        for (auto ii = v.begin(); ii != v.end(); ii++)
        {
            qv.push_back(*ii);
        }
        return;
    }
    visited[curr - 1] = true;
    if (promising(visited,cars,camera,{curr+1,curr+2},'N') == true)
    {
        v.push_back(car_number);
        backtracking(cars,visited,camera,curr+2,want,v);
    }
    if (promising(visited,cars,camera,{curr-2,curr-1},'B') == true)
    {
        v.push_back(car_number);
        backtracking(cars,visited,camera,curr-2,want,v);
    }
    if (promising(visited,cars,camera,{curr+Size_Of_parking,curr+(2*Size_Of_parking)},'N') == true)
    {
        v.push_back(car_number);
        backtracking(cars,visited,camera,curr+(2*Size_Of_parking),want,v);
    }
    if (promising(visited,cars,camera,{curr-(2*Size_Of_parking),curr-(Size_Of_parking)},'B') == true)
    {
        v.push_back(car_number);
        backtracking(cars,visited,camera,curr-(2*Size_Of_parking),want,v);
    }
    return;
}
int main(void)
{
    bool visited[16];
    for (int i = 0 ; i < 16; i++)
    {
        visited[i] = false;
    }
    QMap<int , pair<int,int>> cars;
    cars.insert(1,{1,2});
    cars.insert(2,{3,4});
    cars.insert(3,{5,9});
    cars.insert(4,{6,7});
    cars.insert(5,{10,11});
    cars.insert(6,{12,16});
    cars.insert(7,{13,14});
    int camera = 8;
    int start = 15,end = 7;
    QVector <int> v;
    backtracking(cars,visited,camera,start,end,v);
    for (auto ii = qv.begin(); ii != qv.end(); ii++)
    {
        cout << *ii;
        if (ii != qv.end() - 1)
        {
            cout << "->";
        }
    }
    cout <<endl;
    return 0;
}
