#include"glew.h"
#include<GLFW/glfw3.h>
#include<iostream>
#include <fstream>
#include <string>
#include <sstream>

struct ShaderProgramSource
{
    std::string vertexSource;
    std::string fragmentSource;
};

static ShaderProgramSource ParseShader(const std::string &shadefile)
//obtain shader info from .shader file
{
    std::ifstream stream(shadefile);
    
    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;

    while(getline(stream, line))
    //std::cout << "gets line" << std::endl;
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
            {
                //std::cout << "found vertex" << std::endl;
                type = ShaderType::VERTEX;
            }
            else if (line.find("fragment"))
            {
                type = ShaderType::FRAGMENT;
            }
        }
        else
        {
            ss[(int)type] << line << "\n";
        }
    }
    return {ss[0].str(), ss[1].str()};
}

static unsigned int CompileShader(unsigned int type, const std::string &source)
{
    /*
    function that compiles the shader, type indicates the type of shader (fragment or vertex) indicated by either
    GL_FRAGMENT_SHADER or GL__VERTEX_SHADER respectively
    The source is a the string that contains the shader code
    */
    unsigned int id = glCreateShader(type); // create shader and generated id for the shader
    const char* src = source.c_str(); // convert std::string to c_string
    
    /*
    glShaderSource(
        shader, number of source codes specified, 
        pointer to pointer of the string,
        length of string(nullptr indicates full string))
    */
    glShaderSource(id, 1, &src, nullptr);

    glCompileShader(id); // once shader is made (using function above) compile it as its own
    
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    if (result == GL_FALSE)
    {
        // if an error occurs
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);

        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "Vertex" : "Fragment")
        << " shader!" << std::endl; // simple error message stating what shader failed
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}

static unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader)
{
    // creates the overall shader program, taking in the vertex and fragment shader strings provided to create the final shader
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    // attach compiled shaders to the program
    
    glLinkProgram(program);
    // link program to the GPU
    
    glValidateProgram(program);
    

    glDeleteShader(vs);
    glDeleteShader(fs);
    // delete shaders once we are done with them

    return program;
}

int main(void)
{
    GLFWwindow* window;

    // Initialize the library 
    if (!glfwInit())
        return -1;
    
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    
    // Create a windowed mode window and its OpenGL context 
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    
    // Make the window's context current 
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

    unsigned int VAO = 0;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int buf;
    glGenBuffers(1, &buf);
    glBindBuffer(GL_ARRAY_BUFFER, buf);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
    //glBindBuffer(GL_ARRAY_BUFFER, 0); 
    //uncommenting this line above makes the triangle "wonky" aka it goes off into the corner and is not a triangle
    
    glEnableVertexAttribArray(0);
    
    /*
    glvertexattribpointer() parameters 
        (what index is the attribute at: unsure, hopefully more will become clear later, 
        the dimension of the shape:      1D, 2D, 3D, 4D, 
        normalizer:                      a boolean value as to where the values given are floats between 0 and 1, if not a float bettween 0 and 1, then GL_TRUE, else GL_FALSE,
        Stride:                          what is the size of each attribute, each vertex has an x and y, those are each floats so we have 2 * size of float,
        Pointer:                         a pointer into the actual attribute, how many bytes into the attribute is the information needed aka offset)
    */
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

    ShaderProgramSource source = ParseShader("../res/shaders/basic.shader");
    // std::cout << "vertex shader" << std::endl;
    // std::cout << source.vertexSource << std::endl;
    // std::cout << "fragment shader" << std::endl;
    // std::cout << source.fragmentSource << std::endl;
    
    unsigned int shader = CreateShader(source.vertexSource, source.fragmentSource); 
    // create shader

    glUseProgram(shader);
    // use shader

    // Loop until the user closes the window

    while (!glfwWindowShouldClose(window))
    {
        // Render here 
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glDeleteProgram(shader);
    // delete program from memory
    // this is a change
    
    glfwTerminate();
    return 0;
}