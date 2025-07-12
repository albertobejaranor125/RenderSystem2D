#include "MapLoader.h"
#include <fstream>
#include <iostream>

Tilemap LoadMapFromFile(const std::string& filename) {
	Tilemap map;
	std::ifstream inFile(filename);
	if (!inFile.is_open()) {
		std::cerr << "[ERROR] Could not open map file: " << filename << std::endl;
		return map;
	}
	std::string line;
	while (std::getline(inFile, line)) {
		std::vector<Tile> row;
		for (char c : line) {
			bool walkable = c == '.';
			if (c == '~' || c == '#') walkable = false;
			row.push_back({c, walkable});
		}
		map.grid.push_back(row);
	}
	map.height = map.grid.size();
	map.width = map.height > 0 ? map.grid[0].size() : 0;
	return map;
}