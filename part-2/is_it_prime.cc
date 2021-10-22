
/// \file is_it_prime.cc
/// Command line program that verifies if the given number is prime or not.

#include <iostream>
#include <vector>

#include "is_it_prime_functions.h"

using namespace std;

/// Main function for the is_it_prime project.
///
/// The program uses command line arguments. It requires at least one argument
/// which must be a postive integer between 1 and 2147483647.
int main(int argc, char const* argv[]) {
  vector<string> args = vector<string>(argv, argv + argc);
  if(args.size() < 2) {
    cout << "Please provide two arguments.\n";
    cout << "For example:\n";
      try {
        cout << args.at(0) << " 2147483647\n";
      } catch (out_of_range const& problem) {
      cout << "You went out of  bounds.\n";
      cout << problem.what() << "\n";
      return 1;
      }
    return 1;
  }
  int input_number = 0;
  try {
    input_number = stoi(args.at(1));
  } catch(exception const& problem) {
    cout << "Problem converting the input numbers.\n";
    cout << problem.what() << "\n";
    return(1);
  }
  // Convert argv to a vector<string>. Name this variable args
  // Check to make sure there are enough arguments on the command line
  // for your program to continue. You need to have the length and width.
  // Look at the Example Output section of the README for the text of the
  // error message. Don't forget to use try and catch.
  // If there aren't enough arguments, return 1 (end the program).
  // Declare an int variables, input_number
  // Use stoi() and convert argument 1 from a string
  // to an integer. Store arugment 1 in input_number. Don't forget to use try
  // and catch.
  // TODO: If input_number is prime, print the message that the input
  // number is prime. Else, print the message that the input number is not
  // prime. Look at the Example Output section of the README for the text of the
  // message.
  return 0;
}