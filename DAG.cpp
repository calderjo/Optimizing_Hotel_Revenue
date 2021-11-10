//
// Created by Jonathan Calderon Chavez on 4/2/21.
//

#include "DAG.h"

std::vector<std::forward_list<std::tuple<int, int>>>
        DAG::constructDAG(const std::vector<std::tuple<int, int, int>>& list) {
    // Assumes list size is greater than 0
    // This function will create a DAG, based on the rules provide in project description,
    // Input: a vector of 3-tuples of ints: order must be as follows startDate, endDate, pay
    // this algorithm will build the edges between different clients

    std::vector<std::forward_list<std::tuple<int, int>>> DAG(list.size() + 2);
    std::vector<int> numberOfIncomingEdgesV(list.size());
    for (int currentNodeToBeAdded = 0; currentNodeToBeAdded < list.size(); currentNodeToBeAdded++){
        for (int visitingNode = 0; visitingNode < list.size(); visitingNode++){ // case: same nodes are compared
            if (currentNodeToBeAdded == visitingNode){
                continue;
            } // case: ei<= sj
            if( std::get<1>(list.at(currentNodeToBeAdded)) <= std::get<0>(list.at(visitingNode))){
                std::tuple<int, int> newNeighbor =
                        std::make_tuple(visitingNode + 1, std::get<2>(list.at(currentNodeToBeAdded)));
                DAG.at(currentNodeToBeAdded+1).push_front(newNeighbor);
                numberOfIncomingEdgesV.at(visitingNode)++;
            }
        }
    } // add start state
    for(int Vi = 1; Vi <= list.size(); Vi++) {  // searching of edges into vertex Vi
        if(numberOfIncomingEdgesV.at(Vi-1) == 0) { // transition from the start state do not have a weight
            std::tuple<int, int> newNeighbor = std::make_tuple(Vi, 0);
            DAG.at(0).push_front(newNeighbor);
        }
    }
    bool noOutGoingEdges; // add end state
    for(int Vi = 1; Vi <= list.size(); Vi++) { // searching of edges into vertex Vi
        noOutGoingEdges = DAG.at(Vi).empty();
        if(noOutGoingEdges){
            std::tuple<int, int> newNeighbor = std::make_tuple(list.size() + 1, std::get<2>(list.at(Vi-1)));
            DAG.at(Vi).push_front(newNeighbor);
        }
    }
    return DAG;
}

DAG::DAG(const std::vector<std::tuple<int, int, int>>& list) {
    Dag = constructDAG(list);
}

int DAG::nodeCount() {
    return Dag.size();
}

std::vector<int> DAG::neighbors(unsigned node) {
    std::vector<int> nVertex;
    for (auto &visitingNode : Dag.at(node)) {
        nVertex.push_back(std::get<0>(visitingNode));
    }
    return nVertex;
}

int DAG::getWeight(unsigned parentNode, unsigned childNode) {
    // Assume an edge exist between vertex v and w
    std::vector<int> nVertex;
    for (auto &visitingNode : Dag.at(parentNode)) {
        if (std::get<0>(visitingNode) == childNode){
            return std::get<1>(visitingNode);
        }
    }
    return -1;
}

