#include <iostream>
#include "Window.h"
#include "Widget.h"
#include "Label.h"

int main(int, char**)
{
    auto window = gui::Window::construct("My Window");
    auto label = gui::Label::construct();

    label->set_text("Hello, World!");
    window->set_main_widget(label);

    return window->show();
}
