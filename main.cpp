#include <GLFW/glfw3.h>

int main() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 800, "Janela do jogo", NULL, NULL);
    glfwMakeContextCurrent(window);

    while(!glfwWindowShouldClose(window)){
        
        glfwPollEvents();
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
        
        glClearColor(0.1, 0.3, 0.6, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glColor3f(0.1, 0.1, 0.1);
        glBegin(GL_TRIANGLES);
            glVertex3f(0.3, 0.4, 0);
            glVertex3f(0, 0.1, 0);
            glVertex3f(0.6, 0.1, 0);
        glEnd();

        glColor3f(0.4, 0.4, 0.8);
        glBegin(GL_QUADS);
            glVertex3f(-0.5, 0.5, 0);
            glVertex3f(-0.2, 0.5, 0);
            glVertex3f(-0.2, -0.5, 0);
            glVertex3f(-0.5, -0.5, 0);
        glEnd();
        
        glfwSwapBuffers(window);
        
    }
    glfwTerminate();
    return 0;
}