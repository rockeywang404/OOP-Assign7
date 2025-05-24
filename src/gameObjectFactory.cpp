#include "gameObjectFactory.h"
#include "environment.h"
#include "iconFactory.h"
#include <chrono>
#include <random>
#include <set>
std::random_device rd;
std::mt19937 engine(rd());
std::uniform_int_distribution<int> distX(0, GAME_WINDOW_WIDTH - 1);
std::uniform_int_distribution<int> distY(0, GAME_WINDOW_HEIGHT - 1);

GameObject *SimpleGameObjectFactory::playerGameObject() {

  int x = distX(engine);
  int y = distY(engine);
  return new GameObject(IconFactory::NxMColor(Size(1, 1), RED), Position{x, y});
}
GameObject *SimpleGameObjectFactory::randomGameObject() {
  int x = distX(engine);
  int y = distY(engine);
  return new GameObject(IconFactory::NxMColor(Size(2, 2), BLUE),
                        Position{x, y});
}
