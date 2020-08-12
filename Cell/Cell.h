
#ifndef CELL_H

#define CELL_H

#ifdef __DLLMAKING__

#define _DLLSPEC __declspec(dllexport)

#else

#define _DLLSPEC __declspec(dllimport)

#endif	// #ifdef __DLLMAKING__

#include <vector>
#include <cstdlib>
#include <cstring>

class _DLLSPEC CellMap
{
public: 

	CellMap(int rows, int cols, int seed); 
	void Grow(); 
	const std::vector<bool>& operator[](int x) const { return map[x]; }

private: 
	std::vector<std::vector<bool>> map; 
	std::vector<std::vector<bool>> tmp;
};


#endif	// #ifndef CELL_H
