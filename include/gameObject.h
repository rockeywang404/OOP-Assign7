#ifndef ELEMENT_H
#define ELEMENT_H

#include "icon.h"
#include "unit.h"
#include <iostream>
#include <vector>
#include "collider.h"
class GameObject : public ICollider {

public:
  GameObject(Icon icon, Position pos = {0, 0});

  virtual ~GameObject();
  virtual void update(const std::vector<GameObject*>& objects) = 0;
  Icon getIcon() const;
  void setDirection(Direction);
  Vec2 getPosition() const;
  virtual std::vector<Position> getmorePositions() {return {getPosition()};}
  bool isDead() const;
  void setDead();
  bool intersect(ICollider* other) override;
  bool onCollision(ICollider* other) override;
  void setPosition(int x, int y); 

protected:
  Direction _dir;
  Vec2 _pos;
  Icon _icon;
  bool _isDead;
};

inline Icon GameObject::getIcon() const { return _icon; }

inline Vec2 GameObject::getPosition() const { return _pos; }
#endif
