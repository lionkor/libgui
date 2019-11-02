#ifndef LK_WIDGET_H
#define LK_WIDGET_H

#include "Object.h"
#include "String.h"
#include "StringBuilder.h"
#include "StringView.h"
#include "Window.h"
#include <vector>

namespace gui
{

class Window;

enum class LayoutHint
{
    Fixed,
    Dynamic
};

class Widget
{
    OBJECT(Widget)
    VIRTUAL_DTOR(Widget)
public:
    virtual void fire_redraw_event(gui::Window*) final;
    virtual void fire_resize_event(gui::Window*) final;

    
protected:
    Widget(Widget* parent = nullptr);

    template<typename _Function>
    void for_each_child(_Function func)
    {
        for (Widget* child : m_children)
        {
            func(child);
        }
    }
    L
    template<typename _Function>
    void for_each_child(_Function func) const
    {
        for (const Widget* child : m_children)
        {
            func(child);
        }
    }
    
    Widget* m_parent;
    std::vector<Widget*> m_children; // FIXME: Is vector the right thing here?
    virtual void on_redraw(gui::Window*) {}
    virtual void on_resize(gui::Window*) {}

private:
    void register_child(Widget*);
};

} // namespace LK

#endif // LK_WIDGET_H
