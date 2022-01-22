#pragma once
#include <vector>
#include <vulkan/vulkan.h>

class SwapChainSupportDetails
{
public:
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

