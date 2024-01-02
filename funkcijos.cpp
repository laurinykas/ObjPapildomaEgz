
#include "funkcijos.h"



// Function to process each word in the text
void processWord(const std::string& word, int lineNum, std::map<std::string, std::pair<int, std::set<int>>>& wordMap) {
    // Remove punctuation from the word and convert to lowercase
    std::string cleanWord;
    for (char c : word) {  // praeina per kiekviena simboli ir tikrina ar tai raide ar simbolis (tik anglu)
        if (isalpha(c)) {
            cleanWord += tolower(c); // jei raide, ja automatiskai padaro automatiskai mazaja
        }
    }
    if (!cleanWord.empty()) {
        wordMap[cleanWord].first++;  // prideda jau tinkama zodi prie map'o
        wordMap[cleanWord].second.insert(lineNum); // prideda eilutes nr. kaip id , kaip antra parametra
    }
}

void findURLs(const std::string& line, std::vector<std::string>& urls) {
    std::regex urlPattern("(https?://www\\.|www\\.)[\\w\\.-]+(/[\\w\\.-]*)*"); // dazniausios url pradzios
    std::smatch matches;
    std::string::const_iterator searchStart(line.cbegin()); // praeina per visa faila ir iesko url
    while (regex_search(searchStart, line.cend(), matches, urlPattern)) {
        urls.push_back(matches[0]);
        searchStart = matches.suffix().first;
    }
}

void readFile (std::map<std::string, std::pair<int, std::set<int>>>& wordMap, std::vector<std::string> &urls ) {
    std::cout<<"Input your file name ex(wiki.txt): "<<std::endl; std::string fileName;
    std::cin>>fileName;
    std::ifstream file(fileName);
    std::string line;
    int lineNum = 1;

    if (file.is_open()) {
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::string word;
            while (iss >> word) {
                processWord(word, lineNum, wordMap);
            }
            findURLs(line, urls);
            lineNum++;
        }
        file.close();
    }
    else {
        std::cerr << "Unable to open file or file with that name doesn't exist " << std::endl;

    }

}
void outputToFile(const std::map<std::string, std::pair<int, std::set<int>>>& wordMap, const std::vector<std::string>& urls){

    std::ofstream outFile("Output.txt");
    for (const auto& pair : wordMap) {
        if (pair.second.first > 1) {
            outFile << pair.first << ": " << pair.second.first
                    << " [Lines: ";
            for (int ln : pair.second.second) {
                outFile << ln << " ";
            }
            outFile << "]" << std::endl;
        }
    }
    // Output the URLs found
    for (const std::string& url : urls) {
        outFile << "URL: " << url << std::endl;
    }

    outFile.close();
    std::cout<< "File created: Output.txt"<< std::endl;
}
void outputToConsole(const std::map<std::string, std::pair<int, std::set<int>>>& wordMap, const std::vector<std::string>& urls){
    for (const auto& pair : wordMap) {
        if (pair.second.first > 1) {
            std::cout << pair.first << ": " << pair.second.first
                    << " [Lines: ";
            for (int ln : pair.second.second) {
                std::cout << ln << " ";
            }
            std::cout << "]" << std::endl;
        }
    }
    // Output the URLs found
    for (const std::string& url : urls) {
        std::cout << "URL: " << url << std::endl;
    }


}
int consoleOrFile(){
    int choice;
    while (true) {
        std::cout<<"Do you want your output in console (type 1) or in file (type 2)?  : ";
        if (std::cin >> choice &&( choice == 1 || choice == 2 || choice == 3 )) {
            return choice;
        } else {
            std::cout << "Incorrect input, type 1 or 2  :" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
}
int substringOrFull(){
    int choice;
    while (true) {
        std::cout<<"Do you want to search using substring for words  (type 1) or find all words  (type 2)?  : ";
        if (std::cin >> choice &&( choice == 1 || choice == 2 || choice == 3 )) {
            return choice;
        } else {
            std::cout << "Incorrect input, type 1 or 2  :" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
}



void searchSubstringToConsole(const std::string& substring, const std::map<std::string, std::pair<int, std::set<int>>>& wordMap) {
    int totalWords = 1;
    std::cout << "Words containing '" << substring << "':" << std::endl;
    for (const auto& pair : wordMap) {
        if (pair.first.find(substring) != std::string::npos) {
            std::cout << pair.first << " [Lines: ";
            for (int ln : pair.second.second) {
                std::cout << ln << " ";
                totalWords++;
            }
            std::cout << "]" << std::endl;
        }
    }
    std::cout<<"Total words found "<<totalWords<<std::endl;
}
std::string inputSubstring(){
    std::string substring;
    std::cout<<"Input your substring : "<<std::endl;
    std::cin>>substring;
    return substring;


}

void searchSubstringToFile(const std::string& substring, const std::map<std::string, std::pair<int, std::set<int>>>& wordMap) {
    int totalWords = 1 ;
    std::ofstream outFile("OutputSubstring.txt");
    outFile << "Words containing '" << substring << "':" << std::endl;
    for (const auto& pair : wordMap) {
        if (pair.first.find(substring) != std::string::npos) {
            outFile << pair.first << " [Lines: ";
            for (int ln : pair.second.second) {
                outFile << ln << " ";
                totalWords++;
            }
            outFile << "]" << std::endl;
        }
    }
    outFile<<"Total words found "<<totalWords<<std::endl;
    outFile.close();
    std::cout<< "File created: OutputSubstring.txt"<< std::endl;
}


// žmogus turi įvesti žodžių junginį turi įvesti į failą arba į ekraną



