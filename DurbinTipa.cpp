#include  <fstream>
//#include "NumMethod.h"
#include "DurbinMethod.h"
#include <iostream>
#include "DurbinTipa.h"


void ReadCaps(std::fstream & fs, std::vector<std::complex<double>> & cap)
{
  std::string line, smth;
  while (std::getline(fs, line))
  {
    std::stringstream str(line);
    std::vector<double> complex_in_vector{};

    while (getline(str, smth, ' '))
    {
      complex_in_vector.push_back(std::stod(smth));
    }

    cap.emplace_back(complex_in_vector[0], complex_in_vector[1]);
  }
}

int main()
{
  std::vector<std::complex<double>> u_cap;
  std::vector<std::complex<double>> p_cap;

  std::fstream fs;
  fs.open("u_cap.txt", std::ios::in);
  ReadCaps(fs, u_cap);
  fs.close();

  fs.open("p_cap.txt", std::ios::in);
  ReadCaps(fs, p_cap);
  fs.close();


  double x = 3;
  double sigma = 5;
  int N = 20000;
  double T = 10;
  std::ofstream fin;
  fin.open("Result_Displacement.csv", std::ios::out);
  fin << "TimeStep" << ";" << "Displacement" << "\n"; 
  for (size_t t = 0; t <= 300; t+=1) {
      double f = f_N(t/10000., sigma, N, T, x, u_cap);
      fin << t/10000. << ";" << f << "\n"; 
  }
  fin.close();

  x = 0;
  fin.open("Result_Stress.csv", std::ios::out);
  fin << "TimeStep" << ";" << "Stress" << "\n"; 
  for (int t = 0; t <= 300; t+=1) {
      double f = f_N(t/10000., sigma, N, T, x, p_cap);
      fin << t/10000. << ";" << f << std::endl;
  }
  fin.close();

}