#include "playerGameObject.h"
#include "iconFactory.h"
#include "environment.h"
#include "wallGameObject.h"
#include "diamondGameObject.h"
#include "monsterGameObject.h"

PlayerGameObject::PlayerGameObject(Position pos)
    :_score(0), GameObject(IconFactory::NxMColor(Size(1, 1), RED), pos) {}

void PlayerGameObject::update(const std::vector<GameObject*>& objects) {
	Vec2 nextPos = _pos;

	if (_dir == UP && _pos.y() != 0) {
        nextPos.y()--;
    } else if (_dir == LEFT && _pos.x() != 0) {
        nextPos.x()--;
    } else if (_dir == DOWN && _pos.y() < GAME_WINDOW_HEIGHT - 1) {
        nextPos.y()++;
    } else if (_dir == RIGHT && _pos.x() < GAME_WINDOW_WIDTH - 1) {
        nextPos.x()++;
    }

	bool canMove = true;
    for (auto obj : objects) {
	    if (obj == this) continue;
    	if (auto wall = dynamic_cast<WallGameObject*>(obj)) {
        	for (const auto& wallPos : wall->getmorePositions()) {
            	if (wallPos == nextPos) {
                	canMove = false;
                	break;
            	}
        	}
    	}
	}
	if (canMove) {_pos = nextPos;}
}

bool PlayerGameObject::onCollision(ICollider* other) {
    if (auto diamond = dynamic_cast<DiamondGameObject*>(other)) {
        _score++;
        diamond->setDead(); 
		return true;
    }
    if (auto monster = dynamic_cast<MonsterGameObject*>(other)) {
        this->setDead(); 
		return true;
    }
    return false;
}

bool PlayerGameObject::intersect(ICollider* other) {
    auto otherObj = dynamic_cast<GameObject*>(other);
    if (!otherObj) return false;

    return this->getPosition() == otherObj->getPosition();
}
