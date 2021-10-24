//
// Created by 柴长林 on 2021/10/24.
//
#include <tuple>
#include <utility>
class Shape {
 public:
  using value_type = double;
  virtual ~Shape() = default;
};
class Shape2D : public Shape {
 public:
  using value_type = Shape::value_type;
  using Coordinate = std::pair<value_type, value_type>;
  virtual value_type perimeter() const = 0;
  virtual value_type area() const = 0;
};
class Shape3D : public Shape {
 public:
  using value_type = Shape::value_type;
  using Coordinate = std::tuple<value_type, value_type, value_type>;
  virtual value_type area() const = 0;
  virtual value_type volumn() const = 0;
};

class Circle : public Shape2D {};
class Square : public Shape2D {};
class Rectangle : public Shape2D {};

class Sphere : public Shape3D {};
class Cube : public Shape3D {};
class Cone : public Shape3D {};