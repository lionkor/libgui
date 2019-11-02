#include "Label.h"

gui::Label::Label(gui::Widget* parent)
    : Widget(parent), m_text("Label"), m_pos(20, 20)
{
}

void gui::Label::on_redraw(gui::Window* window)
{
    window->paint_string(m_text, m_pos.x, m_pos.y, "black");
}

void gui::Label::on_resize(gui::Window* window)
{
}
