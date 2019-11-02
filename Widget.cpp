#include "Widget.h"

LK::Widget::Widget(Widget* parent) : m_parent(parent)
{
    if (m_parent)
    {
        m_parent->register_child(this);
    }
}

void LK::Widget::register_child(Widget* child) { m_children.push_back(child); }

void LK::Widget::fire_redraw_event(Window* window)
{
    for_each_child([&](Widget* child) { child->fire_redraw_event(window); });
    on_redraw(window);
}

void LK::Widget::fire_resize_event(LK::Window* window) 
{
    for_each_child([&](Widget* child) { child->fire_resize_event(window); });
    on_resize(window);
}
