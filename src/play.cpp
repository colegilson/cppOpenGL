#include"glew.h"
#include<GLFW/glfw3.h>
#include<iostream>

static unsigned int CompileShader(unsigned int type, const std::string &source)
{
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    /*
    glShaderSource(
        shader, number of source codes specified, 
        pointer to pointer of the string,
        length of string(nullptr indicates full string))
    */
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);
    
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);

        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment")
        << " shader!" << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

static unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader)
{

    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);
    
    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

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
    
    glewExperimental=GL_TRUE;
    GLenum err=glewInit();
    if(err!=GLEW_OK)
      std::cout << "Error!" << std::endl;
    
    std::cout << glGetString(GL_VERSION) << std::endl;
    
    float positions[6] = {
        -0.5f,-0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int buf;
    glGenBuffers(1, &buf);
    glBindBuffer(GL_ARRAY_BUFFER, buf);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    
    glEnableVertexAttribArray(0);
    
    /*
    glvertexattribpointer parameters 
        (what index is the attribute at: unsure, hopefully more will become clear later, 
        the dimension of the shape:      1D, 2D, 3D, 4D, 
        normalizer:                      a boolean value as to where the values given are floats between 0 and 1, if not a float bettween 0 and 1, then GL_TRUE, else GL_FALSE,
        Stride:                          what is the size of each attribute, each vertex has an x and y, those are each floats so we have 2 * size of float,
        Pointer:                         a pointer into the actual attribute, how many bytes into the attribute is the information needed aka offset)
    */
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
    
    std::string vertexShader = 
    "#version 330 core\n"
    "\n"
    "layout(location = 0) in vec4 position;\n"
    "\n"
    "void main()\n"
    "{\n"
    "   gl_Position = position;\n"
    "}\n";

        std::string fragmentShader = 
    "#version 330 core\n"
    "\n"
    "out vec4 colour;\n"
    "\n"
    "void main()\n"
    "{\n"
    "   colour = vec4(1.0, 0.0, 0.0, 1.0);\n"
    "}\n";

    unsigned int shader = CreateShader(vertexShader, fragmentShader);
    glUseProgram(shader);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(shader);
    glfwTerminate();
    return 0;
}