#include "monsterGameObject.h"
#include "iconFactory.h"
#include "environment.h"
#include "wallGameObject.h"
#include "playerGameObject.h"

MonsterGameObject::MonsterGameObject(Position pos)
    : GameObject(IconFactory::NxMMonster(Size(1, 1), YELLOW), pos) {}

void MonsterGameObject::update(const std::vector<GameObject*>& objects) {
    _moveAI(objects);
}


void MonsterGameObject::_moveAI(const std::vector<GameObject*>& objects) {
	int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    int dir = rand() % 4;

    Position curr = getPosition();
	
	int nextX = curr.x() + dx[dir];
    int nextY = curr.y() + dy[dir];
	
    if (nextX < 0 || nextX >= GAME_WINDOW_WIDTH) {
    	dx[dir] *= -1; 
    }
   
    if (nextY < 0 || nextY >= GAME_WINDOW_HEIGHT) {
   		dy[dir] *= -1;
	}
	nextX = curr.x() + dx[dir];
    nextY = curr.y() + dy[dir];
	Position nextPos(nextX, nextY);

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
	if (canMove) {setPosition(curr.x() + dx[dir], curr.y() + dy[dir]);}
}
bool MonsterGameObject::onCollision(ICollider* other) {
    if (auto player = dynamic_cast<PlayerGameObject*>(other)) {
        player->setDead(); 
        return true;
    }
	return true;
}
