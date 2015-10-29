//cmps335 exam 1 framework
//Write a unit test to check the validity of the milesToKm function. 
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stdio.h>
using namespace std;



double milesToKm(double miles);
bool almostEqualRelative(double A, double B, double maxRelDiff);

int main(int argc, char *argv[])
{
  double miles = 1.0;
  double inputNum = atof(argv[1]);
  double tolerance = atof(argv[2]);
  double kilo;
  
  bool isEqual;
  
  int count;
  int badcount = 0;
  
  float Values[200] = { 0.070595, 0.127778, 0.193219, 0.256047, 0.320338,
    0.377179, 0.437968, 0.502869, 0.566453, 0.627338, 0.687828, 0.750056,
    0.812044, 0.872742, 0.939051, 0.999317, 1.057795, 1.122426, 1.184569,
    1.245477, 1.306479, 1.370552, 1.431963, 1.500516, 1.562474, 1.622408,
    1.679902, 1.747587, 1.808442, 1.868826, 1.931736, 1.993311, 2.058741,
    2.114956, 2.177221, 2.244804, 2.305723, 2.366640, 2.426989, 2.489355,
    2.549020, 2.617720, 2.680177, 2.739693, 2.796955, 2.863584, 2.921229,
    2.984832, 3.053955, 3.111606, 3.173981, 3.231968, 3.301554, 3.363203,
    3.417607, 3.487014, 3.546460, 3.606221, 3.671176, 3.729340, 3.797348,
    3.853076, 3.920678, 3.981979, 4.041785, 4.109515, 4.166262, 4.234851,
    4.291360, 4.356319, 4.415136, 4.479174, 4.540696, 4.599834, 4.661250,
    4.727898, 4.791527, 4.848451, 4.916565, 4.977180, 5.039618, 5.097969,
    5.164436, 5.224322, 5.282185, 5.350919, 5.408075, 5.473248, 5.539605,
    5.599579, 5.660778, 5.723007, 5.786572, 5.843236, 5.904629, 5.965863,
    6.028120, 6.094124, 6.151809, 6.218438, 6.277264, 6.341629, 6.400159,
    6.468370, 6.529736, 6.587545, 6.650267, 6.713125, 6.775721, 6.844419,
    6.905757, 6.968653, 7.023566, 7.089232, 7.149879, 7.210517, 7.272780,
    7.338446, 7.402120, 7.458603, 7.522106, 7.584842, 7.651417, 7.706348,
    7.773612, 7.829443, 7.893471, 7.960854, 8.020551, 8.080128, 8.142003,
    8.208389, 8.270194, 8.328461, 8.390922, 8.451956, 8.515895, 8.578941,
    8.640696, 8.705094, 8.764701, 8.825657, 8.890815, 8.953197, 9.017682,
    9.081349, 9.142233, 9.196844, 9.264040, 9.326461, 9.385418, 9.453980,
    9.507000, 9.570395, 9.631752, 9.699898, 9.756987, 9.820235, 9.883626,
    9.948276, 10.008963, 10.072093, 10.130992, 10.191348, 10.260607, 10.319830,
    10.379083, 10.440144, 10.510276, 10.569147, 10.632470, 10.690071, 10.757761,
    10.814104, 10.881951, 10.941990, 10.999862, 11.066456, 11.128969, 11.191900,
    11.248778, 11.318111, 11.377467, 11.435228, 11.495819, 11.564395, 11.628164,
    11.683708, 11.753395, 11.808419, 11.876475, 11.934712, 12.000728, 12.055547,
    12.122003, 12.185142, 12.247047, 12.310618, 12.372681, 12.432581 };
    
    
    
  if (inputNum > 1){ //Regular functionality
      
    if (argc > 1) {
      miles = inputNum;

      cout << miles << " miles = ";
      cout << milesToKm(miles) << " Km" << endl;
      cout << endl;
      return 0;
    }
  }
    
  if (inputNum < 0) { //Unit test functionality if input is < 1
      
    cout << "Unit test of milesToKm() function..." << endl << endl;
    cout << "       Miles   Function" << endl;
    cout << "       -----   --------" << endl;
      
    for(int i = 0; i < 200; i ++) {
      count = i + 1;
      miles = (count * .1);
      kilo = milesToKm(miles);
      isEqual = almostEqualRelative(Values[i], kilo, tolerance);

      if (isEqual) { //if within tolerance, print
        printf ("%3i    %4.1f    %f\n", count, miles, kilo);
      }
      else { //if not within tolerance, print bad value and increment our bad count     
        printf ("%3i    %4.1f    %f  <--- bad value\n", count, miles, kilo);
        badcount += 1;
      } 
    }
      
    cout << "bad element count: " << badcount << endl;
    cout << "unit test complete." << endl;
      
    return 0;
  }
}

bool almostEqualRelative(double A, double B, double maxRelDiff)
{
  double diff = fabs(A - B);  //find the absolute value of the difference of two numbers
  A = fabs(A);
  B = fabs(B);
  
  if (diff <= maxRelDiff){  //compare to our tolerance
    return true;
  }
  return false;
}

double milesToKm(double miles)
{
  return (miles * 0.62137);
}

