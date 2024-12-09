#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>



int main()
{
    int count{0};
    std::ifstream file("input.txt");
    std::vector<std::string> grid;
    std::string line;

    while(std::getline(file, line))
    {
        grid.push_back(line);
    }
    
    for(int row = 0; row < grid.size(); row++)
    {
        for(int column = 0; column < grid[0].size(); ++column)
        {
            if(grid[row][column] != 'X') continue;

            for(int d_row = -1; d_row <= 1; ++d_row)
            {
                for(int d_column = -1; d_column <= 1; ++d_column)
                {
                    if(d_row == 0 && d_column == 0) continue;
                    if (row + 3 * d_row < 0 || row + 3 * d_row >= grid.size() || column + 3 * d_column < 0 || column + 3 * d_column >= grid[0].size()) continue;
                    if(grid[row + d_row][column + d_column] == 'M' && grid[row + 2 * d_row][column + 2 * d_column] == 'A' && grid[row + 3 * d_row][column + 3 * d_column] == 'S')
                    {
                        count++;
                    }
                }
            }
        }
    }
    std::cout << "XMAS appears " << count << " times.\n";

}