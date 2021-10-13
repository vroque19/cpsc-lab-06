
# Fitch Cheney's Five Card Trick Part 1

## Introduction

This exercise is part of a two part lab exercise. This is the first part where you shall develop the necessary parts needed to perform a magical mind reading card trick with the assistance of your computer.

The goal of this exercise is to develop and test most of the functions (units) needed in the following part of this lab. There is no main function in this exercise, however there is a small collection of functions that must be defined in `mind_reader_functions.cc`.

The lab has the following files:
* `mind_reader.cc` - Do not edit.
* `mind_reader_functions.cc`
* `mind_reader_functions.h` - Do not edit.
* `mind_reader_unittest.cc` - Do not edit.

The only file that you will be working with is `mind_reader_functions.cc`. Each function is documented inline and the documentation can be generated using `make doc`. (See Inline Documentation for more details.)

The function inputs and outputs are very similar to our Blackjack Calculator. Refer back to that lab exercise for inspiration on how to work with playing cards.

Using the feedback from the unit tests, develop and test the functions defined in `mind_reader_functions.cc`. When your code passes the unit tests, then you will be ready for the next lab where we put this code into use.

## The Card Trick

In this exercise, we shall write a program that will masquerade as a artificial intelligence. Imagine telling a friend or family member that in your introductory computer science class, you have learned how to write programs that can calculate what cards you have selected from a deck of cards. You may go on to explain that with a little more work, your computer program can predict what everyone was dealt in a poker game. For now, your program can predict the fifth card in a poker hand given the first four cards.

William Fitch Cheney, Jr. was a mathematics professor at Tufts University, University of Connecticut, and the University of Hartford in the middle third of the 20th century passing away in 1974. Other than being a professor, he was a published amateur magician. In the book _Math Miracles_ by Wallace Lee, a trick was published that is credited to Fitch Cheney. This trick uses discrete math, which is very important to a computer science student, to create an astounding effect.

The trick is performed with two magicians. In our case, one of the magicians will be our computer program. The trick can be performed with any deck of playing cards. The deck can be a borrowed deck and can be shuffled as many times as one would like. The trick requires no preparation, gimmicks, or gaffs. Five cards are randomly selected from the deck and given to the the human magician. The human magician then shows (inputs) four of the five cards to the computer magician. The computer magician reveals the unseen fifth card.

