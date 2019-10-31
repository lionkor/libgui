#ifndef LK_WIDGET_H
#define LK_WIDGET_H

#include "Object.h"
#include <vector>

namespace LK
{

class Window;

class Widget
{
    OBJECT(Widget);
public:
    
protected:
    Widget(Widget* parent = nullptr);

    Widget* m_parent;
    std::vector<Widget*> m_children; // FIXME: Is vector the right thing here?

private:
    void register_child(Widget*);
};


}

#endif//LK_WIDGET_H
