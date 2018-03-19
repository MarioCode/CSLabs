//
//  main.cpp
//  ConvexHullProblem
//

#include "ConvexHull.h"
#include <iostream>
#include <vector>

int main()
{
  Point points[] = {{2,2}, {1,3}, {4,1}, {0,0}, {5,-2}, {6,3}, {3,0}};
  ConvexHull cHull(points, sizeof(points)/sizeof(points[0]));
  cHull.runConvexHull();

  return 0;
}

