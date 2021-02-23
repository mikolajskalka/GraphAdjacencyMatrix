# GraphAdjacencyMatrix

Klasa reprezentująca graf nieskierowany jako macierz sąsiedztwa.

### Wprowadzenie:

W pliku main.cpp znajdują się testy zaimplementowanych metod. 
Plik main.cpp uruchamia się za pomocą pliku Makefile. W pliku Makefile znajdują się komendy pozwalające
na skompilowanie programu oraz jego uruchomienie. W tym celu należy wpisać w konsoli polecenie <br/>
`make all` <br/>
plik main.cpp zostanie skompilowany oraz uruchomiony, a na konsoli zostanie wyświetlona macierz sąsiedztwa
reprezentująca poniższy graf:

![image](./Graph.png)

Wyświetlone zostaną również kolejne wierzchołki odwiedzane podczas przechodzenia grafu
algorytmami BFS i DFS.


### Zaimplementowano metody:

`GraphAM()` - konstruktor podstawowy, inicjuje graf bez wierzchołków <br/>
`GraphAM(n)` - kostruktor, tworzy macierz macierz sąsiedztwa dla grafu z n wierzchołkami <br/>
`GraphAM(const GraphAM& g)` - konstruktor kopiujący, tworzy nowy obiekt, który jest kopią przekazanego obiektu <br/>
`GraphAM(GraphAM&& g) ` - konstruktor przenoszący, przenosi zadany obiekt do nowego obiektu <br/>
`~GraphAM()` - destruktor (defaultowy) <br/>
`display()` - wyświetla macierz sąsiedztwa\
`add_node()` - dodaje kolejny wierzchołek do grafu\
`add_edge(int node1, int node2)` - dodaje krawędź pomiędzy wierzchołkami node1 i node2\
`get_nodes()` - zwraca liczbę wierzchołków\
`get_edges()` - zwraca liczbę krawędzi\
`has_edge(int node1, int node2)` - sprawdza czy obiekt posiada krawędź pomiędzy dwoma wierzchołkami, zwraca bool (true/false) <br/>
`has_node(int node)` - sprawdza czy obiekt posiada przekazany wierzchołek, zwraca bool (true/false) <br/> 
`del_node(int node)` - usuwa wszystkie krawędzie prowadzące do danego wierzchołka <br/>
`del_edge(int node1, int node2)` - usuwa krawędź pomiędzy wierzchołkami node1 i node2 <br/> 
`BFS()` - przechodzi po wszystkich wierzchołkach grafu zgodnie
z algorytmem bread firs search i wyświetla je, przejście zaczyna się od wierzchołka "0" <br/>
`BFS(int node)` -  przechodzi po wszystystkich wierzchołkachgrafu zgodnie 
z algorytmem bread first search i wyświetla je, przejscie zaczyna się od wierchołka node <br/>
`DFS()` - przechodzi po wszystkich wierzchołkach grafu zgodnie 
z algorytmem depth first search i wyświetla je, przejcie zaczyna się od wierzchołka "0" <br/>
`DFS(int node)` -  przechodzi po wszystystkich wierzchołkachgrafu zgodnie 
z algorytmem bdepth first search i wyświetla je, przejscie zaczyna się od wierchołka node




