#include "Label.h"

void gui::Label::on_redraw(const gui::RedrawEvent& event)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    event.window->paint_string(m_text, m_pos.x, m_pos.y, "black");
}
