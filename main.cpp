#include <fstream>
#include "inputToTuples.h"
#include "DAG.h"
#include "Topological_Sort.h"
#include "max_rev_algo.h"

int main() {
    std::string fileName;  // prompt user
    std::cout << "Enter the file to read data: ";
    std::cin >> fileName;
    std::cout << std::endl;
    std::string firstLine = "Enter the file to read data: " + fileName;

    std::string outputFileName = "./outData/out" + fileName; // create output file
    std::ofstream outputFile(outputFileName);
    outputFile << firstLine << std::endl << std::endl;

    // read file
    std::vector<std::tuple<int, int, int>> listOfClients = inputToTuples::readFileOfClients(fileName);

    std::cout << "There are " << std::to_string(listOfClients.size()) << " clients in this file";
    std::cout << std::endl << std::endl;
    outputFile << "There are " << std::to_string(listOfClients.size()) << " clients in this file"
    << std::endl << std::endl;

    // organize data
    DAG clientList(listOfClients);
    std::vector<int> topOrderClients = topologicalSort_QueueBase(clientList);

    // calc max rev that can be made
    std::map<int, int> max_rev = cal_max_revenue(topOrderClients, clientList);
    std::cout << "Optimal revenue earned is " << std::to_string(max_rev[0]) << std::endl;
    outputFile << "Optimal revenue earned is " << std::to_string(max_rev[0]) << std::endl;


    // calc optimal path that can make that max rev
    std::vector<int> opt_path = cal_optimal_path(topOrderClients, max_rev, clientList);

    std::cout << "Clients contributing to this optimal revenue:";
    for(int node = 0; node <= opt_path.size() - 2 ; ++node)  {
        std::cout << " " << std::to_string(opt_path.at(node))<< ",";
    }
    std::cout << " " << opt_path.at(opt_path.size()-1);
    std::cout << std::endl;

    outputFile << "Clients contributing to this optimal revenue:";
    for(int node = 0; node <= opt_path.size() - 2 ; ++node)  {
        outputFile << " " << std::to_string(opt_path.at(node))<< ",";
    }
    outputFile << " " << opt_path.at(opt_path.size()-1);
    outputFile << std::endl;

    // close the output file
    outputFile.close();
    return 0;

}
