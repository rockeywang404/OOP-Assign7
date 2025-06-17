#ifndef PLAYER_GAME_OBJECT_H
#define PLAYER_GAME_OBJECT_H

#include "gameObject.h"
#include "collider.h"
#include "unit.h"

class PlayerGameObject : public GameObject {
public:
    PlayerGameObject(Position pos);
	void update(const std::vector<GameObject*>& objects) override;
	int getScore() const { return _score; }
	bool onCollision(ICollider* other);
	bool intersect(ICollider* other);
private:
    int _score = 0;
};

#endif
