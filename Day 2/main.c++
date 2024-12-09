#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>


bool safe(const std::vector<int>& levels)
{
    std::vector<int> differences;
    for (size_t i = 1; i < levels.size(); i++)
    {
        differences.push_back(levels[i] - levels[i - 1]);
    }
    bool c1 = true, c2 = true;
    for (int difference : differences)
    {       
        if (!(difference >= 1 && difference <= 3)) c1 = false;
        if (!(difference >= -3 && difference <= -1)) c2 = false;
    }
    return c1 || c2;
}


void problem1()
{
    int count = 0;
    std::ifstream file("input.txt");
    std::string line;

    while(std::getline(file, line))
    {
        std::vector<int> levels;
        std::istringstream string_stream(line);
        int level;

        while(string_stream >> level) { levels.push_back(level);}
        if(safe(levels))
        {
            count++;
        }
    }
    std::cout << "Safe: " << count << std::endl;
}


void problem2()
{
    int count = 0;
    std::ifstream file("input.txt");
    std::string line;
    // TXT line to list of ints
    while (std::getline(file, line))
    {
        std::vector<int> levels;
        size_t start = 0, end = 0;
        while ((end = line.find(' ', start)) != std::string::npos)
        {
            levels.push_back(std::stoi(line.substr(start, end - start)));
            start = end + 1;
        }
        levels.push_back(std::stoi(line.substr(start)));
        bool found = false;
        for (size_t index = 0; index < levels.size(); ++index)
        {
            std::vector<int> tmp_levels = levels;
            tmp_levels.erase(tmp_levels.begin() + index);
            if (safe(tmp_levels))
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            count++;
        }
    }
    std::cout << "Safe(Problem Dampler Enabled): " << count << std::endl;
}


int main(void)
{
    problem1();
    problem2();
}