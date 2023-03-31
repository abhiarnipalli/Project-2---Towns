#ifndef PROGRAM2_MYGRAPH_H
#define PROGRAM2_MYGRAPH_H
#include <vector>
using namespace std;

class MyGraph {
private:
    int n;
    vector<vector<pair<int, float>>> list;
public:
    MyGraph(int n);
    MyGraph(const MyGraph& g);
    bool AddEdge(int a, int b, float w);
    void output(ostream& os);
    pair<vector<int>, float> HW2Prog(int s, int t, bool printMST);
};

#endif //PROGRAM2_MYGRAPH_H
