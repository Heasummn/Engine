#include "graphics/window.h"

using namespace engine::graphics;

int main(int argc, char* argv[])
{
    Window window("Very creatively named Engine");
    while(!window.closed())
    {
        window.clear();
        glClearColor(0.0, 0.5, 0.7, 1.0);
        glBegin(GL_TRIANGLES);
            glVertex2f(-0.5f, -0.5f);
            glVertex2f(-0.5f,  0.5f);
            glVertex2f( 0.5f, -0.5f);
        glEnd();
        window.tick();
    }
}