#include "Label.h"

LK::Label::Label(LK::Widget* parent)
    : Widget(parent), m_text("Label"), m_pos(20, 20)
{
}

void LK::Label::on_redraw(LK::Window* window)
{
    window->paint_string(m_text, m_pos.x, m_pos.y, "black");
}

void LK::Label::on_resize(LK::Window* window)
{
}
