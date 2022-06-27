#include "taskone.h"

taskone::taskone()
{

}

void taskone::backtracking(QMap <int,pair<int,int>> car,int row,int col,int curr,int camera,int end,QVector<int> path,int pre_empty)
{
    if ( curr == end )
    {
        cout << "Move : " << path.size() << endl;
        for (auto ii = path.begin(); ii != path.end(); ii++)
        {
            cout << *ii << endl;
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
        car[car_numb].first = curr + 1;
        car[car_numb].second = curr + 2;
    }
    if (promising(car,{curr - 2,curr - 1},camera,pre_empty,'B') == true)
    {
        car[car_numb].first = curr - 1;
        car[car_numb].second = curr;
        path.push_back(car_numb);
        backtracking(car,row,col,curr - 2,camera,end,path,curr);
        path.pop_back();
        car[car_numb].first = curr - 2;
        car[car_numb].second = curr - 1;
    }
    if (promising(car,{curr + col,curr +(2*col)},camera,pre_empty,'N') == true)
    {
        car[car_numb].first = curr;
        car[car_numb].second = curr + col;
        path.push_back(car_numb);
        backtracking(car,row,col,curr + (2*col),camera,end,path,curr);
        path.pop_back();
        car[car_numb].first = curr + col;
        car[car_numb].second = curr + col + col;
    }
    if (promising(car,{curr - (2*col),curr - col},camera,pre_empty,'B') == true)
    {
        car[car_numb].first = curr - col;
        car[car_numb].second = curr;
        path.push_back(car_numb);
        backtracking(car,row,col,curr - (2*col),camera,end,path,curr);
        path.pop_back();
        car[car_numb].first = curr - col - col;
        car[car_numb].second = curr - col;
    }
}


bool taskone::promising(QMap <int,pair<int,int>> car,pair<int,int> m,int cam,int pre_empty,QChar p)
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
