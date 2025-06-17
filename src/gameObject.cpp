#include "gameObject.h"
#include "environment.h"

GameObject::GameObject(Icon icon, Position pos) : _icon(icon), _pos(pos) {
  _dir = NONE;
}
GameObject::~GameObject() {}

/*void GameObject::update(const std::vector<GameObject*>& obj) {
  if (_dir == UP && _pos.y() != 0) {
    _pos.y()--;
  } else if (_dir == LEFT && _pos.x() != 0) {

    _pos.x()--;
  } else if (_dir == DOWN && _pos.y() < GAME_WINDOW_HEIGHT - 1) {

    _pos.y()++;
  } else if (_dir == RIGHT && _pos.x() < GAME_WINDOW_WIDTH - 1) {

    _pos.x()++;
  }
}*/

void GameObject::setDirection(Direction dir) { _dir = dir; }

void GameObject::setDead() {_isDead = true;}

void GameObject::setPosition(int x, int y) { _pos = Position(x, y); }

bool GameObject::isDead() const {return _isDead;}

bool GameObject::intersect(ICollider* other) {
    auto* otherObj = dynamic_cast<GameObject*>(other);
    if (!otherObj) return false;
    return this->getPosition() == otherObj->getPosition();
}

bool GameObject::onCollision(ICollider* other) {
    return false;
}

