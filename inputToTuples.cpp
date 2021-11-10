//
// Created by Jonathan Calderon Chavez on 3/31/21.
//

#include "inputToTuples.h"

std::vector<std::tuple<int, int, int>> inputToTuples::fileParser(const std::string& fileName) {
    // This function takes in a string that represent the filename of file containing
    // client information on each line.
    //Open file

    std::string newString = "./data/" + fileName;
    std::vector<std::tuple<int, int, int>> listOfClientInfo;
    std::ifstream clientsFile(newString);
    std::string clientInformation;

    if (clientsFile.is_open()){
        while (getline(clientsFile,clientInformation) ){
            listOfClientInfo.push_back(lineParser(clientInformation));
        }
        clientsFile.close();
    }
    else {
        std::cout << "Unable to open file" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return listOfClientInfo;
}

std::tuple<int, int, int> inputToTuples::lineParser(const std::string& input) {
    // This function will take in a single string containing 3
    // ints x1, x2, x3 separated by white spaces
    // returns a 3-tuple or int

    std::stringstream line(input);
    int startDate;
    int endDate;
    int pay;

    line >> startDate;
    line >> endDate;
    line >> pay;

    return std::make_tuple(startDate, endDate, pay) ;
}

std::vector<std::tuple<int, int, int>> inputToTuples::readFileOfClients(const std::string& fileName) {
    std::vector<std::tuple<int, int, int>> listOfClients = fileParser(fileName);
    return listOfClients;
}

