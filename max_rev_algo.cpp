//
// Created by Jonathan Calderon Chavez on 4/5/21.
//
#include "max_rev_algo.h"

std::map<int, int> cal_max_revenue(const std::vector<int>& topSortList, DAG graph){
    int maxVal;
    int valNeighbor;
    int currentNode;
    int visitingNeighbor;
    int val;
    int findIdx;
    std::vector<int> neighbors;
    std::map<int, int> tSListIdex;
    std::map<int, int> mR;

    for (int index = 0; index < topSortList.size(); index++){
        val = topSortList.at(index);
        tSListIdex[val] = index;
    }
    for(int currentNodeIdx = int(topSortList.size() - 1); currentNodeIdx >= 0; --currentNodeIdx){
        currentNode = topSortList.at(currentNodeIdx);
        neighbors = graph.neighbors(currentNode); // let find all the neighbors of vertex I,

        if(neighbors.empty()){  // let consider a node that has no children, end node
            mR[currentNode] = 0; // node with no children, has no value: max rev is 0
        }
        else{ // let consider a node with children
            maxVal = -1;  // starting a opt path from Node i to end node
            for (int node: neighbors) {
                // since list is top sorted, succeeding node are after the currentNode
                findIdx = tSListIdex[node];
                valNeighbor = mR[findIdx]; // find determine if path is opt
                if (valNeighbor > maxVal){
                    maxVal = valNeighbor;
                    visitingNeighbor = node;
                } // add the opt path to the current node
                mR[currentNodeIdx] = graph.getWeight(currentNode, visitingNeighbor) + maxVal;
            }
        }
    }
    return mR;
}

std::vector<int> cal_optimal_path(const std::vector<int>& topSortList, std::map<int, int> max_revenue_path, DAG graph){
    int maxVal;
    int val;
    int valNeighbor;
    int currentNode;
    unsigned maxValueNode;
    unsigned vNeighborIdx;
    unsigned visitingNeighborIdx;
    std::vector<int> optPath;
    std::vector<int> neighbors;
    std::vector<int> topSortListIdx(topSortList.size());
    std::map<int, int> tSListIdex;

    for (int index = 0; index < topSortList.size(); index++){
        val = topSortList.at(index);
        tSListIdex[val] = index;
    }
    for(unsigned currentNodeIdx = 0; currentNodeIdx < topSortList.size(); currentNodeIdx++){
        currentNode = topSortList.at(currentNodeIdx);
        neighbors = graph.neighbors(currentNode); // let find all the neighbors of the current node
        if(neighbors.empty()){  // let consider a node that has no children, end node, we reached the end
            break; // node with no children, opt path is itself,
        }
        else{ // let consider a node with children
            maxVal = -1;  // starting a opt path from Node i to end node
            maxValueNode = 0;
            for (int node: neighbors){ // since list is top sorted, succeeding node are after the currentNode
                visitingNeighborIdx = tSListIdex[node];
                valNeighbor = max_revenue_path[visitingNeighborIdx]; // find determine if path is opt
                if (valNeighbor > maxVal){
                    maxVal = valNeighbor;
                    maxValueNode = node;
                    vNeighborIdx = visitingNeighborIdx;
                }
            }
            if (maxValueNode != max_revenue_path.size()-1){  // add the opt path to the current node
                optPath.push_back(maxValueNode);
            }
            currentNodeIdx = vNeighborIdx - 1;
        }
    }
    return optPath;
}
