#ifndef LK_WIDGET_H
#define LK_WIDGET_H

#include "Object.h"
#include "String.h"
#include "StringBuilder.h"
#include "StringView.h"
#include "Window.h"
#include <vector>

namespace LK
{

class Window;

class Widget
{
    OBJECT(Widget)
    VIRTUAL_DTOR(Widget)
public:
    virtual void fire_redraw_event(LK::Window*) final;
    virtual void fire_resize_event(LK::Window*) final;

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
    virtual void on_redraw(LK::Window*) {}
    virtual void on_resize(LK::Window*) {}

private:
    void register_child(Widget*);
};

} // namespace LK

#endif // LK_WIDGET_H
