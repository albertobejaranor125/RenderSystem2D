#pragma once
#include <fstream>
#include <string>
class LoggerSystem {
	std::ofstream logFile;
public:
	LoggerSystem(const std::string& filename = "game_log.txt") {
		logFile.open(filename, std::ios::trunc);
	}
	~LoggerSystem() {
		if (logFile.is_open()) {
			logFile.close();
		}
	}
	void Log(const std::string& message) {
		if (logFile.is_open()) {
			logFile << "[LOG] " << message << std::endl;
		}
	}
};