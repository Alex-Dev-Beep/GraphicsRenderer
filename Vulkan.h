#pragma once

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;

    bool isComplete() {
        return graphicsFamily.has_value();
    }
};

class App {
public:
    const uint32_t WIDTH = 800;
    const uint32_t HEIGHT = 600;

	GLFWwindow* window;

    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

    void run();

private:
	// Validation layers
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

    void createInstance();
    void setupDebugMessenger();
    void pickPhysicalDevice();

    void initWindow();
    void initVulkan();
    void mainLoop();
	void cleanup();
};