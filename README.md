## Vector Projection and Simple 2D Linear Regression

### Goal
Visual understanding of what "least squares" really means.
A best-fit line is simply a projection of data onto a 1-d
space.

### Concept
We model data as
$
y = 2x + 1 + noise
$

where the $noise$ simulates random measurement error.
The linear regression algorithm finds coefficients $a, b$ that
minimize
$
MSE(a,b) = \frac{1}{n} \sum_i(y_i-(a+bx_i))^2
$

The analytical solution for the parameters is given by:

$$
b = \frac{\sum (x_i - \bar{x})(y_i - \bar{y})}{\sum (x_i - \bar{x})^2}, \qquad
a = \bar{y} - b\bar{x}
$$

##Implementation
- **Language:** C++17
- **Data generation:** Gaussian noise using `std::normal_distribution<double>`
- **Outputs:** Automatically writes generated points to `points.csv`
- **Visualization:** Python script automatically runs the C++ program, reads the data, and plots the regression line.  


## How to Run
Simply execute the Python script — it will:
1. Compile and run the C++ code.
2. Generate the synthetic dataset with noise.
3. Read the `points.csv` file.
4. Plot the data points and best-fit line.
