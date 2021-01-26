#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <time.h>

using namespace std;

// Definition of class Point
class Point {
public:
    Point(double xcoord = 0.0, double ycoord = 0.0);
    virtual ~Point() = default;
    virtual void input(const char* prompt);
    virtual void output() const;
    virtual double area() const;
    void move(double deltax, double deltay);
private:
    double x;
    double y;
};

// Definition of class Circle
class Circle : public Point {
public:
    Circle(double xcoord = 0.0, double ycoord = 0.0, double radius0 = 0.0);
    virtual void input(const char* prompt) override;
    virtual void output() const override;
    virtual double area() const override;
private:
    double radius;
};

// Definition of class Square
class Square : public Point {
public:
    Square(double xcoord = 0.0, double ycoord = 0.0, double width0 = 0.0, double height0 = 0.0);
    virtual void input(const char* prompt) override;
    virtual void output() const override;
    virtual double area() const override;
private:
    double width;
    double height;
};

shared_ptr<Point> genFigure();

// TODO MAIN
int main()
{
    /* Exercise A */
    // Put the defined object pointers to vector
    vector<shared_ptr<Point>> figVector;
    figVector.push_back(make_shared<Point>(1.0, 1.0));
    figVector.push_back(make_shared<Circle>(2.0, 2.0, 2.0));
    figVector.push_back(make_shared<Square>(5.0, 5.0, 2.0, 2.0));

    // Put user-defined object pointers to vector
    Point userPoint;
    userPoint.input("Point:");
    figVector.push_back(make_shared<Point>(userPoint));

    Circle userCircle;
    userCircle.input("Circle:");
    figVector.push_back(make_shared<Circle>(userCircle));

    Square userSqure;
    userSqure.input("Square:");
    figVector.push_back(make_shared<Square>(userSqure));

    // Print the object data
    cout << "\nVector populated. Printing the values...\n\n";
    for (auto element : figVector) {
        element->output();
        cout << endl;
    }

    // Sort elements by area
    sort(figVector.begin(), figVector.end(), [](shared_ptr<Point> first, shared_ptr<Point> second) -> bool
        {
            return first->area() < second->area();
        });

    // Print the object data
    cout << "\nVector sorted. Printing the values...\n\n";
    for (auto element : figVector) {
        element->output();
        cout << endl;
    }

    /* Exercise B */
    figVector.clear();

    // Generate random objects
    cout << endl << "Random object generation. Enter the values:" << endl;
    for (int i = 0; i < 5; i++) {
        figVector.push_back(genFigure());
    }

    // Print random objects
    cout << "\nVector populated. Printing the values...\n\n";
    for (auto element : figVector) {
        element->output();
        cout << endl;
    }

    return 0;
}

shared_ptr<Point> genFigure()
{
    srand(time(NULL)); // Set random seed
    int obj = rand() % 3;

    if (obj == 0) {
        Point point;
        point.input("Point:");
        return make_shared<Point>(point);

    }
    else if (obj == 1) {
        Circle circle;
        circle.input("Circle:");
        return make_shared<Circle>(circle);
    }
    else {
        Square square;
        square.input("Square:");
        return make_shared<Square>(square);
    }
}

/* Class Point methods implementation */
// Constructor
Point::Point(double xcoord, double ycoord) :
    x(xcoord), y(ycoord) { }

void Point::input(const char* prompt)
{
    cout << prompt << endl;
    
    cout << "Enter x: ";
    cin >> x;

    cout << "Enter y: ";
    cin >> y;
}
 
void Point::output() const
{
    cout << "Coordinates: (" << x << "," << y << ")";
}

double Point::area() const
{
    return 0.0;
}

void Point::move(double deltax, double deltay)
{
    x += deltax;
    y += deltay;
}

/* Class Circle methods implementation */
// Constructor
Circle::Circle(double xcoord, double ycoord, double radius0) :
    Point(xcoord, ycoord), radius(radius0) { }

void Circle::input(const char* prompt)
{
    Point::input(prompt);
    
    cout << "Enter radius: ";
    cin >> radius;
}

void Circle::output() const
{
    cout << "Circle's area: " << area() << " "; Point::output();
}

double Circle::area() const
{
    return M_PI * pow(radius, 2);
}

/* Class Square methods implementation */
// Constructor
Square::Square(double xcoord, double ycoord, double width0, double height0) :
    Point(xcoord, ycoord), width(width0), height(height0) { }

void Square::input(const char* prompt)
{
    Point::input(prompt);
    
    cout << "Enter width: ";
    cin >> width;

    cout << "Enter height: ";
    cin >> height;
}

void Square::output() const
{
    cout << "Square's area: " << area() << " "; Point::output();
}

double Square::area() const
{
    return width * height;
}