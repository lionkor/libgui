#include <iostream>
#include "Window.h"
#include "Widget.h"
#include "Label.h"

int main(int, char**)
{
    auto window = LK::Window::construct("My Window");
    auto label = LK::Label::construct();

    label->set_text("Hello, World!");
    window->set_main_widget(label);

    return window->show();
}
