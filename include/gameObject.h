#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include "unit.h"
#include "icon.h"
#include <iostream>
class GameObject{

public:
    GameObject(Icon icon, Vec2 pos = {0, 0});

    virtual ~GameObject();
    virtual void update();
    Icon getIcon() const;
    void setDirection(Direction);
    Vec2 getPosition() const;
protected:

    Direction _dir;
    Vec2 _pos;
    Icon _icon;
};

inline Icon GameObject::getIcon() const{
    return _icon;
}

inline Vec2 GameObject::getPosition() const {
    return _pos;
}
#endif
