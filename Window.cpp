#include "Window.h"
#include "Widget.h"
#include <cassert>

LK::Window::Window(const String& title) : m_title(title), m_open(false)
{
    m_display = XOpenDisplay(static_cast<char*>(nullptr /* = Display 0 */));
    m_screen = DefaultScreen(m_display);

    ulong black = BlackPixel(m_display, m_screen);
    ulong white = WhitePixel(m_display, m_screen);


    m_window = XCreateSimpleWindow(m_display, DefaultRootWindow(m_display), 0, 0, 1280,
                                   720, 5, white, white);

    XSetStandardProperties(m_display, m_window, m_title.c_str(), m_title.c_str(), None,
                           nullptr, 0, nullptr);

    XSelectInput(m_display, m_window,
                 ExposureMask | ButtonPressMask | KeyPressMask | StructureNotifyMask);

    m_graphics_context = XCreateGC(m_display, m_window, 0, nullptr);

    XSetBackground(m_display, m_graphics_context, white);

    // XSetForeground(m_display, m_graphics_context, black);
    set_foreground_color("black");

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
    // XSetForeground( m_display, m_graphics_context, BlackPixel(m_display,0)^GetColor(
    // m_display, "white")  );
    if (m_main_widget)
    {
        m_main_widget->fire_redraw_event(this);
    }
    else
    {
        std::cerr << "Window doesn't have a main widget!" << std::endl;
    }

    XFlush(m_display);
}

int LK::Window::show()
{
    m_open = true;

    EventData event_data;

    while (m_open)
    {
        // Note that only events for which a mask is set in the ctor
        // are detected here.
        XNextEvent(m_display, &event_data.event);

        switch (event_data.event.type)
        {
            // case EVENTTYPE: {} break;
            case Expose:
                handle_x_expose_event(event_data);
                break;
            case KeyPress:
                handle_x_key_press_event(event_data);
                break;
            case ButtonPress:
                handle_x_button_press_event(event_data);
                break;
            case ConfigureNotify:
                handle_x_configure_notify_event(event_data);
                break;
            default:
                std::cerr << "Unhandled event: " << event_data.event.type << std::endl;
                break;
        }
    }
    return 0;
}

XColor LK::Window::get_color(const StringView& name)
{
    XColor tmp;
    XParseColor(m_display, DefaultColormap(m_display, m_screen), name.chars(), &tmp);
    XAllocColor(m_display, DefaultColormap(m_display, m_screen), &tmp);
    return tmp;
}

void LK::Window::handle_x_expose_event(EventData& event_data)
{
    if (event_data.event.xexpose.count == 0)
        redraw();
}

void LK::Window::handle_x_key_press_event(EventData& event_data)
{
    KeySym key;
    char text[255];
    if (XLookupString(&event_data.event.xkey, text, 255, &key, nullptr) == 1)
    {
        if (text[0] == 'q')
        {
            close();
        }
    }
    std::cout << "KeyPress: _" << text[0] << "_" << std::endl;
}

void LK::Window::handle_x_button_press_event(LK::Window::EventData& event_data)
{
    std::cout << "ButtonPress: (" << event_data.event.xbutton.x << ","
              << event_data.event.xbutton.y << ")" << std::endl;
}

void LK::Window::handle_x_configure_notify_event(LK::Window::EventData& event_data)
{
    auto configure_event = event_data.event.xconfigure;
    if (m_size.x != configure_event.x || m_size.y != configure_event.y)
    {
        // resize event
        m_size.x = configure_event.x;
        m_size.y = configure_event.y;
        m_main_widget->fire_resize_event(this);
    }
}

void LK::Window::set_foreground_color(const StringView& name)
{
    if (name.is_empty() || name == m_current_foreground_color_name)
        return;
    XColor tmp;
    XParseColor(m_display, DefaultColormap(m_display, m_screen), name.c_str(), &tmp);
    XAllocColor(m_display, DefaultColormap(m_display, m_screen), &tmp);
    XSetForeground(m_display, m_graphics_context, tmp.pixel);
    m_current_foreground_color_name = name;
}


void LK::Window::paint_string(const StringView& string, int x, int y,
                              const StringView& color)
{
    set_foreground_color(color);
    XDrawString(x_display(), x_window(), x_graphics_context(), x, y, string.c_str(),
                int(string.size()));
}
