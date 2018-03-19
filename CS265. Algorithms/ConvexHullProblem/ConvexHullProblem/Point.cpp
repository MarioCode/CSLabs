//
//  Point.cpp
//  ConvexHullProblem
//

#include <stdio.h>

// Point
struct Point
{
  int x;
  int y;
  
  bool operator < (const Point &p) const {
    if (y != p.y)
      return y < p.y;
    
    return x < p.x;
  }
  
  bool operator == (const Point &p) const {
    return (y == p.y && x == p.x);
  }
};

