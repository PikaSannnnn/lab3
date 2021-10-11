#include <iostream>
#include <string>
#include <cassert>

class vec
{
public:
    float data[3];

    float& operator[](size_t i)
    {
        return data[i];
    }

    const float& operator[](size_t i) const
    {
        return data[i];
    }
};

class object
{
public:
    std::string name;
    virtual void nill() {}
};

class sphere : public object
{
public:
    vec center;
    double radius;
    void nill() {}
};

class point : public object
{
public:
    vec location;
    void nill() {}
};

void set_names(object** objects, size_t number_objects, const std::string& base_name)
{
    for(size_t i = 0; i < number_objects; i++)
    {
        objects[i]->name = base_name + std::to_string(i);
    }
}

int main()
{
    object ** balls = new object*[10];
    object ** points = new object*[10];

    vec origin;
    for(size_t i = 0; i < 3; i++)
        origin[i] = 0;

    for(size_t i = 0; i < 10; i++) {
        // sphere* d_ball = dynamic_cast<sphere*> (*balls[i]);  // upcasting base -> derived
        // point* d_points = dynamic_cast<point*> (*points[i]);
        balls[i] = new sphere;
        sphere* d_ball = dynamic_cast<sphere*> (balls[i]);
        // points[i] = new point*;
        d_ball->center = origin;
        d_ball->radius = 0.1 * (i + 1);
        
        points[i] = new point;
        point* d_point = dynamic_cast<point*> (points[i]);
        // points[i] = new point*;
        d_point->location = origin;
        d_point->location[0] = 0.2 * i;
        // points[i]->location = origin;
        // points[i]->location[0] = 0.2 * i;
        
        // delete balls[i];
        // delete points[i];
    }
    
    // for(size_t i = 0; i < 10; i++)
    // {
    //     balls[i]->center = origin;
    //     balls[i]->radius = 0.1 * (i + 1);
    //     points[i]->location = origin;
    //     points[i]->location[0] = 0.2 * i;
    // }
    
    set_names(balls, 10, "ball-");
    set_names(points, 10, "point-");

    for(size_t i = 0; i < 10; i++)
    {
        std::cout << balls[i]->name << " " << points[i]->name << std::endl;
    }

    for (size_t i = 0; i < 10; i++) 
        delete balls[i];
    delete [] balls;

    for (size_t i = 0; i < 10; i++) 
        delete points[i];
    delete [] points;
    
    return 0;
}

