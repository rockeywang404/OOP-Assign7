#include "gameObjectFactory.h"
#include "environment.h"
#include "iconFactory.h"
#include "unit.h"
#include <chrono>
#include <random>
#include <set>
std::random_device rd;
std::mt19937 engine(rd());
std::uniform_int_distribution<int> distX(0, GAME_WINDOW_WIDTH - 1);
std::uniform_int_distribution<int> distY(0, GAME_WINDOW_HEIGHT - 1);

PlayerGameObject *SimpleGameObjectFactory::playerGameObject() {

  int x = distX(engine);
  int y = distY(engine);
  return new PlayerGameObject(Position{x, y});
}
DiamondGameObject *SimpleGameObjectFactory::diamondGameObject() {
  int x = distX(engine);
  int y = distY(engine);
  return new DiamondGameObject(Position{x, y});
}
WallGameObject *SimpleGameObjectFactory::wallGameObject() {
  int x = distX(engine);
  int y = distY(engine);

  Size size = Size(rand() % 3 + 1, rand() % 2 + 1);
  
  return new WallGameObject(Position{x, y}, size);
}
MonsterGameObject *SimpleGameObjectFactory::monsterGameObject() {
  int x = distX(engine);
  int y = distY(engine);
  return new MonsterGameObject(Position{x, y});
}
