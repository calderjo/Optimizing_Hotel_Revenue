//
// Created by Jonathan Calderon Chavez on 3/31/21.
//

#include <tuple>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>

#ifndef CS415PROJECT2B_INPUTTOTUPLES_H
#define CS415PROJECT2B_INPUTTOTUPLES_H

class inputToTuples {
public:
    static std::vector<std::tuple<int, int, int>> readFileOfClients(const std::string& fileName);

private:
    static std::vector<std::tuple<int, int, int>> fileParser(const std::string& fileName);
    static std::tuple<int, int, int> lineParser(const std::string& input);
};

#endif //CS415PROJECT2B_INPUTTOTUPLES_H
