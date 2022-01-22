#pragma once
#include <vulkan/vulkan.h>
#include <vector>
class ShaderModuleGenerator
{
public:
	static VkShaderModule createShaderModule(const std::vector<char>& code, VkDevice device);
};

