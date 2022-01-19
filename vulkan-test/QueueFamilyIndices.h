#pragma once
#include <cstdint>
#include <optional>

class QueueFamilyIndices
{
public:
	std::optional<uint32_t> graphicsFamily;

	bool isComplete();
};

