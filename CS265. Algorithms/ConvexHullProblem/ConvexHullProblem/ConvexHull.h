//
//  ConvexHull.h
//  ConvexHullProblem
//

#ifndef ConvexHull_h
#define ConvexHull_h

#include "Point.cpp"
#include <iostream>
#include <stack>
#include <cstdlib>

class ConvexHull {

public:
  ConvexHull();
  ConvexHull(Point *_points, int size);
  ~ConvexHull();

  // Data member
  Point *points;
  int countPoints;
  static Point firstPoint;
  
  // Base methods
  void runConvexHull();
  void swap(Point &p1, Point &p2);
  
  // Static methods for using qsort
  static int distanceBetweenPoints(Point p1, Point p2);
  static int orientation(Point a, Point b, Point c);
  static int compare(const void *point1, const void *point2);
  Point nextToTop(std::stack<Point> &hull);
};

#endif /* ConvexHull_h */
