#include "Cell.h"

CellMap::CellMap(int rows, int cols, int seed) : map(rows, std::vector<bool>(cols)), tmp(rows, std::vector<bool>(cols))
{
    //Init map
	::srand(seed); 
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            map[i][j] = (bool)(::rand() % 2);
}

void CellMap::Grow()
{
    int rows = (int)map.size(); 
    if (rows == 0) return; 
    int cols = (int)map[0].size(); 
    //New grow
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
        {
            int num = 0;
            //Check around
            for (int x = -1; x <= 1; ++x)
                for (int y = -1; y <= 1; ++y)
                {
                    if (!(x || y)) continue;
                    int xTmp = (i + x) % rows, yTmp = (j + y) % cols;
                    if (xTmp < 0) xTmp += rows;
                    if (yTmp < 0) yTmp += cols;
                    if (map[xTmp][yTmp]) ++num;
                }
            switch (num)
            {
            case 2:
                tmp[i][j] = map[i][j];
                break;
            case 3:
                tmp[i][j] = true;
                break;
            default:
                tmp[i][j] = false;
                break;
            }
        }
    //Copy to map
    map = tmp; 
}
