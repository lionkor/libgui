#include "Window.h"

LK::Window::Window(const String& title)
    : m_title(title), m_open(false)
{
    m_display = XOpenDisplay((char*)0);
    m_screen = DefaultScreen(m_display);

    ulong black = BlackPixel(m_display, m_screen);
    ulong white = WhitePixel(m_display, m_screen);


    m_window = XCreateSimpleWindow(
            m_display, 
            DefaultRootWindow(m_display),
            0, 
            0,
            1280,
            720, 
            5, 
            white, 
            black
    );

    XSetStandardProperties(
            m_display, 
            m_window, 
            m_title.c_str(),
            m_title.c_str(),
            None,
            nullptr, 
            0,
            nullptr
    );

    XSelectInput(
            m_display, 
            m_window, 
            ExposureMask | ButtonPressMask | KeyPressMask
    );

    m_graphics_context = XCreateGC(
            m_display, 
            m_window, 
            0, 
            0
    );

    XSetBackground(
            m_display, 
            m_graphics_context,
            white
    );

    XSetForeground(
            m_display,
            m_graphics_context,
            black
    );

    XClearWindow(m_display, m_window);
    XMapRaised(m_display, m_window);
}

LK::Window::~Window()
{
    XFreeGC(m_display, m_graphics_context);
    XDestroyWindow(m_display, m_window);
    XCloseDisplay(m_display);
}

void LK::Window::close()
{
    std::cout << "close" << std::endl;
    m_open = false;
}

void LK::Window::redraw()
{
    std::cout << "redraw" << std::endl;
}


int LK::Window::show()
{
    m_open = true;

    XEvent event;
    KeySym key;
    char text[255];

    while (m_open)
    {
        // Note that only events for which a mask is set in the ctor
        // are detected here.
        XNextEvent(m_display, &event);
        if (event.type == Expose && event.xexpose.count == 0)
        {
            redraw();
        }

        if (event.type == KeyPress && XLookupString(&event.xkey, text, 255, &key, 0) == 1)
        {
            std::cout << "KeyPress: _" << text[0] << "_" << std::endl;
            if (text[0] == 'q')
            {
                close();
            }
        }
        
        if (event.type == ButtonPress)
        {
            std::cout << "ButtonPress: (" << event.xbutton.x << "," 
                << event.xbutton.y << ")" << std::endl;
        }
    }
    return 0;
}

