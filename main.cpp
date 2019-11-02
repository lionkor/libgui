#include <iostream>
#include "Window.h"
#include "Widget.h"
#include "Label.h"
#include "Button.h"
#include "Events.h"

class MyWidget : public gui::Widget
{
    OBJECT(MyWidget)
    WIDGET_CTOR(MyWidget, gui::Widget)
protected:
    void on_click(const gui::ClickEvent& event)
    {
        event.handled=false;
    }
};


int main(int, char**)
{
    auto window = gui::Window::construct("My Window");
    auto main_widget = MyWidget::construct();
    window->set_main_widget(main_widget);
    
    auto label = gui::Label::construct(main_widget);
    auto button = gui::Button::construct(main_widget);
    
    button->set_text("My Button");
    label->set_text("Hello, World!");
    
    button->click_event_callback = [&](auto)
    {
        std::cout << "button click" << std::endl;
    };

    return window->show();
}
