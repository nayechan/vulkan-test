#pragma once
#include <vector>
#include <string>
#include <fstream>

class Utility
{
public:
	static std::vector<char> readFileToByte(const std::string& filename);
};

