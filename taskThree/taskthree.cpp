#include "taskthree.h"

taskThree::taskThree()
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
        {
            vertex = stoi(stringTwo);
            for(int i = 0; i < vertex; i++)
            {
                parent.push_back(-1);
                rank.push_back(1);
            }
        }
        else if(!strcmp(stringOne, "vertex"))
        {
            fscanf(ptr,"%s", stringOne);
            sign.insert({stringTwo[0], stringOne});
            number = vertex - 1;
            while(number-- && (fscanf(ptr,"%s %s", stringTwo, stringOne) > 0))
                sign.insert({stringTwo[0], stringOne});
        }
        else
        {
            edgelist.push_back({number, {stringOne[0], stringTwo[0]}});
        }
    }
    fclose(ptr);
}

int taskThree::find(char character)
{
    if (parent[character - 'a'] == -1)
        return character - 'a';
    return parent[character - 'a'] = find('a' + parent[character - 'a']);
}

void taskThree::unite(char characterOne, char characterTwo)
{
    int indexOne = find(characterOne);
    int indexTwo = find(characterTwo);
    if (indexOne != indexTwo)
    {
        if (rank[indexOne] < rank[indexTwo])
        {
            parent[indexOne] = indexTwo;
            rank[indexTwo] += rank[indexOne];
        }
        else
        {
            parent[indexTwo] = indexOne;
            rank[indexOne] += rank[indexTwo];
        }
    }
}

void taskThree::addEdge(char vertexOne, char vertexTwo, int weight)
{
    edgelist.push_back({weight, {vertexOne, vertexTwo}});
}

void taskThree::print(string vertexOne, string vertexTwo)
{
    cout << vertexOne;
    for(int i = 0; i < 12 - vertexOne.size(); i++)
        cout << ' ';
    cout << "--  ";
    cout << vertexTwo <<endl;
}

void taskThree::kruskals_mst()
{
    sort(edgelist.begin(), edgelist.end());
    int answer = 0;
    for (auto edge : edgelist) {
        char vertexOne = edge.second.first;
        char vertexTwo = edge.second.second;
        int weight = edge.first;
        if (find(vertexOne) != find(vertexTwo))
        {
            unite(vertexOne, vertexTwo);
            answer += weight;
            print(sign.find(vertexOne)->second, sign.find(vertexTwo)->second);
        }
    }
    cout << "\nMinimum Cost : " << answer << endl;
}
