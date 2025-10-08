#include <iostream>
#include <random>
#include <vector>


struct Point {
    double x;
    double y;
};

// prototypes
double averageX(std::vector<Point> *);
double averageY(std::vector<Point> *);
double b(std::vector<Point>);
double a(std::vector<Point>);



int main() {

    // create vector of points
    std::vector<Point> vec;

}



double averageX(std::vector<Point> &vec) {
    double avgX = 0.0;
    double sum = 0;
    for (auto & i : vec) {
        sum += i.x;
    }
    return avgX;
}
