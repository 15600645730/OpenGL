//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include "../LearnCamera/Camera.h"
//#include "../LearnShader/Shader.h"
//#include "../Includes/stb_image.h"
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
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
//	glfwWindowHint(GLFW_SAMPLES, 4);
//
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
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
//	glEnable(GL_MULTISAMPLE);
//	glEnable(GL_DEPTH_TEST);
//
//	//Shader shader("D:\\UE4\\LearnOpenGL\\LearnOpenGL\\Source\\AntiAliasing\\MSAA.vs", "D:\\UE4\\LearnOpenGL\\LearnOpenGL\\Source\\AntiAliasing\\MSAA.fs");
//	Shader shader("F:\\opengl\\OpenGLProject\\Source\\AntiAliasing\\MSAA.vs", "F:\\opengl\\OpenGLProject\\Source\\AntiAliasing\\MSAA.fs");
//	
//	GLfloat cubeVertices[] = {
//		// Positions       
//		-0.5f, -0.5f, -0.5f,
//		 0.5f, -0.5f, -0.5f,
//		 0.5f,  0.5f, -0.5f,
//		 0.5f,  0.5f, -0.5f,
//		-0.5f,  0.5f, -0.5f,
//		-0.5f, -0.5f, -0.5f,
//
//		-0.5f, -0.5f,  0.5f,
//		 0.5f, -0.5f,  0.5f,
//		 0.5f,  0.5f,  0.5f,
//		 0.5f,  0.5f,  0.5f,
//		-0.5f,  0.5f,  0.5f,
//		-0.5f, -0.5f,  0.5f,
//
//		-0.5f,  0.5f,  0.5f,
//		-0.5f,  0.5f, -0.5f,
//		-0.5f, -0.5f, -0.5f,
//		-0.5f, -0.5f, -0.5f,
//		-0.5f, -0.5f,  0.5f,
//		-0.5f,  0.5f,  0.5f,
//
//		 0.5f,  0.5f,  0.5f,
//		 0.5f,  0.5f, -0.5f,
//		 0.5f, -0.5f, -0.5f,
//		 0.5f, -0.5f, -0.5f,
//		 0.5f, -0.5f,  0.5f,
//		 0.5f,  0.5f,  0.5f,
//
//		-0.5f, -0.5f, -0.5f,
//		 0.5f, -0.5f, -0.5f,
//		 0.5f, -0.5f,  0.5f,
//		 0.5f, -0.5f,  0.5f,
//		-0.5f, -0.5f,  0.5f,
//		-0.5f, -0.5f, -0.5f,
//
//		-0.5f,  0.5f, -0.5f,
//		 0.5f,  0.5f, -0.5f,
//		 0.5f,  0.5f,  0.5f,
//		 0.5f,  0.5f,  0.5f,
//		-0.5f,  0.5f,  0.5f,
//		-0.5f,  0.5f, -0.5f
//	};
//
//	unsigned int cubeVBO, cubeVAO;
//	glGenVertexArrays(1, &cubeVAO);
//	glGenBuffers(1, &cubeVBO);
//    glBindVertexArray(cubeVAO);
//    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
//	glEnableVertexAttribArray(0);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glBindVertexArray(0);
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
//
//		shader.use();
//		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//		glm::mat4 view = camera.GetViewMatrix();
//		glm::mat4 model;
//		shader.setMat4("projection", projection);
//		shader.setMat4("view", view);
//		shader.setMat4("model", model);
//        glBindVertexArray(cubeVAO);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//		glBindVertexArray(0);
//
//     	glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//    glDeleteVertexArrays(1, &cubeVAO);
//	glDeleteBuffers(1, &cubeVBO);
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