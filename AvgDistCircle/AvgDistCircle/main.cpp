#include <iostream>
#include <cmath>
#include <functional>

using ld = long double;

const ld PI = 3.14159265358979323846;
const ld epsilon = 0.001;
const ld epsilon_derivative = 0.00001;
const long long iteration = 100;

ld avg_dist_circle(double r)
{
    ld total = 0;
    for (ld theta_1 = 0; theta_1 <= 2 * PI; theta_1 += epsilon)
    {
        ld result = 0;
        for (ld theta_2 = 0; theta_2 <= 2 * PI; theta_2 += epsilon)
        {
            result += (sqrt((r * cos(theta_2) - r * cos(theta_1)) * (r * cos(theta_2) - r * cos(theta_1))
                        + (r * sin(theta_2) - r * sin(theta_1)) * (r * sin(theta_2) - r * sin(theta_1)))) * epsilon;
        }
        total += result * epsilon;
    }
    return total / (4 * PI * PI);
}

ld derivative(std::function<ld(ld)> u, ld at)
{
    return (u(at + epsilon_derivative) - u(at)) / epsilon_derivative;
}

ld newton_raphson(ld guess, std::function<ld(ld)> u, std::function<ld(ld)> u_prime)
{
    ld sol = guess;
    for (int i = 0;i < iteration;i++)
    {
        sol = sol - u(sol) / derivative(u, sol);
        std::cout << sol << std::endl;
    }
    return sol;
}

int main() {
    std::cout << std::endl << std::endl;
    std::cout << newton_raphson(0, [](ld x) { return 0.25*x + cos(x); }, [](ld x) { return 0.25 - sin(x); }) << std::endl;
}