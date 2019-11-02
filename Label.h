#ifndef LABEL_H
#define LABEL_H

#include "Object.h"
#include "Widget.h"
#include <glm/glm.hpp>

namespace gui
{

class Label : public Widget
{
    OBJECT(Label)
    VIRTUAL_DTOR(Label)
public:
    inline StringView text() const { return m_text.as_string_view(); }
    inline void set_text(const String& text) { m_text = text; }

protected:
    Label(Widget* parent = nullptr);

    virtual void on_redraw(Window* window);
    virtual void on_resize(Window* window);

    String m_text;
    glm::vec<2, int> m_pos;
};

} // namespace LK

#endif // LABEL_H
