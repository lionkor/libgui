# libgui

(heavy WIP)

A fast and simple C++ GUI library for X11. 
Support for other environments and OS's is on the roadmap.

## Philosophy

Systems back in the day used to be really fast in comparison to today. 
This is partially because of the many layers of abstractions that often
lie between the programmer and the hardware, which is a pretty new phenomenon. 

Instead of getting confused with all the huge and/or legacy GUI libraries and writing GUI apps in something like JavaScript in electron, I want to go back to the roots and design a GUI library for Desktop PCs that is fast and easy to use. 

Currently I'm using my own String library. It's slower than std::string, but I enjoy the interface a lot more. This is probably the only thing that I'll use *instead* of an STD/STL version. This might be a good way to implement Unicode support later down the line, and it makes sense, since most text on the gui (buttons, labels, etc) won't change. 
