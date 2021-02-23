#pragma once 

#include <vector>
#include <iostream>
#include <queue>



class GraphAM
{
    public:

    GraphAM() { nodes = 0; };
    GraphAM(int n);
    GraphAM(const GraphAM& source);
    GraphAM(GraphAM&& source);
    ~GraphAM() = default;


    bool empty() const;
    void display() const;
    void BFS() { BFS(0); };
    void DFS() { DFS(0); };
    int get_nodes() { return nodes; };
    int get_edges() { return edges; };
    bool has_edge(int node1, int node2);
    bool has_node(int node);
    void clear();


    void DFS(int node);
    void BFS(int node);

    void add_node();
    void del_node(int node);
    bool add_edge(int node1, int node2);
    bool del_edge(int node1, int node2);

    private:

    void DFS(int node, std::vector<bool> visited);

    

    private:
    int nodes;
    int edges;
    std::vector<std::vector<int>> am;

};


GraphAM::GraphAM(int n): nodes(n), edges(0), am(n, std::vector<int> (n))
{
};


GraphAM::GraphAM(const GraphAM& source): nodes(source.nodes), am(source.am)
{
};


GraphAM::GraphAM(GraphAM&& source): nodes(std::move(source.nodes)), am(std::move(source.am))
{
};


bool GraphAM::empty() const
{
    if(nodes == 0) return true;
    return false;
}



void GraphAM::display() const
{
    for(auto v : am)
    {
        for(auto i : v)
        {
            std::cout << i << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}


void GraphAM::add_node()
{
    if(empty())
    {
        am.push_back(std::vector<int> (1, 0));
        
    }
    else
    {
        am.push_back(std::vector<int> (nodes, 0));
        for(auto i = 0; i < nodes + 1; i++ )
        {
            am[i].push_back(0);
        }
    }
    nodes++;
}


bool GraphAM::add_edge(int node1, int node2)
{
    if(node1 >= nodes || node2 >= nodes) throw "Node is not in the graph";
    if(am[node1][node2] == 1 || am[node2][node1] == 1) throw "Edge already exists";
    am[node1][node2] = 1;
    am[node2][node1] = 1;
    edges++;
    return true;
}


void GraphAM::BFS(int root)
{
    if(empty()) return;
    std::vector<bool> visited (nodes, false);
    std::queue<int> queue;
    int node = root;
    queue.push(root);
    visited[node] = true;
    while(!queue.empty())
    {
        node = queue.front();
        queue.pop();
        std::cout << node << " ";

        for(int i = 0; i < nodes; i++)
        {
            if(am[node][i] == 1 && !visited[i])
            {
                queue.push(i);
                visited[i] = true;
            }
        }
        
    }
}


void GraphAM::DFS(int root)
{
    if(empty()) return;
    std::vector<bool> visited (nodes, false);
    DFS(root, visited);
}


void GraphAM::DFS(int root, std::vector<bool> visited)
{
    visited[root] = true;
    std::cout << root << " ";
    for(int i = root; i < nodes; i++)
    {
        if(!visited[i] && am[root][i] == 1)
        {
            DFS(i, visited);
        }
    }
}


bool GraphAM::del_edge(int node1, int node2)
{
    if(node1 > nodes || node2 > nodes) return false;
    if(am[node1][node2] == 1 || am[node2][node1] == 1)
    {
        am[node1][node2] = 0;
        am[node2][node1] = 0;
        edges--;
        return true;
    }
    return false;
}


bool GraphAM::has_edge(int node1, int node2)
{
    if(node1 > nodes || node2 > nodes) return false;
    if(am[node1][node2] == 1 || am[node2][node1] == 1) return true;
    return false;
}

bool GraphAM::has_node(int node)
{
    if(node < nodes) return true;
    return false;
}

void GraphAM::clear()
{
    nodes = 0;
    edges = 0;
    am = std::vector<std::vector<int>> (0);
}

void GraphAM::del_node(int node)
{
    if(node >= nodes) return;
    for(int i = 0; i < nodes; i++)
    {
        am[node][i] = 0;
        am[i][node] = 0;
    }
}