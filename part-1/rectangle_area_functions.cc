// Vanessa Roque
// CPSC 120-19
// 2021-10-18
// vroque19@csu.fullerton.edu
// @vroque19
//
// Lab-06-01
//
// This function claculates the area of a triangle

/// \file functions.cc
/// Function definitions used in this project

/// Calculate the area of a triangle defined by \p length and \p width.
///
/// The area of a triangle is the product of the \p length and \p width.
///
/// Although rectangles with negative length and width exist, this program
/// is meant to be used to calculate the positive area of rectangles one
/// could encounter in the physical world.
///
/// Because of this requirement, \p length and \p width must be positive
/// integers. Values less than 1 mean that the rectangle has 0 area.
///
/// Typical usage:
/// \code
///   int input_length = 13;
///   int input_width = 17;
///   int area = RectangleArea(input_length, input_width);
/// \endcode
///
/// \param length the length of the rectangle
/// \param width the width the rectangle
/// \returns the area of the rectangle defined by \p length and \p width

int RectangleArea(int length, int width) {
  int area = 0;
  area = length * width;
  // TODO: Implement this function given the explanation given above.
  return area;
}
