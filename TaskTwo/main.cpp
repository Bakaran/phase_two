#include <iostream>
#include <QMap>
#include <QString>
using namespace std;
int INF = 9999;
QVector <int> qv;
QVector <int> min_path;
int min_cost = 9999;
bool promising(QMap <pair<int,int>,int> graph,QVector<int> path,int next,int curr,int cost)
{
    for (auto ii = path.begin(); ii != path.end(); ii++)
    {
        if (*ii == next)
        {
            return false;
        }
    }
    if (graph.contains({curr,next}) == true || graph.contains({next,curr}) == true)
    {
        return true;
    }
    return false;
}
void shrtst_path(QMap <pair<int,int>,int> graph,QMap<int,QString> loc,QVector<int> path,int cost,int curr,int dst)
{
    if (curr == dst)
    {
        if (min_cost > cost)
        {
            if (min_path.size() != 0)
            {
                min_path.clear();
            }
            for (auto ii = path.begin(); ii != path.end(); ii++)
            {
                min_path.push_back(*ii);
            }
            min_path.push_back(-1);
            min_cost = cost;
            return;
        }
        else if (min_cost == cost)
        {

            for (auto ii = path.begin(); ii != path.end(); ii++)
            {
                min_path.push_back(*ii);
            }
            min_path.push_back(-1);
            return;
        }
    }
    for (auto ii = loc.begin(); ii != loc.end(); ii++)
    {
        if (promising(graph,path,ii.key(),curr,cost) == true)
        {
            path.push_back(ii.key());
            if(graph.contains({ii.key(),curr}) == true)
            {
                shrtst_path(graph,loc,path,(cost + graph[{ii.key(),curr}]),ii.key(),dst);
            }
            else if(graph.contains({curr,ii.key()}) == true)
            {
                shrtst_path(graph,loc,path,(cost + graph[{curr,ii.key()}]),ii.key(),dst);
            }
            path.pop_back();
        }
    }
}
void tsp(QMap <pair<int,int>,int> graph,bool *visited,int *states,int current,int size,int count,int cost,int &answer,int start,QVector<int> V)
{
    if (count == size)
    {
        if (graph.contains({current,start}))
        {
            if (answer > (cost + graph[{current,start}]))
            {
                answer = cost + graph[{current,start}];
                qv.clear();
                for (auto ii = V.begin(); ii != V.end(); ii++)
                {
                    qv.push_back(*ii);
                }
            }
        }
        else if (graph.contains({start,current}))
        {
            if (answer > (cost + graph[{start,current}]))
            {
                answer = cost + graph[{start,current}];
                qv.clear();
                for (auto ii = V.begin(); ii != V.end(); ii++)
                {
                    qv.push_back(*ii);
                }
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (!visited[states[i]])
        {
            if (graph.contains({states[i],current}))
            {
                visited[states[i]] = true;
                V.push_back(states[i]);
                tsp(graph,visited,states,states[i],size,count + 1,cost + graph[{states[i],current}],answer,start,V);
                visited[states[i]] = false;
            }
            else if (graph.contains({current,states[i]}))
            {
                visited[states[i]] = true;
                V.push_back(states[i]);
                tsp(graph,visited,states,states[i],size,count + 1,cost + graph[{current,states[i]}],answer,start,V);
                visited[states[i]] = false;
            }
        }
    }
}
void shrtst_cycle(QMap <pair<int,int>,int> graph,QMap <int,QString> loc,int *states,int size,int start)
{
    int answer = INF;
    bool *visited = new bool[loc.size()];
    for (int i = 0; i < loc.size(); i++)
    {
        visited[i] = true;
    }
    for (int i = 0; i < size; i++)
    {
        visited[states[i]] = false;
    }
    QVector<int> V;
    V.push_back(start);
    tsp(graph,visited,states,start,size,0,0,answer,start,V);
    qv.push_back(start);
    cout << answer << endl;
    for (auto ii = qv.begin(); ii != qv.end(); ii++)
    {
        cout << loc[*ii].toStdString();
        if (ii != qv.end() - 1)
        {
            cout <<"->";
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
        if (order == 1)
        {
            int cnt = 1;
            cin >> start >> dst;
            QVector <int> path;
            path.push_back(start);
            shrtst_path(graph,loc,path,0,start,dst);
            cout <<"min cost is : "<< min_cost << endl;
            cout << cnt <<".";
            for (auto ii = min_path.begin(); ii != min_path.end(); ii++)
            {
                if (*ii == -1)
                {
                    cout << endl;
                    if (ii != min_path.end()-1)
                    {
                        cnt++;
                        cout << cnt << ".";
                    }
                }
                else
                {
                    cout << loc[*ii].toStdString();
                    if (*(ii + 1) != -1)
                    {
                        cout << "->";
                    }
                }
            }
        }
        else if (order == 2)
        {
            cout << "size,start : ";
            cin >> n >> start;
            int *states = new int[n];
            for (int i = 0 ; i < n ; i++)
            {
                cin >> states[i];
            }
            shrtst_cycle(graph,loc,states,n,start);
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
    graph.insert({8,9},3);
    choose_opt(loc,graph);
}
