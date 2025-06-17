#include "wallGameObject.h"
#include "iconFactory.h"
#include "vector"

WallGameObject::WallGameObject(Position pos, Size size)
    : GameObject(IconFactory::NxMColor(size, GREEN), pos), _size(size) {}

void WallGameObject::update(const std::vector<GameObject*>& objects) {
}
std::vector<Position> WallGameObject::getmorePositions() {
    std::vector<Position> positions;
    for (int dy = 0; dy < _size.height(); dy++) {
        for (int dx = 0; dx < _size.width(); dx++) {
            positions.emplace_back(getPosition().x() + dx, getPosition().y() + dy);
        }
    }
    return positions;
}
