#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cmath>
#include <vector>

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
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";
const char* fragmentShader2Source = "#version 330 core\n"
"out vec4 FragColor;\n"
"uniform vec4 ourColor2;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
"}\n\0";

int recursion = 4;
int ntriangulos = 0;


void generar_triangulos( std::vector<float>& triangulos, float triangulo[9],int rec=0)
{
    //4
    //grande
    //arriba
    //izquierda
    //derecha

    //menor
    //izquierda
    //derecha
    //abajo


    float z = 0;
    float triangulo_actual[9] = { triangulo[0],triangulo[1],triangulo[2],triangulo[3],triangulo[4],triangulo[5],triangulo[6],triangulo[7],triangulo[8] };
    
    
    triangulos[0 + (9 * ntriangulos)] = (triangulo_actual[0] + triangulo_actual[3]) / 2.0f;
    triangulos[1 + (9 * ntriangulos)] = (triangulo_actual[1] + triangulo_actual[4]) / 2.0f;
    triangulos[2 + (9 * ntriangulos)] = z;

    triangulos[3 + (9 * ntriangulos)] = (triangulo_actual[6] + triangulo_actual[0]) / 2.0f;
    triangulos[4 + (9 * ntriangulos)] = (triangulo_actual[1] + triangulo_actual[4]) / 2.0f;
    triangulos[5 + (9 * ntriangulos)] = z;

    triangulos[6 + (9 * ntriangulos)] = triangulo_actual[0];
    triangulos[7 + (9 * ntriangulos)] = triangulo_actual[4];
    triangulos[8 + (9 * ntriangulos)] = z;

  

    int tri_actual = ntriangulos;
    ++ntriangulos;

    if (recursion == rec) {
        return;
    }
    ++rec;
    //arriba
    triangulo_actual[0] = triangulo[0];//arriba
    triangulo_actual[1] = triangulo[1];
    triangulo_actual[2] = triangulo[2];
    triangulo_actual[3] = triangulos[0 + (9 * tri_actual)];//izquierda
    triangulo_actual[4] = triangulos[1 + (9 * tri_actual)];
    triangulo_actual[5] = triangulos[2 + (9 * tri_actual)];
    triangulo_actual[6] = triangulos[3 + (9 * tri_actual)];//derecha
    triangulo_actual[7] = triangulos[4 + (9 * tri_actual)];
    triangulo_actual[8] = triangulos[5 + (9 * tri_actual)];

    generar_triangulos(triangulos, triangulo_actual,rec);

    //izquierda
    triangulo_actual[0] = triangulos[0 + (9 * tri_actual)];//arriba
    triangulo_actual[1] = triangulos[1 + (9 * tri_actual)];
    triangulo_actual[2] = triangulos[2 + (9 * tri_actual)];
    triangulo_actual[3] = triangulo[3];//izquierda
    triangulo_actual[4] = triangulo[4];
    triangulo_actual[5] = triangulo[5];
    triangulo_actual[6] = triangulos[6 + (9 * tri_actual)];//derecha
    triangulo_actual[7] = triangulos[7 + (9 * tri_actual)];
    triangulo_actual[8] = triangulos[8 + (9 * tri_actual)];

    generar_triangulos(triangulos, triangulo_actual,rec);

    //derecha
    triangulo_actual[0] = triangulos[3 + (9 * tri_actual)];//arriba
    triangulo_actual[1] = triangulos[4 + (9 * tri_actual)];
    triangulo_actual[2] = triangulos[5 + (9 * tri_actual)];
    triangulo_actual[3] = triangulos[6 + (9 * tri_actual)];//izquierda
    triangulo_actual[4] = triangulos[7 + (9 * tri_actual)];
    triangulo_actual[5] = triangulos[8 + (9 * tri_actual)];
    triangulo_actual[6] = triangulo[6];//derecha
    triangulo_actual[7] = triangulo[7];
    triangulo_actual[8] = triangulo[8];

    generar_triangulos(triangulos, triangulo_actual,rec);
    
}

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
        -0.45f, 0.5f, 0.0f, //arriba
        -0.9f, -0.5f, 0.0f, //izquierda   
        -0.0f, -0.5f, 0.0f  //derecha  
    };
    float secondTriangle[] = {
        0.0f, -0.5f, 0.0f,  
        0.9f, -0.5f, 0.0f,  
        0.45f, 0.5f, 0.0f   
    };

    int calculo = 0;
    
    for (int i = 0; i <= recursion; i++) {
        calculo = calculo + pow(3, i);
    }
    std::cout << calculo << std::endl;
    calculo = calculo * 9;
    std::vector<float> triang(calculo);
    generar_triangulos(triang,firstTriangle);

    /*for (int i = 0; i < triang.size(); i++) {
        if (i % 9 == 0)
            std::cout << std::endl;
        std::cout << triang[i] << "  " ;
        
    }*/

    unsigned int VBOs[2], VAOs[2];
    glGenVertexArrays(2, VAOs); 
    glGenBuffers(2, VBOs);
 
    glBindVertexArray(VAOs[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, triang.size()*sizeof(float),triang.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);	
    glEnableVertexAttribArray(0);


    glBindVertexArray(VAOs[1]);	
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);	
    glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    

 
    while (!glfwWindowShouldClose(window))
    {
        // input
        
        glfwSetKeyCallback(window, key_callback);
        // render
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram2);

        glBindVertexArray(VAOs[1]);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glUseProgram(shaderProgram1);
        
        glBindVertexArray(VAOs[0]);
        glDrawArrays(GL_TRIANGLES, 0, ntriangulos*3);	 
        
        

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