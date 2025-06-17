#include "playerGameObject.h"
#include "monsterGameObject.h"
#include "wallGameObject.h"
#include "diamondGameObject.h"
#include "unit.h"

struct SimpleGameObjectFactory {
    
    static PlayerGameObject* playerGameObject();
    static DiamondGameObject* diamondGameObject();
    static WallGameObject* wallGameObject();
    static MonsterGameObject* monsterGameObject();
};  
