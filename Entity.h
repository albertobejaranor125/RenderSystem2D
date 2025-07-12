#pragma once
#include <unordered_map>
#include <typeindex>
#include <memory>

class Entity {
private:
	std::unordered_map<std::type_index, std::shared_ptr<void>> components;
public:
	template <typename T>
	void AddComponent(std::shared_ptr<T> component) {
		components[typeid(T)] = component;
	}
	template <typename T>
	std::shared_ptr<T> GetComponent(){
		auto it = components.find(typeid(T));
		if (it != components.end()) {
			return std::static_pointer_cast<T>(it->second);
		}
		return nullptr;
	}
	template <typename T>
	bool HasComponent() const {
		return components.find(typeid(T)) != components.end();
	}
};