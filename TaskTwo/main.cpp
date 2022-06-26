#include <iostream>
#include <QMap>
#include <QString>
using namespace std;
int INF = 9999;
int find_min(int dist[10],bool touch[10])
{
    int min = INF,index = -1;
    for (int i = 0; i < 10 ; i++)
    {
        if (touch[i] == false)
        {
            if (dist[i] != INF && dist[i] >= 0 && dist[i] < min)
            {
                min = dist[i];
                index = i;
            }
        }
    }
    return index;
}
void find_path(QMap <int,QVector<int>> &path,int start,int end)
{
    path[end].clear();
    for (auto ii = path[start].begin() ; ii != path[start].end(); ii++)
    {
        path[end].push_back(*ii);
    }
    path[end].push_back(end);
    return;
}
void shrtst_path(QMap <pair<int,int>,int> graph,QMap<int,QString> loc,int start,int dst)
{
    bool touch[10];
    int dist[10];
    QMap <int,QVector<int>> path;
    for (int i = 0; i < 10; i++)
    {
        if (i != start)
        {
            QVector<int> v;
            v.push_back(start);
            v.push_back(i);
            path.insert(i,v);
        }
        dist[i] = INF;
        touch[i] = false;
    }
    touch[start] = true;
    dist[start] = 0;
    for (int i = 0; i < 10; i++)
    {
        if (graph.contains({i,start}) == true)
        {
            dist[i] = graph[{i,start}];
        }
        else if (graph.contains({start,i}) == true)
        {
            dist[i] = graph[{start,i}];
        }
    }
    for (int i = 0; i < 9; i++)
    {
        int index = -1;
        index = find_min(dist,touch);
        touch[index] = true;
        for (int i = 0 ; i < 10; i++)
        {
            if (touch[i] == false)
            {
                if (dist[index] != INF)
                {
                    if (graph.contains({index,i}))
                    {
                        if (dist[i] > dist[index] + graph[{index,i}])
                        {
                            dist[i] = dist[index] + graph[{index,i}];
                            find_path(path,index,i);
                        }
                    }
                    else if (graph.contains({i,index}))
                    {
                        if (dist[i] > dist[index] + graph[{i,index}])
                        {
                            dist[i] = dist[index] + graph[{i,index}];
                            find_path(path,index,i);
                        }
                    }
                }
            }
        }
    }
    cout << dist[dst] << endl;
    for (auto ii = path[dst].begin(); ii != path[dst].end(); ii++)
    {
        cout << loc[*ii].toStdString();
        if (ii != path[dst].end() - 1)
        {
            cout << "->";
        }
    }
    cout << endl;
}
void choose_opt(QMap <int,QString> loc,QMap <pair<int,int>,int> graph)
{
    int order = 0;
    while(order != 3)
    {
        cout <<"1.shrtst_path"<<endl;
        cout <<"2.shrtst_cycle"<<endl;
        cout <<"3.exit"<<endl;
        cout <<"--------------"<<endl;
        cout <<"order : ";
        int start,dst;
        int n;
        cin >> order;
        switch (order)
        {
        case 1:
            cin >> start >> dst;
           shrtst_path(graph,loc,start,dst);
        break;
        case 2:
            cout << "size,start : ";
            cin >> n >> start;
            int *states = new int[n];
            for (int i = 0 ; i < n ; i++)
            {
                cin >> states[i];
            }
          //  shrtst_cycle(graph,loc,states,n,start);
        break;
        }
    }
}
int main(void)
{
    QMap <int,QString> loc;
    loc.insert(0,"Parking");//A
    loc.insert(1,"Shopping center");//B
    loc.insert(2,"Hospital");//C
    loc.insert(3,"Mountain park");//D
    loc.insert(4,"Terminal");//E
    loc.insert(5,"Airport");//F
    loc.insert(6,"Restaurant");//G
    loc.insert(7,"School");//H
    loc.insert(8,"Department");//I
    loc.insert(9,"university");//J
    QMap <pair<int,int>,int> graph;
    graph.insert({0,1},3);
    graph.insert({0,5},9);
    graph.insert({1,2},2);
    graph.insert({1,4},9);
    graph.insert({5,4},8);
    graph.insert({2,3},2);
    graph.insert({2,6},9);
    graph.insert({4,6},7);
    graph.insert({4,8},9);
    graph.insert({3,7},20);
    graph.insert({6,8},5);
    graph.insert({7,9},9);
    graph.insert({0,3},6);
    graph.insert({1,3},4);
    graph.insert({1,5},9);
    graph.insert({5,2},16);
    graph.insert({5,9},18);
    graph.insert({2,4},8);
    graph.insert({4,3},11);
    graph.insert({4,9},10);
    graph.insert({3,6},9);
    graph.insert({6,7},4);
    graph.insert({7,8},1);
    choose_opt(loc,graph);
}