To get an idea of how a similar trick is performed, watch a performance of [Al Stanger's Miracle Poker Machine](https://youtu.be/Ef0zy6cXvkY) presented by [Andy Martin](https://www.martinsmagic.com/). There are many videos of the Five Card Trick presented by [two amateur magicians](https://youtu.be/8rfuV12dGjA) and [one magician with a computer](https://youtu.be/MRGTA9y72nA).

### Background

Let's first review some basic terminology. A deck of cards has four suits: clubs ♣️, diamonds ♦️, hearts ♥️, and spades ♠️. Each suit has 13 cards: Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King. Let's abbreviate Ace as _A_, Jack as _J_, Queen as _Q_, and King as _K_. Let's assume that Ace is the lowest value card, with a value of 0, and King is the highest value card, with a value of 12. (In computing, we like counting from zero rather than 1.) Let's abbreviate the suits as _C_ for clubs, _D_ for diamonds, _H_ for hearts, and _S_ for spades. Additionally, if there are two cards with the same value, then the suit will break the tie. The suits are valued in alphabetical order.

Here are some examples of abbreviations using the given schema:

* The 5 of diamonds is _5D_
* The Jack of hearts is _JH_
* The 2 of clubs is _2C_
* The 7 of clubs is less than the King of clubs, or _7C_ < _KC_
* The Ace of spades is greater than the Ace of diamonds, or _AS_ > _AD_

Typically, a deck of cards is ordered by suit and then by value. This means that all the clubs are together from Ace to King, all the diamonds are together from Ace to King, all the hearts are together from Ace to King, and all the spades are together from Ace to King. To facilitate the calculations in this trick, the sorting of the deck has to be changed. The trick requires that cards are ordered by value and then by suit. This means that the cards are ordered as _AC, AD, AH, AS, 1C, 1D, 1H, 1S, … , QC, QD, QH, QS, KC, KD, KH, KS_. (This detail should not be shared with the spectator.)

### Explanation

_To be revealed in the next part._

## Tips

When working with if-else-if-else conditions here are some tips to keep in mind:

* Always handle the exceptions first and leave the general case for the else statement
* Try to have one entry point and one exit for conditions and functions; use a variable such as `return_value` to hold on to the value you wish to return and then return the variable at the end of the function.
* Write comments in clear, plain english that explain to you what each case is supposed to do. This will help keep your code organized and help you fix any errors.

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
lookup cache used 2/65536 hits=2 misses=2
finished...
$ gio open doc/html/index.html 
```

The last command `gio open doc/html/index.html` will open the main HTML file in your web browser.

Another benefit of documenting your code is that when you use an editor like Visual Studio Code, it can show you the documentation when you point your mouse's cursor at a function name.

## Requirements

Using the inline documentation and any `TODO` comments, implement the functions in `mind_reader_functions.cc`.

Ensure that your code passes all unit tests. You can run the unit tests using the commadn `make unittest`.


Use the [`at()` method](https://en.cppreference.com/w/cpp/string/basic_string/at) of the [`std::string` class](https://en.cppreference.com/w/cpp/string/basic_string) to access the value and suit of the inputted card. (Do not use the `[]` operators!)

When using the `at()` method it will return a `char` type. Convert the `char` type to a `string` type. For example:

```
string hello = "Hello World";
// The first letter is at position 0
string letter_H = string(1, hello.at(0));
// The second letter is at position 1
string letter_e = string(1, hello.at(1));
// The letter d
// Get the size of the string, subtract 1 which will give the location of the last letter
string last_letter = string(1, hello.at(hello.size() - 1));
```

When using `at()` you should wrap each usage with a try/catch just like the try/catch pattern learned from the previous lab to catch errors.

```c++
string hello = "Hello World";
string letter_e;

try {
  letter_e = string(1, hello.at(1));
}catch (const exception& problem) {
  // Print a descriptive message about what went wrong or what you think went
  // wrong.
  cout << "Explain what happened.\n";
  // Use the exception to print addtional diagnostic messages.
  cout << problem.what() << "\n";
  // exit will end the program abruptly and return 1 to the operating system.
  exit(1);
}
```

Use the [`exit()`](https://en.cppreference.com/w/cpp/utility/program/exit) function to exit from your program if an error occurs in a function. Remember to `#include <cstdlib>` to take advantage of the `exit()` function.

If you need to, use  [`std::stoi()`](https://en.cppreference.com/w/cpp/string/basic_string/stol) to convert a string to an integer. Use the try/catch pattern learned from the previous lab to catch errors.

You shall use [cout](https://en.cppreference.com/w/cpp/io/cout) to print messages to the terminal.

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
$ make
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 mind_reader_functions.cc \
| sed 's/\(mind_reader_functions\)\.o[ :]*/\1.o mind_reader_functions.d : /g' > mind_reader_functions.d; \
[ -s mind_reader_functions.d ] || rm -f mind_reader_functions.d
set -e; clang++ -MM -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 mind_reader.cc \
| sed 's/\(mind_reader\)\.o[ :]*/\1.o mind_reader.d : /g' > mind_reader.d; \
[ -s mind_reader.d ] || rm -f mind_reader.d
clang++ -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 -c mind_reader.cc
clang++ -g -O3 -Wall -pipe -std=c++14 -D LINUX -D AMD64 -c mind_reader_functions.cc
clang++ -g -O3 -Wall -pipe -std=c++14 -o mind_reader mind_reader.o mind_reader_functions.o 
$ ./mind_reader 
The main function is empty and does nothing.
Run `make unittest` to check your work.
$ make unittest
rm: cannot remove 'unittest': No such file or directory
make: [Makefile:133: cleanunittest] Error 1 (ignored)
Running main() from /build/googletest-j5yxiC/googletest-1.10.0/googletest/src/gtest_main.cc
[==========] Running 16 tests from 7 test suites.
[----------] Global test environment set-up.
[----------] 4 tests from SuitTest
[ RUN      ] SuitTest.Clubs
[       OK ] SuitTest.Clubs (0 ms)
[ RUN      ] SuitTest.Diamonds
[       OK ] SuitTest.Diamonds (0 ms)
[ RUN      ] SuitTest.Hearts
[       OK ] SuitTest.Hearts (0 ms)
[ RUN      ] SuitTest.Spades
[       OK ] SuitTest.Spades (0 ms)
[----------] 4 tests from SuitTest (0 ms total)

[----------] 4 tests from FaceValueTest
[ RUN      ] FaceValueTest.Clubs
[       OK ] FaceValueTest.Clubs (0 ms)
[ RUN      ] FaceValueTest.Diamonds
[       OK ] FaceValueTest.Diamonds (0 ms)
[ RUN      ] FaceValueTest.Hearts
[       OK ] FaceValueTest.Hearts (0 ms)
[ RUN      ] FaceValueTest.Spades
[       OK ] FaceValueTest.Spades (0 ms)
[----------] 4 tests from FaceValueTest (0 ms total)

[----------] 1 test from NumericValueToFaceValue
[ RUN      ] NumericValueToFaceValue.Trivial
[       OK ] NumericValueToFaceValue.Trivial (0 ms)
[----------] 1 test from NumericValueToFaceValue (0 ms total)

[----------] 4 tests from DeckOrderValueTest
[ RUN      ] DeckOrderValueTest.Clubs
[       OK ] DeckOrderValueTest.Clubs (0 ms)
[ RUN      ] DeckOrderValueTest.Diamonds
[       OK ] DeckOrderValueTest.Diamonds (0 ms)
[ RUN      ] DeckOrderValueTest.Hearts
[       OK ] DeckOrderValueTest.Hearts (0 ms)
[ RUN      ] DeckOrderValueTest.Spades
[       OK ] DeckOrderValueTest.Spades (0 ms)
[----------] 4 tests from DeckOrderValueTest (0 ms total)

[----------] 1 test from SuitOffsetTest
[ RUN      ] SuitOffsetTest.Trivial
[       OK ] SuitOffsetTest.Trivial (0 ms)
[----------] 1 test from SuitOffsetTest (0 ms total)

[----------] 1 test from NumericValueTest
[ RUN      ] NumericValueTest.Trivial
[       OK ] NumericValueTest.Trivial (0 ms)
[----------] 1 test from NumericValueTest (0 ms total)

[----------] 1 test from FitchCheneySecretCardValueTest
[ RUN      ] FitchCheneySecretCardValueTest.Trivial
[       OK ] FitchCheneySecretCardValueTest.Trivial (0 ms)
[----------] 1 test from FitchCheneySecretCardValueTest (0 ms total)

[----------] Global test environment tear-down
[==========] 16 tests from 7 test suites ran. (0 ms total)
[  PASSED  ] 16 tests.
$ 
```

