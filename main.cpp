
#include "funkcijos.h"
int main() {
    //veikia tik anglu kalba
    std::map<std::string, std::pair<int, std::set<int>>> wordMap;
    std::vector<std::string> urls;


    readFile(wordMap,urls);
    int choice1 = substringOrFull();
    int choice2 = consoleOrFile();
    if( choice1 == 1){
        if(choice2 == 1 ){
            searchSubstringToConsole(inputSubstring(),wordMap);
        }
        else{
            searchSubstringToFile(inputSubstring(),wordMap);
            //
        }
    }
    else{
        if(choice2 == 1 ){

            outputToConsole(wordMap,urls);
        }
        else{

            outputToFile(wordMap,urls);
        }


    }

    system("pause");
    return 0;
}