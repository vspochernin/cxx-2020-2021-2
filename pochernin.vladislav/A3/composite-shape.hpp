#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <cstddef> // size_t
#include <memory>

#include "shape.hpp"

namespace pochernin
{
  class CompositeShape: public Shape
  {
  public:
    using ShapePtr = std::shared_ptr< Shape >;
    using ShapeArray = std::unique_ptr< ShapePtr[] >;

    CompositeShape(const CompositeShape& src);
    CompositeShape(CompositeShape&& src) noexcept = default;

    explicit CompositeShape(const ShapePtr shape, size_t capacity = 1);

    virtual ~CompositeShape() = default;

    std::shared_ptr< Shape > at(size_t index);
    std::shared_ptr< const Shape > at(size_t index) const;
    CompositeShape& operator=(const CompositeShape& src);
    CompositeShape& operator=(CompositeShape&& src) noexcept = default;

    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    virtual void move(const point_t& destination) override;
    virtual void move(double dx, double dy) override;
    void pushBack(const ShapePtr shape);
    void popBack();
    size_t size() const;
    size_t capacity() const;
    void swap (CompositeShape& other) noexcept;
    void reserve(size_t newCap);

  private:
    size_t size_;
    size_t capacity_;
    ShapeArray data_;

    virtual void doScale(double factor) override;
  };

  void swap(CompositeShape& cs1, CompositeShape& cs2) noexcept;
}

#endif
