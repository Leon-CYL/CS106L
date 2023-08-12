#include <iostream>
#include <string>
#include <map>
#include <fstream>

std::map<std::string, std::pair<std::string, std::string> > createMap(std::string fileName) {
    std::ifstream in(fileName);
    std::string name;
    std::string university;
    std::string year;
    std::map<std::string, std::pair<std::string, std::string> > csMap;
    std::pair<std::string, std::string> p;

    while (!in.eof()) {
        getline(in, name, ',');
        getline(in, university, ',');
        getline(in, year, '\n');
        p = std::make_pair(university,year);
        csMap[name] = p;
    }

    return csMap;
}

void printMap(std::map<std::string, std::pair<std::string, std::string> > map) {
    for (auto iter = map.begin(); iter != map.end(); iter++) {
        if (iter->second.first.compare("Stanford University") == 0) {
            std::cout << iter->first << " " << iter->second.first << " " << iter->second.second << std::endl;
        }
    }
}

int main() {
    auto csMap = createMap("csProfessor.csv");
    printMap(csMap);
    return 0;
}