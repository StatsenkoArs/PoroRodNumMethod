#include "DurbinMethod.h"


double Real_Part_Func(const double &t, const double &sigma, int N, const double &T, const double &x, std::vector<std::complex<double>> val) {
    double answer = 0;
    for (int k = 1; k <= N; ++k) {
        answer += val[k - 1].real() * std::cos(k * t * PI / T);
    }
    return answer;
}

double Img_Part_Func(const double &t, const double &sigma, int N,const double &T, const double &x, std::vector<std::complex<double>> val) { 
    double answer = 0;
    for (int k = 1; k <= N; ++k) {
        answer += val[k - 1].imag() * std::sin(k * t * PI / T);
    }
    return answer;
}

double f_N(const double &t, const double &sigma, int N, const double &T, const double &x, std::vector<std::complex<double>> val) {
    return (std::exp(sigma * t)/T) * (0.5 * val[0].real() + Real_Part_Func(t, sigma, N, T, x, val) - Img_Part_Func(t, sigma, N, T, x, val));
}