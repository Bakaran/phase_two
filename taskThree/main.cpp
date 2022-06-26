#include <bits/stdc++.h>
#include <taskthree.h>
#include <shortestpath.h>
#include <shortestcycle.h>
using namespace std;

int main()
{
    shortestCycle tt;
    tt.add_states(3);
    tt.add_states(4);
    tt.add_states(6);
    tt.shortst_cycle(2);
    cout << "------------" << endl;
    shortestPath two;
    two.shortst_path({0}, 0, 0, 3);
    two.print();
    taskThree three;
    three.kruskals_mst();
}
