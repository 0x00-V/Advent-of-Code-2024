#include <iostream>
#include <regex>
#include <string>
#include <sstream>
#include <fstream>


int main() {
    int total{0};

    std::ifstream file("input.txt");
    if(!file)
    {
        exit(1);
    }
    
    std::string input;
    while(std::getline(file, input))
    {
        std::regex mul_regex(R"(mul\s*\(\s*(-?\d+)\s*,\s*(-?\d+)\s*\))");
        std::smatch match;
        auto begin = std::sregex_iterator(input.begin(), input.end(), mul_regex);
        auto end = std::sregex_iterator();    
        for (std::sregex_iterator i = begin; i != end; ++i) {
        match = *i;
        int first_num = std::stoi(match[1].str());
        int second_num = std::stoi(match[2].str());
        
        total += first_num * second_num;
    }
    }
    
    file.close();
    std::cout << "(Problem 1) Total: " << total << std::endl;
    return 0;
}
// Do not have time to complete problem 2