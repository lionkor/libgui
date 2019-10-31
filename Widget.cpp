#include "Widget.h"

LK::Widget::Widget(Widget* parent)
    : m_parent(parent)
{
    if (m_parent)
    {
        m_parent->register_child(this);
    }
}

void LK::Widget::register_child(Widget* child)
{
    m_children.push_back(child);
}
