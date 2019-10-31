#ifndef LK_OBJECT_H
#define LK_OBJECT_H

#include <memory>
#include <utility>

#define OBJECT(x)\
public:\
    virtual inline const char* class_name() const { return #x; }\
    template<typename... _Args>\
    static std::unique_ptr<x> construct(_Args&&... args)\
    {\
        return std::unique_ptr<x>(new x(std::forward<_Args>(args)...));\
    }

#endif//LK_OBJECT_H
