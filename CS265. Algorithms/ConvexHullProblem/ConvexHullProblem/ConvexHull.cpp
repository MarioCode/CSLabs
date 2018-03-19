//
//  ConvexHull.cpp
//  ConvexHullProblem
//

#include "ConvexHull.h"

Point ConvexHull::firstPoint;

// Constructor
ConvexHull::ConvexHull(Point *_points, int size)
{
  points = new Point[size];
  countPoints = size;
  for (int i = 0; i < size; i++)
  {
    points[i] = _points[i];
  }
}

// Destructor (delete points)
ConvexHull::~ConvexHull()
{
  delete[] points;
}


////////////////////////////////////////////////
//////////////// Base methods //////////////////


// Returns the square of the distance between the two points
int ConvexHull::distanceBetweenPoints(Point p1, Point p2)
{
  return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}


// To find orientation of ordered triplet (p, q, r).
int ConvexHull::orientation(Point a, Point b, Point c)
{
  int area = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
  
  if (area == 0)
    return 0;
  
  return (area > 0) ? 1 : 2;
}


// Vertex traversal
Point ConvexHull::nextToTop(std::stack<Point> &hull)
{
  Point p = hull.top();
  hull.pop();
  Point result = hull.top();
  hull.push(p);
  return result;
}


// Swap two point
void ConvexHull::swap(Point &p1, Point &p2)
{
  Point tmpPoint = p1;
  p1 = p2;
  p2 = tmpPoint;
}


// Compare two points
int ConvexHull::compare(const void *point1, const void *point2) {
  Point *a = (Point *)point1;
  Point *b = (Point *)point2;
  int order = ConvexHull::orientation(ConvexHull::firstPoint, *a, *b);

  if (order == 0)
    return (ConvexHull::distanceBetweenPoints(ConvexHull::firstPoint, *b) >= ConvexHull::distanceBetweenPoints(ConvexHull::firstPoint, *a)) ? -1 : 1;
  
  return (order == 2) ? -1: 1;
}


// Run main algorithm
void ConvexHull::runConvexHull() {
  
  int yMin = points[0].y;
  int minPoint = 0;
  
  for (int i = 0; i < countPoints; i++)
  {
    int y = points[i].y;
    if (y < yMin || (y == yMin && points[i].x < points[minPoint].x)) {
      yMin = points[i].y;
      minPoint = i;
    }
  }
  
  swap(points[0], points[minPoint]);
  
  firstPoint = points[0];
  qsort(&points[1], countPoints - 1, sizeof(Point), compare);
  
  std::stack<Point> resultHull;
  resultHull.push(points[0]);
  resultHull.push(points[1]);
  resultHull.push(points[2]);
  
  for (int i = 3; i < countPoints; i++)
  {
    while(orientation(nextToTop(resultHull), resultHull.top(), points[i])!=2)
      resultHull.pop();
    
    resultHull.push(points[i]);
  }
  
  std::cout << "Finish path: \n";
  int count = 1;
  
  while(!resultHull.empty())
  {
    Point point = resultHull.top();
    std::cout << count++ <<  ": (" << point.x << ", " << point.y << ")" << std::endl;
    resultHull.pop();
  }
}



