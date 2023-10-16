#include <iostream>
#include <vector>

// struct ComplexVector {
//   std::vector<double> realPart;
//   std::vector<double> imaginaryPart;
// };

struct CComplexVector{
  int size;
  double *realPart;
  double *imaginaryPart;
};

// int linear_combination(ComplexVector x, ComplexVector y, double a){
//   int sizeVector;
//   ComplexVector z;
//   sizeVector = (int)x.realPart.size();
//   z.realPart.resize(sizeVector);
//   z.imaginaryPart.resize(sizeVector);

//   // Add real part
//   for(int i = 0; i < sizeVector; i++){
//     z.realPart[i] = x.realPart[i] + a * y.realPart[i];
//   }

//   // Add imaginary part
//   for(int i = 0; i < sizeVector; i++){
//     z.imaginaryPart[i] = x.imaginaryPart[i] + a * y.imaginaryPart[i];
//   }

//   for (int i = 0; i < z.imaginaryPart.size(); ++i){
//     std::cout << z.realPart[i] << " " << z.imaginaryPart[i] << std::endl;
//   }
//   std::cout << std::endl;

//   return 0;
// }

int clinear_combination(CComplexVector x, CComplexVector y, double a){
  CComplexVector z;
  z.size = x.size;

  // Add real part
  for(int i = 0; i < z.size; i++){
    z.realPart[i] = x.realPart[i] + a * y.realPart[i];
  }

  // Add imaginary part
  for(int i = 0; i < z.size; i++){
    z.imaginaryPart[i] = x.imaginaryPart[i] + a * y.imaginaryPart[i];
  }

  for (int i = 0; i < z.size; ++i){
    std::cout << z.realPart[i];
    if(z.imaginaryPart[i] >= 0){
      std::cout << "+";
    } 
    std::cout << z.imaginaryPart[i] << "i" << std::endl;
  }
  std::cout << std::endl;

  return 0;
}


int main(){
  // double a;
  // ComplexVector x, y;
  // a = 2;

  // x.realPart.push_back(1);
  // x.realPart.push_back(1);
  // y.realPart.push_back(3);
  // y.realPart.push_back(5);

  // x.imaginaryPart.push_back(1);
  // x.imaginaryPart.push_back(-1);
  // y.imaginaryPart.push_back(2);
  // y.imaginaryPart.push_back(-3);

  // linear_combination(x, y, a);

  double ca;
  CComplexVector cx, cy;

  ca = 2;

  cx.size = 2;
  cx.realPart = (double*) malloc(cx.size * sizeof(int));
  cx.realPart[0] = 1;
  cx.realPart[1] = 1;
  cx.imaginaryPart = (double*) malloc(cx.size * sizeof(int));
  cx.imaginaryPart[0] = 1;
  cx.imaginaryPart[1] = -1;

  cy.size = 2;
  cy.realPart = (double*) malloc(cy.size * sizeof(int));
  cy.realPart[0] = 3;
  cy.realPart[1] = 5;
  cy.imaginaryPart = (double*) malloc(cy.size * sizeof(int));
  cy.imaginaryPart[0] = 2;
  cy.imaginaryPart[1] = -3;

  clinear_combination(cx, cy, ca);
  
  free(cx.realPart);
  free(cx.imaginaryPart);
  free(cy.realPart);
  free(cy.imaginaryPart);

  return 0;
}