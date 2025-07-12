#pragma once
#include "Entity.h"
#include "Components.h"
#include <vector>
#include <iostream>

class MovementSystem {
public:
	void Update(std::vector<Entity>& entities) {
		for (auto& entity : entities) {
			if (entity.HasComponent<Position>()) {
				auto pos = entity.GetComponent<Position>();
				pos->x += 1;
				if (entity.HasComponent<Name>()) {
					auto name = entity.GetComponent<Name>();
					std::cout << name->value << " moved to (" << pos->x << ", " << pos->y << ")\n";
				}
			}
		}
	}
};
class HealthSystem {
public:
	void Update(std::vector<Entity>& entities) {
		for (auto& entity : entities) {
			if (entity.HasComponent<Health>()) {
				auto healthCurrent = entity.GetComponent<Health>();
				healthCurrent->current -= 5;
				if (healthCurrent->current < 0) {
					healthCurrent->current = 0;
				}
				if (entity.HasComponent<Name>()) {
					auto name = entity.GetComponent<Name>();
					std::cout << name->value << " has " << healthCurrent->current << "/" << healthCurrent->max << " HP\n";
				}
			}
		}
	}
};
class DeathSystem {
public:
	void Update(std::vector<Entity>& entities) {
		for (auto& entity : entities) {
			if (entity.HasComponent<Health>()) {
				auto healthCurrent = entity.GetComponent<Health>();
				if (healthCurrent->current <= 0) {
					if (entity.HasComponent<Name>()) {
						std::cout << entity.GetComponent<Name>()->value << " has died!" << std::endl;
					}else {
						std::cout << "An entity has died!" << std::endl;
					}
					entity.GetComponent<Health>()->current = 0;
				}
			}
		}
	}
};
class AnimationSystem {
public:
	void Update(std::vector<Entity>& entities, float deltaTime) {
		for (auto& entity : entities) {
			if (!entity.HasComponent<Animation>()) {
				continue;
			}
			auto animation = entity.GetComponent<Animation>();
			animation->timer += deltaTime;
			if (animation->timer >= animation->frameTime) {
				animation->timer = 0.0f;
				animation->currentFrame = (animation->currentFrame + 1) % animation->maxFrames;
				std::cout << "[Animation] " << animation->currentState << " | Frame: " << animation->currentFrame << "\n";
			}
		}
	}
};
class InputSystem {
public:
	void Update(Entity& entity) {
		if (!entity.HasComponent<Input>()) return;
		auto input = entity.GetComponent<Input>();
		const std::vector<std::string>& possibleCommands = { "Idle", "Move", "Attack" };
		int choice = rand() % possibleCommands.size();
		input->lastComand = possibleCommands[choice];
		std::cout << "[Input] Command received: " << input->lastComand << "\n";
	}
};
class CollisionSystem {
public:
	void Update(std::vector<Entity>& entities) {
		for (size_t i = 0; i < entities.size(); i++) {
			for (size_t j = 0; j < entities.size(); j++) {
				auto& a = entities[i];
				auto& b = entities[j];
				if (!a.HasComponent<Position>() || !a.HasComponent<Collider>()) continue;
				if (!b.HasComponent<Position>() || !b.HasComponent<Collider>()) continue;
				auto aPos = a.GetComponent<Position>();
				auto bPos = b.GetComponent<Position>();
				auto aCol = a.GetComponent<Collider>();
				auto bCol = b.GetComponent<Collider>();
				if (IsColliding(*aPos, *bPos, *aCol, *bCol)) {
					std::string aName = a.HasComponent<Name>() ? a.GetComponent<Name>()->value : "EntityA";
					std::string bName = b.HasComponent<Name>() ? b.GetComponent<Name>()->value : "EntityB";
					std::cout << "[Collision] " << aName << " collided with " << bName << "\n";
				}
			}
		}
	}
private:
	bool IsColliding(const Position& aPos, const Position& bPos, const Collider& aCol, const Collider& bCol) {
		return (
			aPos.x < bPos.x + bCol.width &&
			bPos.x < aPos.x + aCol.width &&
			aPos.y < bPos.y + bCol.height &&
			bPos.y < aPos.y + aCol.height);
	}
};
class TilemapSystem {
public:
	void Render(const Tilemap& map) {
		for (int y = 0; y < map.height; y++) {
			for (int x = 0; x < map.width; x++) {
				std::cout << map.grid[y][x].symbol;
			}
			std::cout << "\n";
		}
	}
};