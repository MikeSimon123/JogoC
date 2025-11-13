#include <GLFW/glfw3.h>

class meuQuadrado {
    public:
        double x,y,w,h;
        float color[];
        void resize(double x, double y, double w, double h){
            this->x = x; this->y = y; this->w = w; this->h = h;
        };
        void colorir(double r, double g, double b){
            this->color[0] = r;
            this->color[1] = g;
            this->color[2] = b;
        };
        void desenhar(){
            glColor3f(this->color[0], this->color[1], this->color[2]);
            glBegin(GL_QUADS);
                glVertex3f(this->x, this->y, 0);
                glVertex3f(this->x+w, this->y, 0);
                glVertex3f(this->x+w, this->y+h, 0);
                glVertex3f(this->x, this->y+h, 0);
            glEnd();
        };
};

meuQuadrado quadrado1;
double x = 1.0; double y = 1.0;
double speed = 0.2;

void desenharCena(){
    
    quadrado1.resize(x, y, 1.0, 1.0);
    quadrado1.colorir(0.3, 0.1, 0.5);
    quadrado1.desenhar();
};

int main() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 800, "Janela do jogo", NULL, NULL);
    glfwMakeContextCurrent(window);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, 1.0, -1.0);

    while(!glfwWindowShouldClose(window)){
        
        glfwPollEvents();
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
        if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
            x += speed;
        }
        if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
            x -= speed;
        }
        glClearColor(0.3, 0.3, 0.3, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        desenharCena();

        glfwSwapBuffers(window);
        
    }
    glfwTerminate();
    return 0;
}