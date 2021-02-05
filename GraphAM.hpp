#pragma once 

#include <vector>
#include <iostream>
#include <queue>


template <typename T>
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


    void DFS(int node);
    void BFS(int node);

    void add_node();
    void add_edge(int node1, int node2);

    private:

    void DFS(int node, std::vector<bool> visited);

    

    private:
    std::vector<std::vector<int>> am;
    int nodes;

};

template<typename T>
GraphAM<T>::GraphAM(int n): nodes(n), am(n)
{
};

template <typename T>
GraphAM<T>::GraphAM(const GraphAM<T>& source): am(source.am)
{
};

template <typename T>
GraphAM<T>::GraphAM(GraphAM&& source): am(std::move(source.am))
{
};

template <typename T>
bool GraphAM<T>::empty() const
{
    if(nodes == 0) return true;
    return false;
}


template <typename T>
void GraphAM<T>::display() const
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

template <typename T>
void GraphAM<T>::add_node()
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

template <typename T>
void GraphAM<T>::add_edge(int node1, int node2)
{
    if(node1 >= nodes || node2 >= nodes) throw "Node is not in the graph";
    am[node1][node2] += 1;
    am[node2][node1] += 1;
}

template <typename T>
void GraphAM<T>::BFS(int root)
{
    if(empty()) return;
    std::vector<bool> visited (nodes, false);
    std::queue<T> queue;
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

template <typename T>
void GraphAM<T>::DFS(int root)
{
    if(empty()) return;
    std::vector<bool> visited (nodes, false);
    DFS(root, visited);
}

template <typename T>
void GraphAM<T>::DFS(int root, std::vector<bool> visited)
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
