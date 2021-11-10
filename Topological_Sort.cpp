//
// Created by Jonathan Calderon Chavez on 4/4/21.
//
#include "Topological_Sort.h"
std::vector<int> topologicalSort_QueueBase(DAG Graph){
    std::queue<int> Q;
    std::vector<int> count(Graph.nodeCount(),0);
    std::vector<int> list;
    std::vector<int> ordering;

    for(int v = 0; v < Graph.nodeCount(); v++ ){
        list = Graph.neighbors(v);
        for (int i : list)
            count.at(i)++;
    }

    for (int v = 0; v < Graph.nodeCount(); v++){
        if (count.at(v) == 0)
            Q.push(v);
    }

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();
        ordering.push_back(v);
        list = Graph.neighbors(v);
        for (int & i : list) {
            count.at(i)--;
            if (count.at(i) == 0)
                Q.push(i);
        }
    }
    return ordering;
}