#include "Point.hpp"

static Fixed calculateArea(Point const &p1, Point const &p2, Point const &p3) {
    return Fixed((p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat()) +
                  p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat()) +
                  p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat())) /
                 2.0f)
        .toFloat();
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed totalArea = calculateArea(a, b, c);
    Fixed area1 = calculateArea(point, b, c);
    Fixed area2 = calculateArea(a, point, c);
    Fixed area3 = calculateArea(a, b, point);

    if (area1.toFloat() <= 0 || area2.toFloat() <= 0 || area3.toFloat() <= 0) {
        return false;
    }
    return (area1 + area2 + area3) == totalArea;
}
