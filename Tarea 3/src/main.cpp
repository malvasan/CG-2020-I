#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);


// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

GLfloat rojo = 0.0f;
GLfloat verde = 0.0f;
GLfloat azul = 0.0f;

bool r = false;
bool v = false;
bool a = false;

GLfloat rojo1 = 0.0f;
GLfloat verde1 = 0.0f;
GLfloat azul1 = 0.0f;

bool r1 = false;
bool v1 = false;
bool a1 = false;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
const char* fragmentShader1Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"uniform vec4 ourColor1;\n"
"void main()\n"
"{\n"
"   FragColor = ourColor1;\n"
"}\n\0";
const char* fragmentShader2Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"uniform vec4 ourColor2;\n"
"void main()\n"
"{\n"
"   FragColor = ourColor2;\n"
"}\n\0";

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_R && action == GLFW_PRESS) {
        if (rojo == 0) {
            rojo = 1.0f;
            r = true;
        }
        else {
            rojo = 0;
            r = false;

        }
    }
    else if (key == GLFW_KEY_G && action == GLFW_PRESS) {
        if (verde == 0) {
            verde = 1.0f;
            v = true;
        }
        else {
            verde = 0;
            v = false;
        }
    }
    else if (key == GLFW_KEY_B && action == GLFW_PRESS) {
        if (azul == 0) {
            azul = 1.0f;
            a = true;
        }
        else {
            azul = 0;
            a = false;
        }
    }
    else if (key == GLFW_KEY_T && action == GLFW_PRESS) {
        if (r == true)
            rojo = rojo + 0.1f;
        if(v==true)
            verde = verde + 0.1f;
        if(a==true)
            azul = azul + 0.1f;
    }
    else if (key == GLFW_KEY_Y && action == GLFW_PRESS) {
        if (r == true)
            rojo = rojo - 0.1f;
        if (v == true)
            verde = verde - 0.1f;
        if (a == true)
            azul = azul - 0.1f;
    }

    else if (key == GLFW_KEY_O && action == GLFW_PRESS) {
        if (rojo1 == 0) {
            rojo1 = 1.0f;
            r1 = true;
        }
        else {
            rojo1 = 0;
            r1 = false;
        }
    }
    else if (key == GLFW_KEY_V && action == GLFW_PRESS) {
        if (verde1 == 0) {
            verde1 = 1.0f;
            v1 = true;
        }
        else {
            verde1 = 0;
            v1 = false;
        }
    }
    else if (key == GLFW_KEY_A && action == GLFW_PRESS) {
        if (azul1 == 0) {
            azul1 = 1.0f;
            a1 = true;
        }
        else {
            azul1 = 0;
            a1 = false;
        }
    }
    else if (key == GLFW_KEY_U && action == GLFW_PRESS) {
        if (r1 == true)
            rojo1 = rojo1 + 0.1f;
        if (v1 == true)
            verde1 = verde1 + 0.1f;
        if (a1 == true)
            azul1 = azul1 + 0.1f;
    }
    else if (key == GLFW_KEY_I && action == GLFW_PRESS) {
        if (r1 == true)
            rojo1 = rojo1 - 0.1f;
        if (v1 == true)
            verde1 = verde1 - 0.1f;
        if (a1 == true)
            azul1 = azul1 - 0.1f;
    }

    
}

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



    
    
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER); 
    unsigned int fragmentShader2 = glCreateShader(GL_FRAGMENT_SHADER); 
    unsigned int shaderProgram1 = glCreateProgram();
    unsigned int shaderProgram2 = glCreateProgram(); 
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    glShaderSource(fragmentShader1, 1, &fragmentShader1Source, NULL);
    glCompileShader(fragmentShader1);
    glShaderSource(fragmentShader2, 1, &fragmentShader2Source, NULL);
    glCompileShader(fragmentShader2);
    
    glAttachShader(shaderProgram1, vertexShader);
    glAttachShader(shaderProgram1, fragmentShader1);
    glLinkProgram(shaderProgram1);
    
    glAttachShader(shaderProgram2, vertexShader);
    glAttachShader(shaderProgram2, fragmentShader2);
    glLinkProgram(shaderProgram2);

    
    float firstTriangle[] = {
        -0.9f, -0.5f, 0.0f,   
        -0.0f, -0.5f, 0.0f,  
        -0.45f, 0.5f, 0.0f,  
    };
    float secondTriangle[] = {
        0.0f, -0.5f, 0.0f,  
        0.9f, -0.5f, 0.0f,  
        0.45f, 0.5f, 0.0f   
    };
    unsigned int VBOs[2], VAOs[2];
    glGenVertexArrays(2, VAOs); 
    glGenBuffers(2, VBOs);
 
    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);	
    glEnableVertexAttribArray(0);


    glBindVertexArray(VAOs[1]);	
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);	
    glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); 
    glEnableVertexAttribArray(0);
    

 
    while (!glfwWindowShouldClose(window))
    {
        // input
        
        glfwSetKeyCallback(window, key_callback);
        // render
     
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        
        glUseProgram(shaderProgram1);
        
        int vertexColorLocation = glGetUniformLocation(shaderProgram1, "ourColor1");
        glUniform4f(vertexColorLocation, rojo, verde, azul, 1.0f);
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);	 
        
        glUseProgram(shaderProgram2);
        vertexColorLocation = glGetUniformLocation(shaderProgram2, "ourColor2");
        glUniform4f(vertexColorLocation, rojo1, verde1, azul1, 1.0f);
        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);	

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

   
    glDeleteVertexArrays(2, VAOs);
    glDeleteBuffers(2, VBOs);

    
    glfwTerminate();
    return 0;
}



void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}