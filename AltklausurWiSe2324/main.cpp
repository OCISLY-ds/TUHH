#include "task.hpp"
#include <iomanip> 
#include <iostream> 
#include <sstream> 
#include <string>
std::string to_string(unsigned int *data, int size) {
    if(data == nullptr) {
        return "nullptr";
    }
    std::stringstream result;
    for(int y = 0; y < size; ++y) {
        result << (y == 0 ? "" : ", ");
        result << std::setw(3) << std::setfill(' ') << data[y];
}
    return result.str();
}
std::string to_string(float *data, int size) {
    if(data == nullptr) {
        return "nullptr";
    }
    std::stringstream result;
    for(int y = 0; y < size; ++y) {
        result << (y == 0 ? "" : ", ");
        result << std::setw(3) << std::setfill(' ') << data[y];
      }
      return result.str();
  }
  std::string to_string(float **data, int size1, int size2) {
      if(data == nullptr) {
          return "    Übergebenes 2D-Feld ist nullptr. / Given 2D-array is nullptr.";
      }
      std::stringstream result;
      result << std::endl;
      for(int x = 0; x < size1; ++x) {
          float *row = data[x];
          if(row == nullptr) {
              result <<"    nullptr" <<std::endl;
              continue;
}
          result <<"    ";
          for(int y = 0; y < size2; ++y) {
              result << (y == 0 ? "" : ", ");
              result << std::setw(3) << std::setfill(' ') << data[x][y];
          }
          result <<std::endl;
      }
      return result.str();
  }
int main() {
      {
          std::cout <<"Führe get_maximum aus / Executing get_maximum" <<std::endl;
          int size= 4;
          float *data = new float[size]{-1.2, -2.0, -3.0, -4.5 };
          std::cout <<"  data: " <<to_string(data, size) <<std::endl;
          std::cout <<"  Erhalten / received: " <<get_maximum(data, size) <<std::endl;
          std::cout <<"  Erwartet / expected: -1.2" <<std::endl <<std::endl;
}
      {
          std::cout <<"Führe initialize_increase aus / Executing initialize_increase" <<std::endl;
          int size1= 4;
          int size2= 4;
          bool increase= true;
          float **data = new float * [size1] {
              new float [size2]  {  0,  50,  50, 108},
              new float [size2]  {  0,  51, 210, 109},
              new float [size2]  {  0,  52, 216, 110},
              new float [size2]  {  0,  25,  28, 111}
          };
          std::cout <<"  incease: " <<increase <<", data: " <<to_string(data, size1, size2) <<std::endl;
          initialize_increase(data, size1, size2, increase);
          float **xpct = new float * [size1] {
              new float [size2]  {  1,  2,  3,  4},
              new float [size2]  {  5,  6,  7,  8},
              new float [size2]  {  9, 10, 11, 12},
              new float [size2]  { 13, 14, 15, 16}
          };
          std::cout <<"  Erhalten / received: " <<to_string(data, 4, 4);
          std::cout <<"  Erwartet / expected: " <<to_string(xpct, 4, 4) <<std::endl;
}
      {
          std::cout <<"Führe invert aus / Executing invert" <<std::endl;
          int size1= 4;
          int size2= 4;
          float **data = new float * [size1] {
              new float [size2] {  1,  2,  3,  4},
              new float [size2] {  5,  6,  7,  8},
              new float [size2] {  9, 10, 11, 12},
              new float [size2] { 13, 14, 15, 16}
          };
          float **xpct = new float * [size1] {
              new float [size2] { -1, -2, -3, -4},
              new float [size2] { -5, -6, -7, -8},
              new float [size2] { -9,-10,-11,-12},
              new float [size2] {-13,-14,-15,-16}
          };
          std::cout <<"  data: " <<to_string(data, size1, size2) <<std::endl;
          invert(data, 4, 4);
          std::cout <<"  Erhalten / received: " <<to_string(data, 4, 4);
          std::cout <<"  Erwartet / expected: " <<to_string(xpct, 4, 4) <<std::endl;
}
      {
          std::cout <<"Führe count_pairs aus für / Executing count_pairs for";
          int size1= 4;
          int size2= 5;
          float **data = new float * [size1] {
              new float[size2] { 5, 8, 5, 9, 5},
              new float[size2] { 6, 5, 5, 5, 5},
              new float[size2] { 5, 5, 5, 1, 5},
              new float[size2] { 2, 4, 2, 1, 5}
          };
          std::cout <<to_string(data, size1, size2) <<std::endl;
          unsigned int xpct[size2] = { 0, 1, 2, 0, 3 };
          unsigned int numPairs[size2]= { 100, 100, 100, 100, 100 };
          count_pairs(data, size1, size2, numPairs);
          std::cout <<"  Erhalten / received: " <<to_string(numPairs, size2) <<std::endl;
          std::cout <<"  Erwartet / expected: " <<to_string(xpct, size2) <<std::endl <<std::endl;
}
      {
          std::cout <<"Führe down_sampling aus / Executing down_sampling" <<std::endl;
          int size= 11;
          int M= 3;
          float data[size] = { 1, 1, 1, 10, 2, 2, 2, 2, 4, 5, 6};
          float xpct[size/M] = { 2.85, 2.4, 3.8 };
          float *processed= down_sampling(data, size, M);
          std::cout <<"  Erhalten / received: " <<to_string(processed, size/M) <<std::endl;
          std::cout <<"  Erwartet / expected: " <<to_string(xpct, size/M) <<std::endl <<std::endl;
}
return 0; }
