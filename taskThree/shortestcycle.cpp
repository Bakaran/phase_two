#include "shortestcycle.h"

void shortestCycle::tsp(QVector<bool> visited, int current, int count, int cost, int &answer, int start, QVector<int> V)
{
    if (count == states.size())
    {
        if (graph.contains({current,start}) && answer > (cost + graph[{current,start}]))
        {
            answer = cost + graph[{current,start}];
            answerVector.clear();
            for (auto itr = V.begin(); itr != V.end(); itr++)
                answerVector.push_back(*itr);
        }
        else if (graph.contains({start,current}) && answer > (cost + graph[{start,current}]))
        {
            answer = cost + graph[{start,current}];
            answerVector.clear();
            for (auto ii = V.begin(); ii != V.end(); ii++)
                answerVector.push_back(*ii);
        }
        return;
    }
    for (int i = 0; i < states.size(); i++)
    {
        if (!visited[states[i]])
        {
            if (graph.contains({states[i],current}))
            {
                visited[states[i]] = true;
                V.push_back(states[i]);
                tsp(visited, states[i], count + 1, cost + graph[{states[i],current}], answer,start,V);
                visited[states[i]] = false;
            }
            else if (graph.contains({current,states[i]}))
            {
                visited[states[i]] = true;
                V.push_back(states[i]);
                tsp(visited,states[i],count + 1,cost + graph[{current,states[i]}],answer,start,V);
                visited[states[i]] = false;
            }
        }
    }
}

shortestCycle::shortestCycle()
{
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

void shortestCycle::shortst_cycle(int start)
{
    int answer = INF;
    QVector<bool> visited(vertex, true);
    for (int i = 0; i < states.size(); i++)
        visited[states[i]] = false;
    QVector<int> Vector;
    Vector.push_back(start);
    tsp(visited, start, 0, 0, answer, start, Vector);
    answerVector.push_back(start);
    cout << "Cost : " << answer << endl;
    for (auto itr = answerVector.begin(); itr != answerVector.end(); itr++)
    {
        cout << loc[*itr].toStdString();
        if (itr != answerVector.end() - 1)
            cout <<" -> ";
    }
    cout << endl;
}

void shortestCycle::add_states(int number)
{
    states.push_back(number);
}
