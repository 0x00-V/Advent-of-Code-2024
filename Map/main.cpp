#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

// if . move, else if # turn 90 move

// for 90 deg, use diff dir symbol, move along facing vertcies

void mapToGrid(std::ifstream& file, std::vector<std::vector<char>>& grid)
{
    std::string line;
    while (std::getline(file, line))
    {
        std::vector<char> row(line.begin(), line.end());
        grid.push_back(row);
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

    int up{1};
    for(size_t row = 0; row < map.size(); ++row)
    {
        for(size_t col = 0; col < map[row].size(); ++col)
        {
            if(map[row][col] == '^')
            {
                std::cout << "Found Guard(^) at pos: (" << row << col << ")\n";
                std::cout << map[row-1][col-1] << map[row-1][col] << map[row-1][col+1] << '\n' << map[row][col-1] << map[row][col] << map[row][col+1] << '\n' << map[row+1][col-1] << map[row+1][col] << map[row+1][col+1];


                // ^ means check  row - until # is detected.
                // keep track of ^ char
                int guard_row = row;
                int guard_col = col;
                while (map[row-up][col] != '#')
                {
                    std::cout << map[row-up+1][col] << '\n'; // collision detected
                    --up;
                }
            }

            
            
            
        }

    }
    



    return 0;
}