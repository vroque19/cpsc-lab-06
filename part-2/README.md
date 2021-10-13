
# Checking If a Number is Prime

Did you write this program correctly? This is almost the same version of the project we did previously except we have defined unit tests to verify that the parts of our project work according to the specification.

The purpose of this exercise is to gain practice using the following elements:
* Writing our own command line parser (please refer to previous labs for examples)
* Using instructor provided [unit tests](https://en.wikipedia.org/wiki/Unit_testing).
* Defining functions
* Viewing inline documentation

This project is defined in 4 files:
* `is_it_prime.cc`
* `is_it_prime_functions.cc`
* `is_it_prime_functions.h`- Do not edit or change this file
* `is_it_prime_unittest.cc`- Do not edit or change this file.

Recall that our previous project the [Trial Division](https://en.wikipedia.org/wiki/Trial_division) algorithm was used. This algorithm, if implemented naïvely can be very slow. Our unit tests will determine if your implementation behaves correctly and if it runs fast enough.

The unit tests are already defined and ready to run. Make the neccessary changes to  `is_it_prime.cc` and `is_it_prime_functions.cc` using the code that you wrote in your previous exercises and run the unit tests with `make unittest`.

A passed test will look something like the following passage:

```
[ RUN      ] IsPrimeTest.Negative
[       OK ] IsPrimeTest.Negative (0 ms)
```

Should a unit test fail, then the output from `make unittest` will look something like the following example:

```
[ RUN      ] IsPrimeTest.Trivial
is_it_prime_unittest.cc:82: Failure
Value of: IsPrime(2)
  Actual: false
Expected: true
[  FAILED  ] IsPrimeTest.Trivial (1 ms)
```

On most terminals, the tests will appear in color. Tests that fail will be in red and tests that pass will be in green.

In the event that your code does not execute fast enough, one or more unit tests will fail. The failure will appear with a message explaining that the execution time was greater than some predefined value. For example, the excerpt below shows what a failed unit test may look like.

```
[ RUN      ] IsPrimeTest.Large
is_it_prime_unittest.cc:101: Failure
  Execution time greater than 125 milliseconds.
  Revise algorithm for better performance and check for infinite loops.
[  FAILED  ] IsPrimeTest.Large (125 ms)
```

Use the feedback from the unit tests to revise your code until all the of the tests pass.

At that point, you will still need to test the entire program for correctness. As a starting point you can use `make test` which will run some simple tests your instructor provides for you.

## Inline Documentation

Are you curious what the `Doxyfile` is for? Wonder what the difference is between the regular comments (`//`) and the weird comments (`///`)?

The triple slash comment (`///`) is used to create documentation using a documentation generator named [Doxygen](http://www.doxygen.nl). In the C++ community, Doxygen is a commonly used program to generate HTML and PDF documentation from a program's comments.

To try it out, use `make doc`. This will create a folder in the project's directory named `doc`. Inside of that directory are HTML files which you can view with your web browser.

Try the following commands to generate and view the documentation for this project:

```
$ make doc
(cat Doxyfile; echo "PROJECT_NAME = rectangle_area") | doxygen -
Notice: Output directory 'doc' does not exist. I have created it for you.
Searching for include files...
Searching for example files...
  # Many lines out output removed
Patching output file 1/2
Patching output file 2/2
lookup cache used 3/65536 hits=3 misses=3
finished...
$ gio open doc/html/index.html 
```

The last command `gio open doc/html/index.html` will open the main HTML file in your web browser.

Another benefit of documenting your code is that when you use an editor like Visual Studio Code, it can show you the documentation when you point your mouse's cursor at a function name.

## Requirements

Write a program that takes one integer as a command line argument and then calculates whether or not the number is prime. Print a message to the screen stating if the number is or is not a prime number. See the Example Output Section for more details.

You shall use [cout](https://en.cppreference.com/w/cpp/io/cout) to print messages to the terminal.

_Do not use_ [cin](https://en.cppreference.com/w/cpp/io/cin) to read in values from the keyboard. This program is not interactive and an interactive program will be marked with a zero score.

The program reads in one value from the command line (`argv`), stores them in a vector named `args`. Use the examples provided to process command line arguments.

Use the trial division algorithm along with your `IntegerSquareRoot()` function. Use of the function is mandatory.

Use `stoi()` only. Do not use `atoi()`.

The starting code defines a series of `TODO` comments which you can use to formulate your plan and develop your program.

Write your program progressively. Compile your program often and check that you're making progress. Make sure your program behaves the way you expect.

The output of your program must match the output given in the section Example Output below.

To compile your program, you use the `make` command. A Makefile is provided for this exercise.

The Makefile has the following targets:

* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* lint: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* header: check to make sure your files have the appropriate header
* test: run tests to help you verify your program is meeting the assignment's requirements. This does not grade your assignment.
* unittest: run unit tests to verify parts of your program performs according to the instructor supplied unit tests.

## Don't Forget

Please remember that:

- You need to put a header in every file.
- You need to follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
- Remove the `TODO` comments.

## Testing Your Code

Computers only ever do exactly what they are told, exactly the way they are told it, and never anything else. Testing is an important process to writing a program. You need to test for the program to behave correctly and test that the program behaves incorrectly in a predictable way.

As programmers we have to remember that there are a lot of ways that we can write the wrong program and only one to a few ways to write the correct program. We have to be aware of [cognitive biases](https://en.wikipedia.org/wiki/List_of_cognitive_biases) that we may exercise that lead us to believe we have correctly completed our program. That belief may be incorrect and our software may have errors. [Errors in software](https://www.wired.com/2005/11/historys-worst-software-bugs/) may lead to loss of [life](https://www.nytimes.com/2019/03/14/business/boeing-737-software-update.html), [property](https://en.wikipedia.org/wiki/Mariner_1), [reputation](https://en.wikipedia.org/wiki/Pentium_FDIV_bug), or [all of the above](https://en.wikipedia.org/wiki/2009%E2%80%9311_Toyota_vehicle_recalls).

### Test strategy

Start simple, and work your way up. Good tests are specific, cover a broad range of fundamentally different possibilities, can identify issues quickly, easily, and directly, without need for much set up, and can almost be diagnosed by inspection if the code fails to execute the test correctly.

## Example Output

Please ensure your program's output is identical to the example below.

```
$ make unittest
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 is_it_prime_functions.cc \
| sed 's/\(is_it_prime_functions\)\.o[ :]*/\1.o is_it_prime_functions.d : /g' > is_it_prime_functions.d; \
[ -s is_it_prime_functions.d ] || rm -f is_it_prime_functions.d
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 is_it_prime.cc \
| sed 's/\(is_it_prime\)\.o[ :]*/\1.o is_it_prime.d : /g' > is_it_prime.d; \
[ -s is_it_prime.d ] || rm -f is_it_prime.d
rm: cannot remove 'unittest': No such file or directory
make: [Makefile:135: cleanunittest] Error 1 (ignored)
clang++ -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 -c is_it_prime_functions.cc
Running main() from /build/googletest-j5yxiC/googletest-1.10.0/googletest/src/gtest_main.cc
[==========] Running 8 tests from 2 test suites.
[----------] Global test environment set-up.
[----------] 4 tests from IsPrimeTest
[ RUN      ] IsPrimeTest.Negative
[       OK ] IsPrimeTest.Negative (0 ms)
[ RUN      ] IsPrimeTest.Trivial
[       OK ] IsPrimeTest.Trivial (0 ms)
[ RUN      ] IsPrimeTest.Positive
[       OK ] IsPrimeTest.Positive (1 ms)
[ RUN      ] IsPrimeTest.Large
Testing 361201, 7901, 62425801, 2147483647
[       OK ] IsPrimeTest.Large (8 ms)
[----------] 4 tests from IsPrimeTest (9 ms total)

[----------] 4 tests from IntegerSquareRootTest
[ RUN      ] IntegerSquareRootTest.Negative
[       OK ] IntegerSquareRootTest.Negative (1 ms)
[ RUN      ] IntegerSquareRootTest.Trivial
[       OK ] IntegerSquareRootTest.Trivial (0 ms)
[ RUN      ] IntegerSquareRootTest.Positive
[       OK ] IntegerSquareRootTest.Positive (0 ms)
[ RUN      ] IntegerSquareRootTest.Large
Testing 361201, 7901, 62425801, 2147483647
[       OK ] IntegerSquareRootTest.Large (0 ms)
[----------] 4 tests from IntegerSquareRootTest (1 ms total)

[----------] Global test environment tear-down
[==========] 8 tests from 2 test suites ran. (10 ms total)
[  PASSED  ] 8 tests.
$ make
clang++ -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 -c is_it_prime.cc
clang++ -g -O3 -Wall -pipe -std=c++14 -o is_it_prime is_it_prime.o is_it_prime_functions.o 
$ ./is_it_prime 
Please provide a number to check.
For example:
./is_it_prime 2147483647
$ ./is_it_prime 2147483647
2147483647 is prime.
$ ./is_it_prime 0
0 is not prime.
```

