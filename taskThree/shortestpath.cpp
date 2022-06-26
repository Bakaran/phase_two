#include "shortestpath.h"

bool shortestPath::promising(QVector<int> path, int next,int curr,int cost)
{
    for (auto itr = path.begin(); itr != path.end(); itr++)
        if (*itr == next)
            return false;
    if (graph.contains({curr,next}))
    {
        if (min_cost < cost + graph[{curr,next}])
            return false;
        return true;
    }
    else if (graph.contains({next,curr}))
    {
        if (min_cost < cost + graph[{next,curr}])
            return false;
        return true;
    }
    return false;
}

shortestPath::shortestPath()
{
    min_cost = INF;
    FILE* ptr = fopen("city.txt", "r");
    char stringOne[10], stringTwo[10];
    int number;
    if (ptr == NULL)
    {
        cout << "Error!!! file can't be opened" << endl;
        return;
    }
    while(fscanf(ptr,"%s %s %i", stringOne, stringTwo, &number)>0)
    {
        if(!strcmp(stringOne, "size"))
            vertex = stoi(stringTwo);
        else if(!strcmp(stringOne, "vertex"))
        {
            fscanf(ptr,"%s", stringOne);
            loc.insert(stringTwo[0] - 'a', stringOne);
            number = vertex - 1;
            while(number-- && (fscanf(ptr,"%s %s", stringTwo, stringOne) > 0))
                loc.insert(stringTwo[0] - 'a', stringOne);
        }
        else
            graph.insert({stringOne[0] - 'a', stringTwo[0] - 'a'}, number);
    }
    fclose(ptr);
}

void shortestPath::shortst_path(QVector<int> path, int cost,int current,int distance)
{
    if (current == distance)
    {
        if (min_cost > cost)
        {
            if (min_path.size())
                min_path.clear();
            for (auto itr = path.begin(); itr != path.end(); itr++)
                min_path.push_back(*itr);
            min_path.push_back(-1);
            min_cost = cost;
            return;
        }
        else if (min_cost == cost)
        {
            for (auto itr = path.begin(); itr != path.end(); itr++)
                min_path.push_back(*itr);
            min_path.push_back(-1);
            return;
        }
    }
    for (auto itr = loc.begin(); itr != loc.end(); itr++)
    {
        if (promising(path, itr.key(), current, cost))
        {
            path.push_back(itr.key());
            if(graph.contains({itr.key(),current}))
                shortst_path(path,(cost + graph[{itr.key(),current}]),itr.key(),distance);
            else if(graph.contains({current,itr.key()}) == true)
                shortst_path(path,(cost + graph[{current,itr.key()}]),itr.key(),distance);
            path.pop_back();
        }
    }
}

void shortestPath::print()
{
    int cnt =  1;
    cout <<"min cost : "<< min_cost << endl;
    cout << cnt <<" . ";
    for (auto itr = min_path.begin(); itr != min_path.end(); itr++)
    {
        if (*itr == -1)
        {
            cout << endl;
            if (itr != min_path.end()-1)
            {
                cnt++;
                cout << cnt << " . ";
            }
        }
        else
        {
            cout << loc[*itr].toStdString();
            if (*(itr + 1) != -1)
                cout << " -> ";
        }
    }
}
