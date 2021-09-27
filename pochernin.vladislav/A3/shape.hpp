#ifndef SHAPE_HPP
#define SHAPE_HPP

namespace pochernin
{
  struct point_t;
  struct rectangle_t;

  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& destination) = 0;
    virtual void move(double dx, double dy) = 0;
    void scale(double factor);

  private:
    virtual void doScale(double factor) = 0;
  };

  double getX(const Shape& shape);
  double getY(const Shape& shape);
  double getWidth(const Shape& shape);
  double getHeight(const Shape& shape);
}

#endif
