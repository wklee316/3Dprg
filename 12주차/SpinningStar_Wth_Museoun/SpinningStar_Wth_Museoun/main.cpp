#include <chrono>
#include <thread>
#include <string>
#include <math.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include "MuSeounMath.h"


#pragma comment(lib, "OpenGL32")

using namespace std;

chrono::system_clock::time_point startRenderTimePoint;
chrono::duration<double> renderDuration;

GLFWwindow* window;
bool isFirstFrame = true;


struct Vertex
{
    vec3 pos;
    float r, g, b, a;
};

struct Transform
{
    mat3 translate;
    mat3 scale;
    mat3 rotation;
};


Vertex star[5];
Vertex transformedStar[5];
Vertex circle[360];
Vertex transformedCircle[360];

Transform transform;



int frame = 1;
bool is_big = false;
float scale = 1;




void Init();
void Update();
void Release();

static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(void);


void Init()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(720, 720, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSwapInterval(1);

    startRenderTimePoint = chrono::system_clock::now();


    int i = 0;
    for (float theta = 0; theta < 360; theta += 72)
    {

        star[i].pos.vec[0] = -(float)sin(PI * theta / 180) * 0.5f;
        star[i].pos.vec[1] = (float)cos(PI * theta / 180) * 0.5f;
        star[i].pos.vec[2] = 1.0f;

        star[i].r = 0.3f;
        star[i].g = 0.0f;
        star[i].b = theta / 360.0f;
        star[i].a = 0.7f;


        transformedStar[i] = star[i];

        i++;
    }

    for (int theta = 0; theta < 360; theta++)
    {
        circle[theta].pos.vec[0] = -(float)sin(PI * theta / 180) * 0.5;
        circle[theta].pos.vec[1] = (float)cos(PI * theta / 180) * 0.5;
        circle[theta].pos.vec[2] = 1.0f;

        circle[theta].r = 0.3f;
        circle[theta].g = 0.0f;
        circle[theta].b = (float)theta / 360.0f;
        circle[theta].a = 0.7f;

        transformedCircle[theta] = circle[theta];
    }

}



void Release()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}
void Update()
{
    while (!glfwWindowShouldClose(window))
    {





        float translateX = 0.001 * frame;
        mat3 trans(new float[3][3]{
            {1,0,0},
            {0,1,0},
            {translateX,0,1}}
        );

        mat3 rota(new float[3][3]{
            {(float)cos(PI * frame / 180), (float)-sin(PI * frame / 180),0},
            {(float)sin(PI * frame / 180), (float)cos(PI * frame / 180),0},
            {0,0,1} }
        );


        

        if (is_big) {
            scale -= 0.01;
            if (scale <= 0.7)
                is_big = false;
        }
        else {
            scale += 0.01;
            if (scale >= 1.3)
                is_big = true;
        }

        mat3 sca(new float[3][3]{
            {scale,0,0},
            {0,scale,0},
            {0,0,1} }
        );






        frame++;
       



        for (int i = 0; i < 360; i++)
        {
            transformedCircle[i].pos = circle[i].pos * sca * rota * trans;
        }

        for (int i = 0; i < 5; i++)
        {
            transformedStar[i].pos = star[i].pos * sca * rota * trans;
        }


        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);


        glLineWidth(7.0f);
        glBegin(GL_LINE_STRIP);

        int a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vec[0], transformedStar[a].pos.vec[1], 0.0f);
        a = 3;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vec[0], transformedStar[a].pos.vec[1], 0.0f);
        a = 1;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vec[0], transformedStar[a].pos.vec[1], 0.0f);
        a = 4;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vec[0], transformedStar[a].pos.vec[1], 0.0f);
        a = 2;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vec[0], transformedStar[a].pos.vec[1], 0.0f);

        a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.vec[0], transformedStar[a].pos.vec[1], 0.0f);
        glEnd();

        glBegin(GL_LINE_STRIP);
        for (int theta = 0; theta < 360; theta++)
        {
            glColor4f(transformedCircle[theta].r, transformedCircle[theta].g, transformedCircle[theta].b, transformedCircle[theta].a);
            glVertex3f(transformedCircle[theta].pos.vec[0], transformedCircle[theta].pos.vec[1], 0.0f);
        }
        glEnd();


        glfwSwapBuffers(window);
        glfwPollEvents();

        renderDuration = chrono::system_clock::now() - startRenderTimePoint;
        startRenderTimePoint = chrono::system_clock::now();

        float fps = 1.0 / renderDuration.count();
        if (isFirstFrame == true)
        {
            isFirstFrame = false;
            continue;
        }
        if (renderDuration.count() < (1.0f / 60.0f))
            this_thread::sleep_for(chrono::milliseconds((int)(((1.0f / 60.0f) - renderDuration.count()) * 1000)));
        string fps_s = "FPS : " + to_string(fps);
        std::cout << fps_s << endl;

    }
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
    Init();
    Update();
    Release();

    exit(EXIT_SUCCESS);
}