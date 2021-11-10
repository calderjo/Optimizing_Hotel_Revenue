//
// Created by Jonathan Calderon Chavez on 4/2/21.
// Uses ideas
//

#include <vector>
#include <tuple>
#include <forward_list>
#include <string>

#ifndef CS415PROJECT2B_DAG_H
#define CS415PROJECT2B_DAG_H

class DAG {
public:
    explicit DAG(const std::vector<std::tuple<int, int, int>>& list);
    int nodeCount();
    std::vector<int> neighbors(unsigned node);
    int getWeight(unsigned parentNode, unsigned childNode);

private:
    static std::vector<std::forward_list<std::tuple<int, int>>>
            constructDAG(const std::vector<std::tuple<int, int, int>>& list);

    std::vector<std::forward_list<std::tuple<int,int>>> Dag;
};
#endif //CS415PROJECT2B_DAG_H
