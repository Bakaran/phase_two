#include <iostream>
#include <QMap>
#include <QStringList>
using namespace std;
QVector <int> p;
int car_numb = 0;
bool promising(QMap <int,pair<int,int>> car,pair<int,int> m,int cam,int pre_empty,QChar p)
{
    if (m.first == cam || m.second == cam)
    {
        return false;
    }
    if (p == 'N')
    {
        int empty = m.second;
        if (empty == pre_empty)
        {
            return false;
        }
    }
    else
    {
        int empty = m.first;
        if (empty == pre_empty)
        {
            return false;
        }
    }
    for (auto ii = car.begin(); ii != car.end(); ii++)
    {
        if (ii.value().first == m.first && ii.value().second == m.second)
        {
            car_numb = ii.key();
            return true;
        }
    }
    return false;
}
void backtracking(QMap <int,pair<int,int>> car,int row,int col,int curr,int camera,int end,QVector<int> path,int pre_empty)
{
    if ( curr == end )
    {
        for (auto ii = path.begin(); ii != path.end(); ii++)
        {
            p.push_back(*ii);
        }
        return;
    }
    if (promising(car,{curr + 1,curr + 2},camera,pre_empty,'N') == true)
    {
        car[car_numb].first = curr;
        car[car_numb].second = curr + 1;
        path.push_back(car_numb);
        backtracking(car,row,col,curr + 2,camera,end,path,curr);
        path.pop_back();
    }
    if (promising(car,{curr - 2,curr - 1},camera,pre_empty,'B') == true)
    {
        car[car_numb].first = curr - 1;
        car[car_numb].second = curr;
        path.push_back(car_numb);
        backtracking(car,row,col,curr - 2,camera,end,path,curr);
        path.pop_back();
    }
    if (promising(car,{curr + col,curr +(2*col)},camera,pre_empty,'N') == true)
    {
        car[car_numb].first = curr;
        car[car_numb].second = curr + col;
        path.push_back(car_numb);
        backtracking(car,row,col,curr + (2*col),camera,end,path,curr);
        path.pop_back();
    }
    if (promising(car,{curr - (2*col),curr - col},camera,pre_empty,'B') == true)
    {
        car[car_numb].first = curr - col;
        car[car_numb].second = curr;
        path.push_back(car_numb);
        backtracking(car,row,col,curr - (2*col),camera,end,path,curr);
        path.pop_back();
    }
}
int main(void)
{
    int row = 0, col = 0;
    cin >> row >> col;
    int number_of_cars = 0;
    cin >> number_of_cars;
    QMap<int,pair<int,int>> car;
    for (int i = 0 ; i < number_of_cars; i++)
    {
        pair <int,int> m;
        cin >> m.first >> m.second;
        car.insert(i+1,m);
    }
    int start = 0,camera = 0,end = 0;
    cin >> start >> camera >> end;
    QVector <int> path;
    backtracking(car,row,col,start,camera,end,path,start);
    for (auto ii = p.begin(); ii != p.end(); ii++)
    {
        cout << *ii << endl;
    }
}
