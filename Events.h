#ifndef EVENTS_H
#define EVENTS_H

#include <glm/glm.hpp>

namespace gui
{

enum MouseButton
{
    Left = 0,
    Right = 1
};

struct Event
{
    Event(class Window* window) : window(window) {}
    Window* window;
};

struct HandleableEvent : public Event
{
    HandleableEvent(Window* win) : Event(win) {}
    mutable bool handled = false;
};

struct RedrawEvent : public Event
{
    RedrawEvent(Window* win) : Event(win) {}
};

struct ResizeEvent : public Event
{
    ResizeEvent(Window* win) : Event(win) {}
};

struct ClickEvent : public HandleableEvent
{
    ClickEvent(Window* win, int x, int y, unsigned button)
        : HandleableEvent(win), x(x), y(y), button(MouseButton(button))
    {
    }
    int x;
    int y;
    MouseButton button;
};

} // namespace gui

#endif // EVENTS_H
