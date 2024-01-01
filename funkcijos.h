#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <regex>
#include <locale>
#include <codecvt>

#ifndef OBJPAPILDOMAEGZ_FUNKCIJOS_H
#define OBJPAPILDOMAEGZ_FUNKCIJOS_H


void findURLs(const std::string& line, std::vector<std::string>& urls);
void processWord(const std::string& word, int lineNum, std::map<std::string, std::pair<int, std::set<int>>>& wordMap);
void readFile (std::map<std::string, std::pair<int, std::set<int>>>& wordMap,std::vector<std::string> &urls );
void outputToFile(const std::map<std::string, std::pair<int, std::set<int>>>& wordMap, const std::vector<std::string>& urls);
void outputToConsole(const std::map<std::string, std::pair<int, std::set<int>>>& wordMap, const std::vector<std::string>& urls);
int consoleOrFile();



#endif //OBJPAPILDOMAEGZ_FUNKCIJOS_H
