## Vector Projection and Simple 2D Linear Regression

### Goal
Visual understanding of what "least squares" really means.
A best-fit line is simply a projection of data onto a 1-d
space.

### Concept
We model data as
$y = 2x + 1 + noise$
where the $noise$ simulates random measurement error.
The linear regression algorithm finds coefficients $a, b$ that
minimize
$MSE(a,b) = 1/n \sum_i(y_i-(a+bx_i))^2$

