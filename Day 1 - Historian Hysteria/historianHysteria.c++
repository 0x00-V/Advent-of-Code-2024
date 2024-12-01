#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

void toVectorAndSort(const std::string& filename, std::vector<int>&left, std::vector<int>& right)
{
    std::ifstream file;
    file.open(filename);
    if(!file)
    {
        std::cerr << "Couldn't open file.\nMake sure input.txt is in the same directory as me!\n";
        exit(1);
    }
    std::string line;
    while(std::getline(file, line))
    {
        int l, r;
        std::istringstream stream(line);
        stream >> l >> r;
        left.push_back(l);
        right.push_back(r);
    }
    // Introsort algorithm [O(n log n)]
    std::sort(left.begin(), left.end(), std::less<int>());
    std::sort(right.begin(), right.end(), std::less<int>());
}


void calculateDifference(std::vector<int> left, std::vector<int> right)
{
    int distance{0};

    for(size_t i = 0; i < left.size(); i++)
    {
        std::cout << left[i] << " | "<< right[i] << std::endl;
        distance += std::abs(left[i] - right[i]);
    }
    std::cout << "Distance: " << distance << std::endl;
}


void calculateSimularityScore(std::vector<int> left, std::vector<int> right)
{
    int score{0};
    std::unordered_map<int, int> freq;
    for(int r:right) { freq[r]++;}
    for(int l:left)
    {
        int count = freq[l];
        score+=l*count;
    }
    std::cout << "Simularity Score: " << score << std::endl;
}


int main(void)
{
    std::vector<int> left;
    std::vector<int> right;

    toVectorAndSort("./input.txt", left, right);
    calculateDifference(left, right);
    calculateSimularityScore(left,right);
    return 0;
}