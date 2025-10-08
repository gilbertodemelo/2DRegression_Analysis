/**
 * Vector Projection and Simples 2D
 * Linear Regression
 *
 *
 */

#include <iostream>
#include <random>
#include <vector>


struct Point {
    double x;
    double y;
};

// prototypes
double averageX(std::vector<Point> &);
double averageY(std::vector<Point> &);
double b(std::vector<Point> &);
double a(std::vector<Point> &);



int main() {

    std::random_device rd;  // seeds the generator with real entropy
    std::mt19937 gen(rd()); // Mersenne Twister engine

    // Creates the normal distribution
    std::normal_distribution<double> noise(0.0, 1.0);

    // create vector of points
    std::vector<Point> vec(10000);

    for (int i = 0; i < vec.size(); i++) {
        vec[i].x = i / 2.0;
        vec[i].y = 2 * vec[i].x + 1 + noise(gen);
        //std::cout << vec[i].x << ", " << vec[i].y << std::endl;
    }

    std::cout << "Average X: " << averageX(vec) << std::endl;
    std::cout << "Average Y: " << averageY(vec) << std::endl;
    std::cout << "b: " << b(vec) << std::endl;
    std::cout << "a: " << a(vec) << std::endl;

    return 0;

}




double averageX(std::vector<Point> &vec) {
    double sum = 0;

    for (auto &i : vec) {
        sum += i.x;
    }

    return sum / (double) vec.size();
}

double averageY(std::vector<Point> &vec) {

    double sum = 0.0;
    for (auto &i : vec) {
        sum += i.y;
    }

    return sum / (double) vec.size();
}

double b(std::vector<Point> &vec) {

    double avgX = averageX(vec);
    double avgY = averageY(vec);
    double num = 0.0;
    double denominator = 0.0;

    for (auto & i : vec) {
        double dx = i.x - avgX;
        double dy = i.y - avgY;
        num += dx * dy;
        denominator += dx * dx;
    }

    if (denominator == 0.0) {
        std::cerr << "Warning: zero variance in x, slope undefined.\n";
        return 0.0;
    }

    return num / denominator;
}

double a(std::vector<Point> &vec) {
    double _b = b(vec);
    double avgY = averageY(vec);
    double avgX = averageX(vec);

    return avgY - (_b * avgX);
}


