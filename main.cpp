/**
 * Vector Projection and Simples 2D
 * Linear Regression
 *
 *
 */

#include <iostream>
#include <random>
#include <vector>
#include <fstream>


struct Point {
    double x;
    double y;
};

// prototypes
double averageX(std::vector<Point> &);
double averageY(std::vector<Point> &);
double b(std::vector<Point> &);
double a(std::vector<Point> &);
double mse(std::vector<Point> &, double, double);
double r2(std::vector<Point> &, double, double);




int main() {

    std::random_device rd;  // seeds the generator with real entropy
    std::mt19937 gen(rd()); // Mersenne Twister engine

    // Creates the normal distribution
    std::normal_distribution<double> noise(0.0, 10.0);

    // create vector of points
    std::vector<Point> vec(10000);

    // write results into a file
    std::fstream outfile;
    outfile.open("points.csv", std::ios::out);

    // headers of the file
    outfile << "x,y" << std::endl;

    for (int i = 0; i < vec.size(); i++) {
        vec[i].x = i / 2.0 + noise(gen) + 0.3;
        vec[i].y = 2 * vec[i].x + 1 + noise(gen);
        //std::cout << vec[i].x << ", " << vec[i].y << std::endl;
        outfile << vec[i].x << "," << vec[i].y <<  std::endl;
    }

    outfile.close();

    double _a = a(vec);
    double _b = b(vec);

    std::cout << _a << " " << _b << " "
              << mse(vec, _a, _b) << " "
              << r2(vec, _a, _b) << std::endl;


    return 0;

}

double r2(std::vector<Point> &vec, double a, double b) {
    double avgY = averageY(vec);

    double ss_tot = 0.0;
    double ss_res = 0.0;
    for (auto &i : vec) {
        double y_pred = a + b * i.x;
        ss_res += (i.y - y_pred) * (i.y - y_pred);
        ss_tot += (i.y - avgY) * (i.y - avgY);
    }

    return 1 - (ss_res / ss_tot);
}

double mse(std::vector<Point> &vec, double a, double b) {

    double res = 0.0;

    for(int i = 0; i < vec.size(); i++) {
        double y_i = vec[i].y;
        double x_i = vec[i].x;
        res += (y_i - (a + (b * x_i))) * (y_i - (a + (b * x_i)));
    }

    return res/ (double) vec.size();

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


