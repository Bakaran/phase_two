#include <iostream>
#include <QMap>
#include <QString>
using namespace std;
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
           // shrtst_path(graph,loc,start,dst);
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
