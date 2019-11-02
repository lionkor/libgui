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
    WIDGET_CTOR_ARGS(Label, Widget, m_text("label"), m_pos(20, 20))
    VIRTUAL_DTOR(Label)
public:
    inline StringView text() const { return m_text.as_string_view(); }
    inline void set_text(const String& text) { m_text = text; }

protected:
    void on_redraw(const RedrawEvent&);

    String m_text;
    glm::vec<2, int> m_pos;
    
};

} // namespace LK

#endif // LABEL_H
