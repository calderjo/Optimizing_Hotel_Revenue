//
// Created by Jonathan Calderon Chavez on 4/5/21.
//

#include <tuple>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "DAG.h"

#ifndef CS415PROJECT2B_MAX_REV_ALGO_H
#define CS415PROJECT2B_MAX_REV_ALGO_H

std::map<int, int> cal_max_revenue(const std::vector<int>& clientList, DAG listOfClients);
std::vector<int> cal_optimal_path(const std::vector<int>& clientList, std::map<int, int> max_revenue_path, DAG listOfClients);

#endif //CS415PROJECT2B_MAX_REV_ALGO_H
