#ifndef LK_WINDOW_H
#define LK_WINDOW_H

#include "String.h"
#include "StringBuilder.h"
#include "StringView.h"
#include <glm/glm.hpp>

#include "Object.h"

using ulong = unsigned long;

namespace X
{
// !!! The order of X11 includes is important
// clang-format off
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
// clang-format on
} // namespace X
using namespace X;


namespace LK
{

class Widget;


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

    /// Sets the main widget of this window.
    /// Accepts any smart pointer with `.get()`
    template<typename _WidgetPtr>
    void set_main_widget(_WidgetPtr& widget)
    {
        m_main_widget = widget.get();
    }

    /// Gets a color from the list of color names: docs/X11_RGB.html
    void set_foreground_color(const StringView& name);
    StringView foreground_color_name() const { return m_current_foreground_color_name; }

    inline X::Display* x_display() { return m_display; }
    inline X::Window& x_window() { return m_window; }
    inline X::GC& x_graphics_context() { return m_graphics_context; }
    inline int& x_screen() { return m_screen; }

    inline constexpr int width() const { return m_size.x; }
    inline constexpr int height() const { return m_size.y; }
    inline constexpr glm::vec<2, int> size() const { return m_size; }

    void paint_string(const StringView& string, int x, int y,
                      const StringView& color = "black");

protected:
    Window(const String& title = "Window");
    XColor get_color(const StringView& name);

    struct EventData
    {
        XEvent event;
    };

    void handle_x_expose_event(EventData&);
    void handle_x_key_press_event(EventData&);
    void handle_x_button_press_event(EventData&);
    void handle_x_configure_notify_event(EventData&);

    glm::vec<2, int> m_size;

    String m_title;
    StringView m_current_foreground_color_name;
    Widget* m_main_widget;
    Display* m_display;
    GC m_graphics_context;
    int m_screen;
    bool m_open;
    X::Window m_window;
};

} // namespace LK


#endif // LK_WINDOW_H
