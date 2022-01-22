#pragma once
#include <cstdint>
#include <optional>

class QueueFamilyIndices
{
public:
	std::optional<uint32_t> graphicsFamily;
	std::optional<uint32_t> presentFamily;

	bool isComplete();
};

