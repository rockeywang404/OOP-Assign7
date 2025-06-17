#ifndef DIAMOND_GAME_OBJECT_H
#define DIAMOND_GAME_OBJECT_H

#include "gameObject.h"

class DiamondGameObject : public GameObject {
public:
    DiamondGameObject(Position pos);
    void update(const std::vector<GameObject*>& objects) override;
};

#endif
