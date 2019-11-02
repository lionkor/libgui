#ifndef BUTTON_H
#define BUTTON_H

#include "Label.h"
#include "Object.h"
#include "Events.h"
#include <functional>

namespace gui
{

class Button : public Label
{
    OBJECT(Button)
    WIDGET_CTOR(Button, Label)
    VIRTUAL_DTOR(Button)
public:
    
    std::function<void(MouseButton)> click_event_callback;
protected:
    void on_redraw(const gui::RedrawEvent&);
    void on_click(const gui::ClickEvent&);
};

}

#endif // BUTTON_H
