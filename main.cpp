
#include "funkcijos.h"
int main() {
    //veikia tik anglu kalba
    std::map<std::string, std::pair<int, std::set<int>>> wordMap;
    std::vector<std::string> urls;


    readFile(wordMap,urls);
    int choice = consoleOrFile();
    if( choice == 1){

        outputToConsole(wordMap,urls);
    }
    else{

        outputToFile(wordMap,urls);

    }

    system("pause");
    return 0;
}