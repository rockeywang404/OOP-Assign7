#include "iconFactory.h"

Icon IconFactory::NxMColor(Size size, Color color) {

  Icon icon;
  for (int h = 0; h < height; ++h) {

    std::vector<Cell> row;

    for (int w = 0; w < width; ++w) {
      row.emplace_back(Cell(color, " "));
    }

    icon.emplace_back(row);
  }

  return icon;
}
