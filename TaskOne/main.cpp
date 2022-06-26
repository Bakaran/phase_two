#include <iostream>
#include <QMap>
using namespace std;
int car_number = -1;
int Size_Of_parking = 4;
QVector <int> qv;
using namespace std;
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
    //backtracking(cars,visited,camera,start,end,v);
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
