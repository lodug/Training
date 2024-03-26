//define the interface of an observer

#pragma once
#include <string>

template <typename T>
//So this base class is going to have a template argument where T is the type of the object we're actually observing.
class Observer
{
    //informations about what fields changed: We take a reference tp the source, the object which actually changed and the name of the field that changed
    virtual void fields_changed(T& source, field_name) = 0;
}
