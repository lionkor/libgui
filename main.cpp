#include <iostream>
#include "Window.h"

int main(int argc, char** argv)
{
    auto window = LK::Window::construct("My Window");


    return window->show();
}
