#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


//static unsigned int CompileShader(const std::string& source, unsigned int type)
//{
//    unsigned int id = glCreateShader(GL_VERTEX_SHADER);
//    const char* src = source.c_str();
//
//}
//
//
//static int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
//{
//    // We need to provide openGL our shader source code. 
//    // want openGL to compile and link both shaders into a single program
//    // give us some unique identifier back so we can bind and use the shader.
//
//    unsigned int program = glCreateProgram();
//    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
//
//}


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;




    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    
    if (glewInit() != GLEW_OK)
        std::cout << "ERROR!" << std::endl;

    std::cout << glGetString(GL_VERSION) << std::endl;

    float positions[6] =
    {
        -0.5f, -0.5f,
        0.0f, 0.5f,
        0.5f, -0.5f
    };

    unsigned int buffer;
    // Generates a buffer and gives us back an ID
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    

    // specify the data that will be put into the buffer
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        //drawing the triangle
        glDrawArrays(GL_TRIANGLES, 0, 3);
        

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}