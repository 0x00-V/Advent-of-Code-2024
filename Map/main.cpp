#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <set>


void mapToGrid(std::ifstream& file, std::vector<std::vector<char>>& grid)
{
    std::string line;
    while (std::getline(file, line))
    {
        std::vector<char> row(line.begin(), line.end());
        grid.push_back(row);
    }
}


void printGrid(const std::vector<std::vector<char>>& map)
{
    for(const auto& row : map)
    {
        for(char cell : row)
        {
            std::cout << cell;
        }
        std::cout << '\n';
    }
}


int main()
{
    std::ifstream file("input.txt");
    if(!file){
        std::cerr << "Couldn't find file" << std::endl;
        return 1;
    }

    std::vector<std::vector<char>> map;
    mapToGrid(file, map);

    int n = map.size();
    int m = map[0].size();
    
    bool found = false;
    int guard_row, guard_col;

    for(int row = 0; row < n; ++row)
    {
        for(int col = 0; col < m; ++col)
        {
            if(map[row][col] == '^')
            {
                guard_row = row;
                guard_col = col;
                found = true;
                break;
            }
        }
        if(found) break;
    }
    int direction = 0;
    int d_deltas[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    std::set<std::pair<int, int>> seen;

    while(true)
    {
        seen.insert({guard_row, guard_col});

        int next_row = guard_row + d_deltas[direction][0];
        int next_col = guard_col + d_deltas[direction][1];

        if (!(0 <= next_row && next_row < n && 0 <= next_col && next_col < m)) break;

        if(map[next_row][next_col] == '#')
        {
            direction = (direction + 1) % 4;
        } else 
        {
            guard_row = next_row;
            guard_col = next_col;
        }
    }
    printGrid(map);
    std::cout << "Guard Moves: " << seen.size() << '\n';
    return 0;
}