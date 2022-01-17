//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//
//const char* fragmentShaderSource1 = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\n\0";
//
//const char* fragmentShaderSource2 = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
//"}\n\0";
//
//int main()
//{
//	// glfw: initialize and configure
//	// -------------------------------------------------------------------------------
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	// glfw window creation
//	// -------------------------------------------------------------------------------
//	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	// glad: load all OpenGL function pointers
//	// -------------------------------------------------------------------------------
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//	// build and compile our shader program
//	// -------------------------------------------------------------------------------
//	// vertex shader
//	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//	// check for shader compile errors
//	int success;
//	char infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//	// fragment shader1
//	unsigned int fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader1, 1, &fragmentShaderSource1, NULL);
//	glCompileShader(fragmentShader1);
//	// check for shader compile errors
//	glGetShaderiv(fragmentShader1, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShader1, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//	// fragment shader2
//	unsigned int fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader2, 1, &fragmentShaderSource2, NULL);
//	glCompileShader(fragmentShader2);
//	// check for shader compile errors
//	glGetShaderiv(fragmentShader2, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShader2, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//	// link shaders
//	unsigned int shaderProgram1 = glCreateProgram();
//	glAttachShader(shaderProgram1, vertexShader);
//	glAttachShader(shaderProgram1, fragmentShader1);
//	glLinkProgram(shaderProgram1);
//	// check for linking errors
//	glGetProgramiv(shaderProgram1, GL_LINK_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(shaderProgram1, 512, NULL, infoLog);
//	}
//
//	unsigned int shaderProgram2 = glCreateProgram();
//	glAttachShader(shaderProgram2, vertexShader);
//	glAttachShader(shaderProgram2, fragmentShader2);
//	glLinkProgram(shaderProgram2);
//	// check for linking errors
//	glGetProgramiv(shaderProgram2, GL_LINK_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(shaderProgram2, 512, NULL, infoLog);
//	}
//
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader1);
//	glDeleteShader(fragmentShader2);
//
//	// set up vertex data (and buffer(s)) and configure vertex attributes
//	// -------------------------------------------------------------------------------
//	float firstTriangle[] = {
//	  -0.9f, -0.5f, 0.0f,  // left 
//	  -0.0f, -0.5f, 0.0f,  // right
//	  -0.45f, 0.5f, 0.0f,  // top 
//	};
//	float secondTriangle[] = {
//		0.0f, -0.5f, 0.0f,  // left
//		0.9f, -0.5f, 0.0f,  // right
//		0.45f, 0.5f, 0.0f   // top 
//	};
//
//	unsigned int VBOs[2], VAOs[2];
//	glGenVertexArrays(2, VAOs);
//	glGenBuffers(2, VBOs);
//
//	// first triangle setup
//    // --------------------
//	glBindVertexArray(VAOs[0]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	// glBindVertexArray(0); // no need to unbind at all as we directly bind a different VAO the next few lines
//    // second triangle setup
//    // ---------------------
//	glBindVertexArray(VAOs[1]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	//note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	//remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
//	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//
//	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//	glBindVertexArray(0);
//
//	//uncomment this call to draw in wireframe polygons.
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	// render loop
//	// -------------------------------------------------------------------------------
//	while (!glfwWindowShouldClose(window))
//	{
//		// input
//		// -------------------------------------------------------------------------------
//		processInput(window);
//
//		// render
//		// -------------------------------------------------------------------------------
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		
//		glUseProgram(shaderProgram1);
//		// draw first triangle using the data from the first VAO
//		glBindVertexArray(VAOs[0]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glUseProgram(shaderProgram2);
//		// then we draw the second triangle using the data from the second VAO
//		glBindVertexArray(VAOs[1]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//		// -------------------------------------------------------------------------------
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//	// optional: de-allocate all resources once they've outlived their purpose:
//	// ------------------------------------------------------------------------
//	glDeleteVertexArrays(1, VAOs);
//	glDeleteBuffers(1, VBOs);
//	glDeleteProgram(shaderProgram1);
//	glDeleteProgram(shaderProgram2);
//	// glfw: terminate, clearing all previously allocated GLFW resources.
//	// ------------------------------------------------------------------
//	glfwTerminate();
//	return 0;
//}
//
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	// make sure the viewport matches the new window dimensions; note that width and 
//	// height will be significantly larger than specified on retina displays.
//	glViewport(0, 0, width, height);
//}
//
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}