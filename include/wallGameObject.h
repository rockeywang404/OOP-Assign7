#ifndef WALL_GAME_OBJECT_H
#define WALL_GAME_OBJECT_H

#include "gameObject.h"
 
class WallGameObject : public GameObject {
public:
    WallGameObject(Position pos, Size size = Size(2, 2));
    std::vector<Position> getmorePositions() override;
	void update(const std::vector<GameObject*>& objects) override;
private:
    Size _size;
};

#endif
