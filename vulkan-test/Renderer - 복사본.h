#pragma once
#define GLFW_INCLUDE_VULKAN

#include <vulkan/vulkan.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <GLFW/glfw3.h>
#include <vector>

class Renderer
{
public:
    Renderer();

private:
    VkInstance instance;
    GLFWwindow* window;
    VkDebugUtilsMessengerEXT debugMessenger;

    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;
    const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

    void createInstance();
    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();
    void setupDebugMessenger();

    bool checkValidationLayerSupport();
    std::vector<const char*> getRequiredExtensions(); 

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, 
        VkDebugUtilsMessageTypeFlagsEXT messageType, 
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, 
        void* pUserData
    );

    VkResult CreateDebugUtilsMessengerEXT(
        VkInstance instance, 
        const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, 
        const VkAllocationCallbacks* pAllocator, 
        VkDebugUtilsMessengerEXT* pDebugMessenger
    );

    void DestroyDebugUtilsMessengerEXT(
        VkInstance instance,
        VkDebugUtilsMessengerEXT debugMessenger,
        const VkAllocationCallbacks* pAllocator
    );
};

