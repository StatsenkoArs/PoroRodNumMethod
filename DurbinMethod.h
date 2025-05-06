#pragma once

#include <vector>
#include <complex>
#include <cmath>

#define PI 3.14159265358979311600


double Real_Part_Func(const double &t, const double &sigma, int N, const double &T, const double &x, std::vector<std::complex<double>> val);

double Img_Part_Func(const double &t, const double &sigma, int N, const double &T, const double &x, std::vector<std::complex<double>> val);

double f_N(const double &t, const double &sigma, int N, const double &T, const double &x, std::vector<std::complex<double>> val);