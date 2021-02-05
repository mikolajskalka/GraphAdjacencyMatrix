#include "GraphAM.hpp"
#include <iostream>

using namespace std;

int main()
{
    GraphAM g;
    for(int i = 0; i < 10; i++)
    {
        g.add_node();
    }
    g.add_edge(0, 1);
    g.add_edge(0, 4);
    g.add_edge(0, 8);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    g.add_edge(4, 5);
    g.add_edge(4, 6);
    g.add_edge(4, 7);
    g.add_edge(8, 9);
    g.add_edge(7, 9);

    g.display();
    g.BFS();
    cout << endl;
    g.DFS();
    cout << endl;
    cout << g.get_nodes() << endl;
    return 0;
}