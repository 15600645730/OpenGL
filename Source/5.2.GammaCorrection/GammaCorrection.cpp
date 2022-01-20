//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <iostream>
//#include "../Includes/Camera.h"
//#include "../Includes/Shader.h"
//#include "../Includes/stb_image.h"
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//unsigned int loadTexture(const char* path, bool gammaCorrection);
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//bool gammaEnabled = false;
//bool gammaKeyPressed = false;
//
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//float lastX = SCR_WIDTH / 2.0f;
//float lastY = SCR_HEIGHT / 2.0f;
//
//float deltaTime = 0.0f; 
//float lastFrame = 0.0f; 
//
//bool firstMouse = true;
//
//int main()
//{
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//	glfwSetCursorPosCallback(window, mouse_callback);
//	glfwSetScrollCallback(window, scroll_callback);
//
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//	//Shader shader("D:\\UE4\\LearnOpenGL\\LearnOpenGL\\Source\\5.2.GammaCorrection\\GammaCorrection.vs", "D:\\UE4\\LearnOpenGL\\LearnOpenGL\\Source\\5.2.GammaCorrection\\GammaCorrection.fs");
//	Shader shader("F:\\opengl\\OpenGLProject\\Source\\5.2.GammaCorrection\\GammaCorrection.vs", "F:\\opengl\\OpenGLProject\\Source\\5.2.GammaCorrection\\GammaCorrection.fs");
//	
//	float planeVertices[] = {
//		// positions            // normals         // texcoords
//		 10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,  10.0f,  0.0f,
//		-10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,   0.0f,  0.0f,
//		-10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,   0.0f, 10.0f,
//
//		 10.0f, -0.5f,  10.0f,  0.0f, 1.0f, 0.0f,  10.0f,  0.0f,
//		-10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,   0.0f, 10.0f,
//		 10.0f, -0.5f, -10.0f,  0.0f, 1.0f, 0.0f,  10.0f, 10.0f
//	};
//
//	unsigned int planeVAO, planeVBO;
//	glGenVertexArrays(1, &planeVAO);
//	glGenBuffers(1, &planeVBO);
//    glBindVertexArray(planeVAO);
//    glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), planeVertices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//	glBindVertexArray(0);
//
//	//unsigned int floorTexture = loadTexture("D:\\UE4\\LearnOpenGL\\LearnOpenGL\\resources\\textures\\wood.png",false);
//	//unsigned int floorTextureGammaCorrected = loadTexture("D:\\UE4\\LearnOpenGL\\LearnOpenGL\\resources\\textures\\wood.png", true);
//	unsigned int floorTexture = loadTexture("F:\\opengl\\OpenGLProject\\resources\\textures\\wood.png", false);
//	unsigned int floorTextureGammaCorrected = loadTexture("F:\\opengl\\OpenGLProject\\resources\\textures\\wood.png", true);
//	
//	shader.use();
//	shader.setInt("floorTexture", 0);
//
//	glm::vec3 lightPositions[] = {
//		glm::vec3(-3.0f, 0.0f, 0.0f),
//		glm::vec3(-1.0f, 0.0f, 0.0f),
//		glm::vec3(1.0f, 0.0f, 0.0f),
//		glm::vec3(3.0f, 0.0f, 0.0f)
//	};
//	glm::vec3 lightColors[] = {
//		glm::vec3(0.25),
//		glm::vec3(0.50),
//		glm::vec3(0.75),
//		glm::vec3(1.00)
//	};
//
//	while (!glfwWindowShouldClose(window))
//	{
//		float currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		processInput(window);
//
//		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		// draw objects
//		shader.use();
//		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//		glm::mat4 view = camera.GetViewMatrix();
//		shader.setMat4("projection", projection);
//		shader.setMat4("view", view);
//		// set light uniforms
//		glUniform3fv(glGetUniformLocation(shader.ID, "lightPositions"), 4, &lightPositions[0][0]);
//		glUniform3fv(glGetUniformLocation(shader.ID, "lightColors"), 4, &lightColors[0][0]);
//		shader.setVec3("viewPos", camera.Position);
//		shader.setInt("gamma", gammaEnabled);
//		// floor
//		glBindVertexArray(planeVAO);
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, gammaEnabled ? floorTextureGammaCorrected : floorTexture);
//		glDrawArrays(GL_TRIANGLES, 0, 6);
//
//		std::cout << (gammaEnabled ? "Gamma enabled" : "Gamma disabled") << std::endl;
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glDeleteVertexArrays(1, &planeVAO);
//	glDeleteBuffers(1, &planeVBO);
//
//	glfwTerminate();
//	return 0;
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//	float cameraSpeed = 2.5f;
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//		camera.ProcessKeyboard(FORWARD, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//		camera.ProcessKeyboard(BACKWARD, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//		camera.ProcessKeyboard(LEFT, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//		camera.ProcessKeyboard(RIGHT, deltaTime);
//
//	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && !gammaKeyPressed)
//	{
//		gammaEnabled = !gammaEnabled;
//		gammaKeyPressed = true;
//	}
//	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE)
//	{
//		gammaKeyPressed = false;
//	}
//}
//
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//	if (firstMouse)
//	{
//		lastX = xpos;
//		lastY = ypos;
//		firstMouse = false;
//	}
//
//	float xoffset = xpos - lastX;
//	float yoffset = lastY - ypos;// 注意这里是相反的，因为y坐标是从底部往顶部依次增大的
//	lastX = xpos;
//	lastY = ypos;
//
//	camera.ProcessMouseMovement(xoffset, yoffset);
//
//}
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//	camera.ProcessMouseScroll(yoffset);
//}
//
//unsigned int loadTexture(char const* path, bool gammaCorrection)
//{
//	unsigned int textureID;
//	glGenTextures(1, &textureID);
//
//	int width, height, nrComponents;
//	unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
//	if (data)
//	{
//		GLenum internalFormat;
//		GLenum dataFormat;
//		if (nrComponents == 1)
//		{
//			internalFormat = dataFormat = GL_RED;
//		}
//		else if (nrComponents == 3)
//		{
//			internalFormat = gammaCorrection ? GL_SRGB : GL_RGB;
//			dataFormat = GL_RGB;
//		}
//		else if (nrComponents == 4)
//		{
//			internalFormat = gammaCorrection ? GL_SRGB_ALPHA : GL_RGBA;
//			dataFormat = GL_RGBA;
//		}
//
//		glBindTexture(GL_TEXTURE_2D, textureID);
//		glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, dataFormat == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT); // for this tutorial: use GL_CLAMP_TO_EDGE to prevent semi-transparent borders. Due to interpolation it takes texels from next repeat 
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, dataFormat == GL_RGBA ? GL_CLAMP_TO_EDGE : GL_REPEAT);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//		stbi_image_free(data);
//	}
//	else
//	{
//		std::cout << "Texture failed to load at path: " << path << std::endl;
//		stbi_image_free(data);
//	}
//
//	return textureID;
//}