#ifndef UNIT_H
#define UNIT_H

#include <string>
#include <cmath>

class Unit
{
public:
    Unit();
    ~Unit();

    int x() const;
    void setX(int newX);

    int y() const;
    void setY(int newY);

    float r_x() const;
    float r_y() const;

    void setRadiusVector(float newR_x, float newR_y);

    float angle() const;
    void setAngle(float newAngleDegrees);

    int distance() const;
    void setDistance(int newDistance);

    void setData( const std::string &data );

    int countVisibilyUnits() const;
    void setCountVisibilyUnits(int newCountVisibilyUnits);

    int distance_2() const;
    float radiusVector() const;

private:
    int x_ = {};
    int y_ = {};
    float r_x_ = {};
    float r_y_ = {};
    float angle_rad_ = {};
    int distance_ = {};
    int countVisibilyUnits_ = {};

    int distance_2_ = {};
    float radiusVector_;
};

inline int Unit::x() const{
    return x_;
}

inline void Unit::setX(int newX){
    x_ = newX;
}

inline int Unit::y() const{
    return y_;
}

inline void Unit::setY(int newY){
    y_ = newY;
}

inline float Unit::r_x() const{
    return r_x_;
}

inline float Unit::r_y() const{
    return r_y_;
}

inline void Unit::setRadiusVector(float newR_x, float newR_y)
{
    r_x_ = newR_x;
    r_y_ = newR_y;
    radiusVector_ = atan2f( r_x_, r_y_ );
    if( radiusVector_ < 0 )
        radiusVector_ += 2 * M_PI;
}

inline float Unit::angle() const{
    return angle_rad_;
}

inline void Unit::setAngle(float newAngleDegrees){
    angle_rad_ = newAngleDegrees * M_PI / 180.;
}

inline int Unit::distance() const{
    return distance_;
}

inline void Unit::setDistance(int newDistance){
    distance_ = newDistance;
    distance_2_ = distance_ * distance_;
}

inline int Unit::countVisibilyUnits() const
{
    return countVisibilyUnits_;
}

inline void Unit::setCountVisibilyUnits(int newCountVisibilyUnits)
{
    countVisibilyUnits_ = newCountVisibilyUnits;
}

inline int Unit::distance_2() const
{
    return distance_2_;
}

inline float Unit::radiusVector() const
{
    return radiusVector_;
}


#endif // UNIT_H
