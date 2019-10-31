#ifndef LK_WINDOW_H
#define LK_WINDOW_H

#include "String.h"
#include "StringView.h"
#include "StringBuilder.h"

#include "Object.h"

using ulong=unsigned long;

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
    OBJECT(Window)
public:
    virtual ~Window();
    
    /// Gives the Window the signal to close down.
    void close();

    /// Forces the window to redraw.
    void redraw();

    /// Blocking call. 
    /// Enters event loop, shows the window, etc.
    /// returns 0 on success.
    int show();
protected:
    Window(const String& title = "Window");
    String m_title;
    bool m_open;

    // X11
    Display* m_display;
    int m_screen;
    X::Window m_window;
    GC m_graphics_context;
};

}


#endif //LK_WINDOW_H
