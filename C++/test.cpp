#include <iostream>
#include <cmath>

using namespace std;


class Point{
protected:
    float x;
    float y;
public:
    Point(float x, float y);
    float calculateDistance(float x, float y);
};

class Point3D : public Point{
    float z;
public:
    Point3D(float i, float j, float z);
    float calculateDistance(float x, float y, float z);
    float calculateDistance(Point3D &p);
};

Point::Point(float x, float y){
    this->x = x;
    this->y = y;
};

Point3D::Point3D(float x, float y, float z) : Point(x, y){
    this->z = z;
};

float Point::calculateDistance(float x, float y)
{
    float n1 = ((this->x) - x)  * ( (this->x) - x );
    float n2 = ((this->y) - y)  * ( (this->y) - y );

    return sqrt(n1+n2);
}

float Point3D::calculateDistance(float x, float y, float z) 
{
    float n1 = ( ( (this->x) - x ) * ( (this->x) - x ) );
    float n2 = ( ( (this->y) - y ) * ( (this->y) - y ) );
    float n3 = ( ( (this->z) - z ) * ( (this->z) - z ) );

    return sqrt(n1+n2+n3);
}

float Point3D::calculateDistance(Point3D &p)
{
    return p.calculateDistance(p.x, p.y, p.z);
}



int main(){
    
    Point3D a(1,2,3);
    Point3D *p;
    cout << a.calculateDistance(a);
    return 0;
}