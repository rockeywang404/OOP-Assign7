#include "iconFactory.h"

Icon IconFactory::NxMColor(Size size, Color color) {

  Icon icon;
  for (int h = 0; h < size.height(); ++h) {

    std::vector<Cell> row;

    for (int w = 0; w < size.width(); ++w) {
      row.emplace_back(Cell(color, " "));
    }

    icon.emplace_back(row);
  }

  return icon;
}
Icon IconFactory::NxMDiamond(Size size, Color color) {

  Icon icon;
  for (int h = 0; h < size.height(); ++h) {

    std::vector<Cell> row;

    for (int w = 0; w < size.width(); ++w) {
      row.emplace_back(Cell(color, "d"));
    }

    icon.emplace_back(row);
  }

  return icon;
}
Icon IconFactory::NxMMonster(Size size, Color color) {
 
  Icon icon;
  for (int h = 0; h < size.height(); ++h) {

    std::vector<Cell> row;

    for (int w = 0; w < size.width(); ++w) {
      row.emplace_back(Cell(color, "m"));
    }

    icon.emplace_back(row);
  }

  return icon;
}
