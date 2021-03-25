//
// Created by olli on 06/05/20.
//

#ifndef STRUCTURE_TEMPLATE_H
#define STRUCTURE_TEMPLATE_H

template<typename T>
class TemplateLib {
private:
    T stuff;

public:
    explicit TemplateLib(T p);

    T getStuff();
    void setStuff(T val);
};

template<typename T>
TemplateLib<T>::TemplateLib(T p) : stuff(p) { }

template<typename T>
T TemplateLib<T>::getStuff() {
    return stuff;
}

template<typename T>
void TemplateLib<T>::setStuff(T val) {
    stuff = val;
}

#endif //STRUCTURE_TEMPLATE_H
