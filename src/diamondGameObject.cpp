#include "diamondGameObject.h"
#include "iconFactory.h"

DiamondGameObject::DiamondGameObject(Position pos)
    : GameObject(IconFactory::NxMDiamond(Size(1, 1), BLUE), pos) {}
 
void DiamondGameObject::update(const std::vector<GameObject*>& objects) {
}
