//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//#include <iostream>
//#include "../Includes/stb_image.h"
//#include "../LearnCamera/Camera.h"
//#include "../LearnShader/Shader.h"
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void processInput(GLFWwindow* window);
//unsigned int loadTexture(const char* path);
//
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//// camera
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//float lastX = SCR_WIDTH / 2.0f;
//float lastY = SCR_HEIGHT / 2.0f;
//bool firstMouse = true;
//
//// timing
//float deltaTime = 0.0f;
//float lastFrame = 0.0f;
//
//// lighting
//glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
//
//int main()
//{
//	// glfw: initialize and configure
//	// ------------------------------
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//	// glfw window creation
//	// --------------------
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//	glfwSetCursorPosCallback(window, mouse_callback);
//	glfwSetScrollCallback(window, scroll_callback);
//
//	// tell GLFW to capture our mouse
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//	// glad: load all OpenGL function pointers
//	// ---------------------------------------
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	// configure global opengl state
//	// -----------------------------
//	glEnable(GL_DEPTH_TEST);
//
//	// build and compile our shader zprogram
//	// ------------------------------------
//	Shader cube("F:\\opengl\\OpenGLProject\\Source\\\MultipleLights\\MultipleLights.vs", "F:\\opengl\\OpenGLProject\\Source\\\MultipleLights\\MultipleLights.fs");
//	Shader light("F:\\opengl\\OpenGLProject\\Source\\LearnLight\\light.vs", "F:\\opengl\\OpenGLProject\\Source\\LearnLight\\light.fs");
//
//	glm::vec3 cubePositions[] =
//	{
//		glm::vec3(0.0f,  0.0f,  0.0f),
//		glm::vec3(2.0f,  5.0f, -15.0f),
//		glm::vec3(-1.5f, -2.2f, -2.5f),
//		glm::vec3(-3.8f, -2.0f, -12.3f),
//		glm::vec3(2.4f, -0.4f, -3.5f),
//		glm::vec3(-1.7f,  3.0f, -7.5f),
//		glm::vec3(1.3f, -2.0f, -2.5f),
//		glm::vec3(1.5f,  2.0f, -2.5f),
//		glm::vec3(1.5f,  0.2f, -1.5f),
//		glm::vec3(-1.3f,  1.0f, -1.5f)
//	};
//
//	glm::vec3 pointLightPositions[] =
//	{
//	 glm::vec3(0.7f,  0.2f,  2.0f),
//	 glm::vec3(2.3f, -3.3f, -4.0f),
//	 glm::vec3(-4.0f,  2.0f, -12.0f),
//	 glm::vec3(0.0f,  0.0f, -3.0f)
//	};
//	// DESERT
//	//glm::vec3 pointLightColors[] = {
//	//glm::vec3(1.0f, 0.6f, 0.0f),
//	//glm::vec3(1.0f, 0.0f, 0.0f),
//	//glm::vec3(1.0f, 1.0, 0.0),
//	//glm::vec3(0.2f, 0.2f, 1.0f)
//	//};
//	// FACTORY
//	//glm::vec3 pointLightColors[] = {
//	//glm::vec3(0.2f, 0.2f, 0.6f),
//	//glm::vec3(0.3f, 0.3f, 0.7f),
//	//glm::vec3(0.0f, 0.0f, 0.3f),
//	//glm::vec3(0.4f, 0.4f, 0.4f)
//	//};
//	// HORROR
//	/*glm::vec3 pointLightColors[] = {
//		glm::vec3(0.1f, 0.1f, 0.1f),
//		glm::vec3(0.1f, 0.1f, 0.1f),
//		glm::vec3(0.1f, 0.1f, 0.1f),
//		glm::vec3(0.3f, 0.1f, 0.1f)
//	};*/
//	// BIOCHEMICAL LAB
//	glm::vec3 pointLightColors[] = {
//	glm::vec3(0.4f, 0.7f, 0.1f),
//	glm::vec3(0.4f, 0.7f, 0.1f),
//	glm::vec3(0.4f, 0.7f, 0.1f),
//	glm::vec3(0.4f, 0.7f, 0.1f)
//	};
//	// set up vertex data (and buffer(s)) and configure vertex attributes
//	// ------------------------------------------------------------------
//	float vertices[] = {
//		// positions          // normals           // texture coords
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
//
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
//
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
//
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
//
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
//		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
//		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
//		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
//	};
//	// first, configure the cube's VAO (and VBO)
//	unsigned int VBO, cubeVAO;
//	glGenVertexArrays(1, &cubeVAO);
//	glGenBuffers(1, &VBO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glBindVertexArray(cubeVAO);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//	// second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
//	unsigned int lightCubeVAO;
//	glGenVertexArrays(1, &lightCubeVAO);
//	glBindVertexArray(lightCubeVAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	// note that we update the lamp's position attribute's stride to reflect the updated buffer data
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	// load textures (we now use a utility function to keep the code more organized)
//	// -----------------------------------------------------------------------------
//	unsigned int diffuseMap = loadTexture("F:\\opengl\\OpenGLProject\\Source\\LightingMaps\\container2.png");
//	unsigned int specularMap = loadTexture("F:\\opengl\\OpenGLProject\\Source\\LightingMaps\\container2_specular.png");
//
//	// shader configuration
//	// --------------------
//	cube.use();
//	cube.setInt("material.diffuse", 0);
//	cube.setInt("material.specular", 1);
//
//	// render loop
//	// -----------
//	while (!glfwWindowShouldClose(window))
//	{
//		// per-frame time logic
//		// --------------------
//		float currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		// input
//		// -----
//		processInput(window);
//
//		// render
//		// ------
//		// DESERT
//		//glClearColor(0.75f, 0.52f, 0.3f, 1.0f);
//		// FACTORY
//		//glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//		// HORROR
//		//glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//		// BIOCHEMICAL LAB
//		glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		// be sure to activate shader when setting uniforms/drawing objects
//		cube.use();
//		cube.setVec3("viewPos", camera.Position);
//		cube.setFloat("material.shininess", 32.0f);
//
//		// DESERT directional light
//		//cube.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
//		//cube.setVec3("dirLight.ambient", 0.3f, 0.24f, 0.14f);
//		//cube.setVec3("dirLight.diffuse", 0.7f, 0.42f, 0.26f);
//		//cube.setVec3("dirLight.specular", 0.5f, 0.5f, 0.5f);
//	    // FACTORY directional light
//		//cube.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
//		//cube.setVec3("dirLight.ambient", 0.05f, 0.05f, 0.1f);
//		//cube.setVec3("dirLight.diffuse", 0.2f, 0.2f, 0.7f);
//		//cube.setVec3("dirLight.specular", 0.7f, 0.7f, 0.7f);
//		// HORROR directional light
//		/*cube.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
//		cube.setVec3("dirLight.ambient", 0.0f, 0.0f, 0.0f);
//		cube.setVec3("dirLight.diffuse", 0.05f, 0.05f, 0.05f);
//		cube.setVec3("dirLight.specular", 0.2f, 0.2f, 0.2f);*/
//		// BIOCHEMICAL LAB directional light
//		cube.setVec3("dirLight.direction", -0.2f, -1.0f, -0.3f);
//		cube.setVec3("dirLight.ambient", 0.5f, 0.5f, 0.5f);
//		cube.setVec3("dirLight.diffuse", 1.0f, 1.0f, 1.0f);
//		cube.setVec3("dirLight.specular", 1.0f, 1.0f, 1.0f);
//		// point light 1
//		cube.setVec3("pointLights[0].position", pointLightPositions[0]);
//		cube.setVec3("pointLights[0].ambient", pointLightColors[0] * 0.1f);
//		cube.setVec3("pointLights[0].diffuse", pointLightColors[0]);
//		cube.setVec3("pointLights[0].specular", pointLightColors[0]);
//		cube.setFloat("pointLights[0].constant", 1.0f);
//		cube.setFloat("pointLights[0].linear", 0.09);
//		cube.setFloat("pointLights[0].quadratic", 0.032);
//		// point light 2
//		cube.setVec3("pointLights[1].position", pointLightPositions[1]);
//		cube.setVec3("pointLights[1].ambient", pointLightColors[1] * 0.1f);
//		cube.setVec3("pointLights[1].diffuse", pointLightColors[1]);
//		cube.setVec3("pointLights[1].specular", pointLightColors[1]);
//		cube.setFloat("pointLights[1].constant", 1.0f);
//		cube.setFloat("pointLights[1].linear", 0.09);
//		cube.setFloat("pointLights[1].quadratic", 0.032);
//		// point light 3
//		cube.setVec3("pointLights[2].position", pointLightPositions[2]);
//		cube.setVec3("pointLights[2].ambient", pointLightColors[2] * 0.1f);
//		cube.setVec3("pointLights[2].diffuse", pointLightColors[2]);
//		cube.setVec3("pointLights[2].specular", pointLightColors[2]);
//		cube.setFloat("pointLights[2].constant", 1.0f);
//		cube.setFloat("pointLights[2].linear", 0.09);
//		cube.setFloat("pointLights[2].quadratic", 0.032);
//		// point light 4
//		cube.setVec3("pointLights[3].position", pointLightPositions[3]);
//		cube.setVec3("pointLights[3].ambient", pointLightColors[3] * 0.1f);
//		cube.setVec3("pointLights[3].diffuse", pointLightColors[3]);
//		cube.setVec3("pointLights[3].specular", pointLightColors[3]);
//		cube.setFloat("pointLights[3].constant", 1.0f);
//		cube.setFloat("pointLights[3].linear", 0.09);
//		cube.setFloat("pointLights[3].quadratic", 0.032);
//		// DESERT spotLight
//		/*cube.setVec3("spotLight.position", camera.Position);
//		cube.setVec3("spotLight.direction", camera.Front);
//		cube.setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
//		cube.setVec3("spotLight.diffuse", 0.8f, 0.8f, 0.0f);
//		cube.setVec3("spotLight.specular", 0.8f, 0.8f, 0.0f);
//		cube.setFloat("spotLight.constant", 1.0f);
//		cube.setFloat("spotLight.linear", 0.09);
//		cube.setFloat("spotLight.quadratic", 0.032);
//		cube.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
//		cube.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));*/
//		// FACTORY spotLight
//		/*cube.setVec3("spotLight.position", camera.Position);
//		cube.setVec3("spotLight.direction", camera.Front);
//		cube.setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
//		cube.setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
//		cube.setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
//		cube.setFloat("spotLight.constant", 1.0f);
//		cube.setFloat("spotLight.linear", 0.09);
//		cube.setFloat("spotLight.quadratic", 0.032);
//		cube.setFloat("spotLight.cutOff", glm::cos(glm::radians(10.0f)));
//		cube.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(12.5f)));*/
//		// HORROR directional light
//		/*cube.setVec3("spotLight.position", camera.Position);
//		cube.setVec3("spotLight.direction", camera.Front);
//		cube.setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
//		cube.setVec3("spotLight.diffuse", 1.0f, 1.0f, 1.0f);
//		cube.setVec3("spotLight.specular", 1.0f, 1.0f, 1.0f);
//		cube.setFloat("spotLight.constant", 1.0f);
//		cube.setFloat("spotLight.linear", 0.09);
//		cube.setFloat("spotLight.quadratic", 0.032);
//		cube.setFloat("spotLight.cutOff", glm::cos(glm::radians(10.0f)));
//		cube.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));*/
//		//  BIOCHEMICAL LAB directional light
//		cube.setVec3("spotLight.position", camera.Position);
//		cube.setVec3("spotLight.direction", camera.Front);
//		cube.setVec3("spotLight.ambient", 0.0f, 0.0f, 0.0f);
//		cube.setVec3("spotLight.diffuse", 0.0f, 1.0f, 0.0f);
//		cube.setVec3("spotLight.specular", 0.0f, 1.0f, 0.0f);
//		cube.setFloat("spotLight.constant", 1.0f);
//		cube.setFloat("spotLight.linear", 0.07);
//		cube.setFloat("spotLight.quadratic", 0.017);
//		cube.setFloat("spotLight.cutOff", glm::cos(glm::radians(7.0f)));
//		cube.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(10.0f)));
//
//		// view/projection transformations
//		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//		glm::mat4 view = camera.GetViewMatrix();
//		cube.setMat4("projection", projection);
//		cube.setMat4("view", view);
//
//		// bind diffuse map
//		glActiveTexture(GL_TEXTURE0);
//		glBindTexture(GL_TEXTURE_2D, diffuseMap);
//
//		// bind specular map
//		glActiveTexture(GL_TEXTURE1);
//		glBindTexture(GL_TEXTURE_2D, specularMap);
//
//		// render the cube
//		glBindVertexArray(cubeVAO);
//		for (unsigned int i = 0; i < 10; i++)
//		{
//			glm::mat4 model;
//			model = glm::translate(model, cubePositions[i]);
//			float angle = 20.0f * i;
//			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//			cube.setMat4("model", model);
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//
//		// also draw the lamp object
//		light.use();
//		light.setMat4("projection", projection);
//		light.setMat4("view", view);
//
//		glBindVertexArray(lightCubeVAO);
//		for (unsigned int i = 0; i < 4; i++)
//		{
//			glm::mat4 model;
//			model = glm::translate(model, pointLightPositions[i]);
//			model = glm::scale(model, glm::vec3(0.2f));
//			light.setMat4("model", model);
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//
//
//		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//		// -------------------------------------------------------------------------------
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	// optional: de-allocate all resources once they've outlived their purpose:
//	// ------------------------------------------------------------------------
//	glDeleteVertexArrays(1, &cubeVAO);
//	glDeleteVertexArrays(1, &lightCubeVAO);
//	glDeleteBuffers(1, &VBO);
//
//	// glfw: terminate, clearing all previously allocated GLFW resources.
//	// ------------------------------------------------------------------
//	glfwTerminate();
//	return 0;
//}
//
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//
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
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	// make sure the viewport matches the new window dimensions; note that width and 
//	// height will be significantly larger than specified on retina displays.
//	glViewport(0, 0, width, height);
//}
//
//
//// glfw: whenever the mouse moves, this callback is called
//// -------------------------------------------------------
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
//	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
//
//	lastX = xpos;
//	lastY = ypos;
//
//	camera.ProcessMouseMovement(xoffset, yoffset);
//}
//
//// glfw: whenever the mouse scroll wheel scrolls, this callback is called
//// ----------------------------------------------------------------------
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//	camera.ProcessMouseScroll(yoffset);
//}
//
//// utility function for loading a 2D texture from file
//// ---------------------------------------------------
//unsigned int loadTexture(char const* path)
//{
//	unsigned int textureID;
//	glGenTextures(1, &textureID);
//
//	int width, height, nrComponents;
//	unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
//	if (data)
//	{
//		GLenum format;
//		if (nrComponents == 1)
//			format = GL_RED;
//		else if (nrComponents == 3)
//			format = GL_RGB;
//		else if (nrComponents == 4)
//			format = GL_RGBA;
//
//		glBindTexture(GL_TEXTURE_2D, textureID);
//		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
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