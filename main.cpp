#include <iostream>
#include "String.h"
#include "StringBuilder.h"
namespace X
{
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
}
using namespace X;

namespace LK
{

class Window 
{
public:
    Window()
    {
        unsigned long black;
        unsigned long white;

        m_display = XOpenDisplay((char*)0);
        m_screen = DefaultScreen(m_display);
        black = BlackPixel(m_display, m_screen);
        white = WhitePixel(m_display, m_screen);

        m_window = XCreateSimpleWindow(
                m_display, 
                DefaultRootWindow(m_display),
                0, 
                0,
                200,
                300, 
                5, 
                white, 
                black);


    }

protected:
    Display* m_display;
    int m_screen;
    X::Window m_window;
    GC m_graphics_context;
};

}

int main(int argc, char** argv)
{
    LK::Window window;

    return 0;
}
