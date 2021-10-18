// Vanessa Roque
// CPSC 120-19
// 2021-10-16
// vroque19@csu.fullerton.edu
// @vroque19
//
// Lab 06-01
//
// This calculates the area of a rectangle!
//

/// \file rectangle_area.cc
/// Command line program that computes the area of the rectangle.

#include <iostream>
#include <vector>

#include "rectangle_area_functions.h"

using namespace std;

/// Main function for the rectangle_area project.
int RectangleArea(int length, int width) {
  int area = 0;
  area = length * width;
  return area;
}
///
/// The program uses command line arguments. It requires at least two arguments
/// which each must be integers between 1 and 2147483647.
int main(int argc, char const* argv[]) {
  vector<string> args = vector<string>(argv, argv + argc);
  // Convert argv to a vector<string>. Name this variable args
  if (args.size() < 2) {
   cout << "Please provide two arguments, a rectangle's length and width.\n";
   cout << "For example:\n";
    try {
      cout << args.at(0) << " 23 17\n";
    } catch (out_of_range const& problem) {
      cout << "You went out of bounds. \n";
      cout << problem.what() << "\n";
      return 1;
    }
    return 1;
  }
  int input_length = 0;
  int input_width = 0;
  try {
    input_length = stoi(args.at(1));
    input_width = stoi(args.at(2));
  } catch(exception const& problem) {
    cout << "Problem converting the input numbers.\n";
    cout << problem.what() << "\n";
    return(1);
  }
  int area = 0;
  area = RectangleArea(input_length, input_width);
  cout << input_length << " x " << input_width << " = " << area << "\n";
  
  // Check to make sure there are enough arguments on the command line
  // for your program to continue. You need to have the length and width.
  // Look at the Example Output section of the README for the text of the
  // error message. Don't forget to use try and catch.
  // If there aren't enough arguments, return 1 (end the program).
  // Declare two int variables, input_length and input_width
  // Use stoi() and convert argument 1 and argument 2 from strings
  // to integers. Store arugment 1 in input_length and argument 2 in
  // input_width. Don't forget to use try and catch.
  // Declare an integer variable named area.
  // Calculate the area using RectangleArea(), assign the returned value
  // to the variable named area.
  // Print out a message reporting the results. Look at the Example Output
  // section of the README for tips on how to format the output.
  return 0;
}