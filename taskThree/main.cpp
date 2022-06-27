#include <bits/stdc++.h>
#include <taskthree.h>
#include <shortestpath.h>
#include <shortestcycle.h>
#include <taskone.h>
using namespace std;

int main()
{
    while(true)
    {
        int number;
        system("cls");
        cout << "Menu : \n0. Solve puzzles\n1. Find Shoetest One\n2. MST\nEnter a number : ";
        cin >> number;
        if(number == 0)
        {
            QMap<int,pair<int,int>> car;
            taskone taskone;
            FILE* ptr = fopen("car.txt", "r");
            char stringOne[10];
            int numberOne, numberTwo;
            if (ptr == NULL)
            {
                cout << "Error!!! file can't be opened" << endl;
                break;
            }
            fscanf(ptr,"%i %i", &numberOne, &numberTwo);
            int row = numberOne, camera;
            int col = numberTwo;
            int start = (numberOne * numberTwo) * (numberOne * numberTwo + 1) / 2;
            while(fscanf(ptr,"%s %i", stringOne, &numberTwo)>0)
            {
                if(!strcmp(stringOne, "car"))
                {
                    int car_numb = numberTwo;
                    taskone.car_numb = car_numb;
                    for (int i = 0 ; i < car_numb; i++)
                    {
                        pair <int,int> m;
                        fscanf(ptr,"%i %i", &m.first, &m.second);
                        start -= m.first + m.second;
                        car.insert(i+1,m);
                    }
                }
                else if(!strcmp(stringOne, "camera"))
                {
                    camera = numberTwo;
                    start -= numberTwo;
                }
            }
            fclose(ptr);
            cout << "end : ";
            int end;
            cin >> end;
            taskone.backtracking(car, row, col, start, camera, end, {}, start);
        }
        else if(number == 1)
        {
            cout << "0. Path\n1. Cycle\nEnter a number : ";
            cin >> number;
            if(number == 0)
            {
                shortestPath two;
                int start, end;
                cout << "Start : ";
                cin >> start;
                cout << "End : ";
                cin>> end;
                two.shortst_path({0}, 0, start, end);
                two.print();
            }
            else if(number == 1)
            {
                shortestCycle two;
                int start, number, tmp;
                cout << "Start : ";
                cin >> start;
                cout << "Number of crossings : ";
                cin >> number;
                while(number--)
                {
                    cin >> tmp;
                    two.add_states(tmp);
                }
                two.shortst_cycle(start);
            }
            else
                cout << "Erorr!!! Invalid data" << endl;
        }
        else if(number == 2)
        {
            taskThree three;
            three.kruskals_mst();
        }
        else
            cout << "Erorr!!! Invalid data" << endl;
        system("pause");
    }
    return 0;
}
