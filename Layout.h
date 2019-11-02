#ifndef LAYOUT_H
#define LAYOUT_H

#include "Object.h"

namespace gui
{
class Layout
{
    VIRTUAL_DTOR(Layout)
public:
    virtual void layout(class Widget*) = 0;
protected:
    Layout() {}
};

}

#endif // LAYOUT_H
