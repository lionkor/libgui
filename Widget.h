#ifndef LK_WIDGET_H
#define LK_WIDGET_H

#include "Object.h"
#include "String.h"
#include "StringBuilder.h"
#include "StringView.h"
#include "Events.h"
#include "Window.h"
#include <vector>

#define WIDGET_CTOR(classname, super) \
public:\
    classname(Widget* parent = nullptr) : super(parent) {}\
    template<typename _WidgetSmartPtr>\
    classname(_WidgetSmartPtr& parent = nullptr) : super(parent.get()) {}

#define WIDGET_CTOR_ARGS(classname, super, ...) \
public:\
    classname(Widget* parent = nullptr) : super(parent), __VA_ARGS__ {}\
    template<typename _WidgetSmartPtr>\
    classname(_WidgetSmartPtr& parent = nullptr) : super(parent.get()), __VA_ARGS__ {}

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
    virtual void fire_redraw_event(const RedrawEvent&) final;
    virtual void fire_resize_event(const ResizeEvent&) final;
    virtual void fire_click_event(const ClickEvent&) final;
    
protected:
    Widget(Widget* parent = nullptr);
    
    // events that return bool: return "already handled"
    virtual void on_redraw(const RedrawEvent&) {}
    virtual void on_resize(const ResizeEvent&) {}
    virtual void on_click(const ClickEvent&) {}

    template<typename _Function>
    void for_each_child(_Function func)
    {
        for (Widget* child : m_children)
        {
            func(child);
        }
    }
    
    Widget* m_parent;
    std::vector<Widget*> m_children; // FIXME: Is vector the right thing here?
    
private:
    void register_child(Widget*);
};

} // namespace LK

#endif // LK_WIDGET_H
