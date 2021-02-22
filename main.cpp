#include "GraphAM.hpp"
#include <iostream>
#include <cassert>

using namespace std;


void add_edge_test()
{
    GraphAM g(10);
    g.add_edge(1, 1);
    assert((g.get_edges() == 1 && g.has_edge(1, 1) == true)  && "Testing add_edge.");

}

void del_edge_test()
{
    GraphAM g(0);
    assert((g.del_edge(1, 1) == false) && "Testing del_edge with no edge to delete.");

    GraphAM g2(10);
    g2.add_edge(1, 1);
    assert((g2.del_edge(1, 1) == true) && "Testing del_edge with edge to delete.");
}

void has_node_test()
{
    GraphAM g(0);
    assert((g.has_node(1) == false) && "Testing has_node with no node.");

    GraphAM g2(10);
    assert((g2.has_node(1) == true) && "Testing has_node with node.");
}

void has_edge_test()
{
    GraphAM g(0);
    assert((g.has_edge(1, 1) == false) && "Testing has_edge with no edge.");

    GraphAM g2(10);
    g2.add_edge(1, 1);
    assert((g2.has_edge(1, 1) == true) && "Testing has_edge with edge.");
}

void empty_test()
{
    GraphAM g(0);
    assert((g.empty() == true) && "Testing empty.");

    GraphAM g2(10);
    assert((g2.empty() == false) && "Testing empty.");
}

void constructors_test()
{
    GraphAM g(10);
    assert((g.get_nodes() == 10) && "Testing constructor.");

    GraphAM g2(0);
    assert((g2.get_nodes() == 0) && "Testing constructor.");

    GraphAM g3(g2);
    assert((g3.get_nodes() == 0) && "Testing constructor.");

    GraphAM g4(std::move(g));
    assert((g4.get_nodes() == 10) && "Testing constructor.");

}

void get_nodes_test()
{
    GraphAM g(10);
    assert((g.get_nodes() == 10) && "Testing get_nodes with nodes.");

    GraphAM g2(0);
    assert((g2.get_nodes() == 0) && "Testing get_nodes with no nodes.");
}

void get_edges_test()
{
    GraphAM g(0);
    assert((g.get_edges() == 0) && "Testing get_edges with no edge.");

    GraphAM g2(10);
    g2.add_edge(1, 1);
    assert((g2.get_edges() == 1) && "Testing get_edges with edge.");
}





int main()
{
    constructors_test();
    add_edge_test();
    del_edge_test();
    has_edge_test();
    has_node_test();
    get_edges_test();
    get_nodes_test();
    empty_test();



    GraphAM g(10);
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
    cout << "Kolejno odwiedzane wierzchołki algorytmem BFS:" << endl;
    g.BFS();
    cout << endl;
    cout << "Kolejno odwiedzane wierzchołki algorytmem DFS:" << endl;
    g.DFS();
    cout << endl;
    return 0;
}