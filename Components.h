#pragma once
#include <string>
#include <vector>

struct Position {
	int x = 0;
	int y = 0;
};

struct Health {
	int current = 100;
	int max = 100;
};
struct Name
{
	std::string value;
};
struct Animation {
	std::string currentState = "idle";
	//std::vector<std::string> states;
	int currentFrame = 0;
	int maxFrames = 4;
	float frameTime = 0.2f;
	float timer = 0.0f;
};
struct Input {
	std::string lastComand;
};
struct Collider {
	int width = 1;
	int height = 1;
};
struct Tile {
	char symbol;
	bool walkable;
};
struct Tilemap {
	std::vector<std::vector<Tile>> grid;
	int width;
	int height;
	const std::vector<std::vector<Tile>>& GetGrid() const {
		return grid;
	}
};