#pragma once
#include "Entity.h"
#include "Components.h"
#include <vector>
#include <iostream>

class RenderSystem {
private:
	int width = 20;
	int height = 10;
public:
	void Draw(std::vector<Entity>& entities, Tilemap& map) {
		/*std::vector<std::vector<char>> grid(height, std::vector<char>(width, '.'));
		for (auto entity : entities) {
			if (entity.HasComponent<Position>()) {
				auto pos = entity.GetComponent<Position>();
				int x = pos->x;
				int y = pos->y;
				if (x >= 0 && x < width && y >= 0 && y < height) {
					char symbol = '?';
					if (entity.HasComponent<Name>()) {
						std::string name = entity.GetComponent<Name>()->value;
						symbol = name == "Hero" ? 'H' : 'M';
					}
					grid[y][x] = symbol;
				}
			}
		}
		std::cout << "\n[Map View]\n";
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				std::cout << grid[y][x] << ' ';
			}
			std::cout << "\n";
		}*/
		auto grid = map.GetGrid();  // Copiamos el mapa base
		for (auto& entity : entities) {
			if (entity.HasComponent<Position>()) {
				auto pos = entity.GetComponent<Position>();
				int x = pos->x;
				int y = pos->y;

				if (y >= 0 && y < static_cast<int>(grid.size()) &&
					x >= 0 && x < static_cast<int>(grid[y].size())) {

					char symbol = '?';
					if (entity.HasComponent<Name>()) {
						std::string name = entity.GetComponent<Name>()->value;
						symbol = name == "Hero" ? 'H' : 'M';
					}

					grid[y][x].symbol = symbol;
				}
			}
		}

		std::cout << "\n[Map View]\n";
		for (const auto& row : grid) {
			for (const auto& tile : row) {
				std::cout << tile.symbol;
			}
			std::cout << '\n';
		}
	}
};