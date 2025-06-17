#ifndef MONSTER_GAME_OBJECT_H
#define MONSTER_GAME_OBJECT_H

#include "gameObject.h"
 
class MonsterGameObject : public GameObject {
public:
    MonsterGameObject(Position pos);
	bool onCollision(ICollider* other) override;
	void update(const std::vector<GameObject*>& objects) override;
protected:
	void _moveAI(const std::vector<GameObject*>& objects);
};

#endif
