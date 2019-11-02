#include "Widget.h"

void gui::Widget::fire_redraw_event(const gui::RedrawEvent& event)
{
    on_redraw(event);
    for_each_child([&](Widget* child) { child->fire_redraw_event(event); });
}

void gui::Widget::fire_resize_event(const gui::ResizeEvent& event)
{
    on_resize(event);
    for_each_child([&](Widget* child) { child->fire_resize_event(event); });
}

void gui::Widget::fire_click_event(const gui::ClickEvent& event)
{
    if (!event.handled)
        on_click(event);
    for_each_child([&](Widget* child) 
    { 
        if (!event.handled)
            child->fire_click_event(event); 
    });
}

gui::Widget::Widget(Widget* parent) : m_parent(parent)
{
    if (m_parent)
    {
        m_parent->register_child(this);
    }
}

void gui::Widget::register_child(Widget* child) { m_children.push_back(child); }
