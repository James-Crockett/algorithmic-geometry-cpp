#include <iostream>

//opengl libs
#include <glad/glad.h>
#include <GLFW/glfw3.h>

 void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
} 

int main()
{
    //telling glfw the opengl version
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "Window", NULL, NULL);

    if (window == NULL)
    {
        std::cout <<"Failed to create window"<< std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    //glad function to point at opengl functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    } 

    glViewport(0,0,800,600);

     //line values
    GLfloat lineVertices[] = {
        500, 100, 0,
        300, 300, 0
    };

    //for resizing window
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

    while(!glfwWindowShouldClose(window))
    {
        //rendring line
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, lineVertices);
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    glfwTerminate();
    return 0;
}
