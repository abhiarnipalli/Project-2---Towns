# Algos
CS3353
Algorithm overview:
Here is algorithm to find the route you want:
1. Given the information about towns and connecting rails, construct the graph as above (we will
call the graph G)
2. Find the maximum spanning tree of G.
a. The maximum spanning tree is a spanning tree of G, such that the sum of the weight of
the edges are the largest (instead of smallest as in minimum spanning tree).
b. One way of finding the maximum spanning tree is to multiply the weight of each edge of
G by -1, and then find the minimum spanning tree of it.
3. Now, given two towns, find the path from one to the other, only using edges in the maximum
spanning tree in step 2.
Program Specification:
You are to implement following class called MyGraph. It represents an undirected graph with weights on
each edge. You must implement the following methods:
Methods:
• Constructors:
o MyGraph(int n): Create a graph with n vertices. The vertices are labelled 1..n
o MyGraph(const MyGraph& g): Construct a new graph that is a copy of g
• Methods
o bool addEdge(int a, int b, float w): Add an edge between vertex a and b, with weight w.
If the edge already exists or a vertex is not on the graph, do nothing and return false.
Otherwise (addition is successful) return true.
o void output(ostream& os): Output the graph to the ostream& specified. Your output
should have the following format:
 The first line print the number of vertices.
 Each subsequent line prints an edge. It should print three numbers: the two
vertices associated with the edge (print the vertex with the smaller number
first), and the weight of the edge. You should have one space character
between the numbers, and no space at the end. You can order the edges
whatever way you want.
o pair<vector<int>, float> HW2Prog(int s, int t, bool printMST): This is the main function
that you have to implement for this homework.
 The function will return the route from s to t with highest capacity The return
will be a pair. The first item of the pair (vector) denotes the path from s to t. The
first item of the vector should be s and the last one should be t, and the vector
is the order of the vertices on the path from s to t. The second item (float)
denote the actual capacity of the route. 
 If the bool variable printMST is true, then you should also output the maximum
spanning tree of the graph to standard output. You should use the same format
as the output() method
You will be given a driver program, prog2main.cpp. The program will read in a file containing
information about the towns and the route. The file will also contain pair of numbers and the program
will find the route with the highest capacity.
The input file format is as follows.
• The first line contains three integers, which represent the number of towns (n), the number of
rail segments that directly connect two towns (e), and the number of highest capacity routes (c)
that the program needs to find.
• The next e lines contain the rail segments. Each line has three numbers, the first two number
represents the two towns, where the third represent capacity of the rail segment.
o For simplicity’s sake, each town is represented by a number from 0 to n-1
• The next c lines contain the pair of towns that I would like to ask about the path with highest
capacity. Each line contains two numbers denoting the two towns involved.
You can assume the input file is correctly formatted (and with numbers that make sense (e.g. town
number has to be between 0.,.n-1 and I would not query a route from a town to itself). Otherwise, your
program is not responsible for its output. (i.e., no error checking of input is needed.
