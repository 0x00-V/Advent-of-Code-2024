#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <fstream>


int main() 
{
    std::ifstream file("input.txt");
    if (!file) 
    {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }
    std::string content;
    std::getline(file, content, '\0');
    size_t delimiterPos = content.find("\n\n");
    std::string rulesSection = content.substr(0, delimiterPos); 
    std::string updatesSection = content.substr(delimiterPos + 2); 
    std::map<int, std::set<int>> rules;
    std::istringstream ruleStream(rulesSection);
    std::string ruleLine;
    while (std::getline(ruleStream, ruleLine))
    {
        size_t delimiterPos = ruleLine.find('|');
        int pageBefore = std::stoi(ruleLine.substr(0, delimiterPos));
        int pageAfter = std::stoi(ruleLine.substr(delimiterPos + 1));
        rules[pageBefore].insert(pageAfter);
    }

    int midSum = 0; 
    int modifiedSum = 0;

    std::istringstream updateStream(updatesSection);
    std::string updateLine;

    while (std::getline(updateStream, updateLine))
    {
        std::vector<int> pages;
        std::istringstream pageStream(updateLine);
        std::string page;
        while (std::getline(pageStream, page, ',')){pages.push_back(std::stoi(page));}
        bool isValid = true;

        for (size_t i = 0; i < pages.size(); ++i)
        {
            for (size_t j = i + 1; j < pages.size(); ++j)
            {
                if (rules.find(pages[i]) == rules.end() || rules[pages[i]].find(pages[j]) == rules[pages[i]].end())
                {
                    isValid = false;
                    break; 
                }
            } if (!isValid) break;
        }

        if (isValid){midSum += pages[pages.size() / 2];} else
        {
            for (size_t i = 0; i < pages.size(); ++i)
            {
                for (size_t j = i + 1; j < pages.size(); ++j){if (rules.find(pages[i]) == rules.end() || rules[pages[i]].find(pages[j]) == rules[pages[i]].end()) {std::swap(pages[i], pages[j]);}}
            }
            modifiedSum += pages[pages.size() / 2];
        }
    }


    std::cout << "(Problem 1)Sum: " << midSum << std::endl;
    std::cout << "(Problem 2)Sum: " << modifiedSum << std::endl;
    return 0;
}
