#include <GLFW/glfw3.h>
#define M_PI 3.14159265358979323846
#include <math.h>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(480, 480, "Vincent Ralph Chang", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        /* Initialize Pentagon Variables */
        int n = 5;
        float angle = 0.0f;
        float radius = 0.5f;
        float angleIncrement = 360.0f / n;  // n is 5 in your case
        angleIncrement *= M_PI / 180.0f;    // convert degrees to radians
        for (int k = 0; k < n; ++k) {
            float x = radius * cos(angle);
            float y = radius * sin(angle);
            glVertex2f(x, y);
            angle += angleIncrement;
        }
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}