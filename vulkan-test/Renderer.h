#pragma once
#define GLFW_INCLUDE_VULKAN

#include <vulkan/vulkan.h>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <GLFW/glfw3.h>
#include <vector>
#include <map>
#include <set>
#include <windows.h>
#include <algorithm>
#include "QueueFamilyIndices.h"
#include "SwapChainSupportDetails.h"

class Renderer
{
public:
    Renderer();

private:
    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;

    const std::vector<const char*> validationLayers = {
        "VK_LAYER_KHRONOS_validation"
    };

    const std::vector<const char*> deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
    };

    std::vector<VkImage> swapChainImages;

    VkInstance instance;
    GLFWwindow* window;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkPhysicalDevice physicalDevice;
    VkDevice device;
    VkQueue graphicsQueue, presentQueue;
    VkSurfaceKHR surface;
    VkSwapchainKHR swapChain;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

// Entire Routine
    void initWindow();
    void initVulkan();
    void mainLoop();
    void cleanup();

// Init Vulkan Routine
    void createInstance();
    void setupDebugMessenger();
    void createSurface();
    void pickPhysicalDevice();
    void createLogicalDevice();
    void createSwapChain();

// Other Functions

    bool checkValidationLayerSupport(); 
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);
    int rateDeviceSuitability(VkPhysicalDevice device);
    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device); 
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

    std::vector<const char*> getRequiredExtensions(); 
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

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


    void populateDebugMessengerCreateInfo(
        VkDebugUtilsMessengerCreateInfoEXT& createInfo
    );
};

