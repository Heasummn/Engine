//
// Created by heasummn on 8/15/16.
//

#ifndef ENGINE_WINDOW_H
#define ENGINE_WINDOW_H

#include <GLFW/glfw3.h>

namespace engine
{
    namespace graphics
    {
        class Window
        {
        private:
            const char* _name;
            int _width, _height;
            GLFWwindow* _window;

        public:
            Window(const char* name, int width = 640, int height = 480);
            void tick();
            void clear();
            bool closed();
            void close();

        private:
            bool init();
            static void resizeHandler(GLFWwindow *window, int width, int height);
        };
    }
}


#endif //ENGINE_WINDOW_H
