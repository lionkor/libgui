#include "Button.h"

void gui::Button::on_redraw(const gui::RedrawEvent&)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void gui::Button::on_click(const gui::ClickEvent& event)
{
    if (click_event_callback)
    {
        click_event_callback(MouseButton(event.button));
    }
    event.handled = true;
}
