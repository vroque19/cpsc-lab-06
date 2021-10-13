
/* Do not edit below this line. */
/* Do not edit below this line. */
/* Do not edit below this line. */

#include <gtest/gtest.h>
#include <limits.h>

#include <cstdio>
#include <future>

#include "is_it_prime_functions.h"

// Thanks to Paul Inventado
// https://github.com/google/googletest/issues/348#issuecomment-431714269
// Fail immediately.
#define ASSERT_DURATION_LE(millisecs, stmt)                                 \
  {                                                                         \
    std::promise<bool> completed;                                           \
    auto stmt_future = completed.get_future();                              \
    std::thread(                                                            \
        [&](std::promise<bool>& completed) {                                \
          stmt;                                                             \
          completed.set_value(true);                                        \
        },                                                                  \
        std::ref(completed))                                                \
        .detach();                                                          \
    if (stmt_future.wait_for(std::chrono::milliseconds(millisecs)) ==       \
        std::future_status::timeout)                                        \
      GTEST_FATAL_FAILURE_("\tExecution time greater than " #millisecs      \
                           " milliseconds.\n\tRevise algorithm for better " \
                           "performance and check for "                     \
                           "infinite loops.");                              \
  }

// Defer failure
#define EXPECT_DURATION_LE(millisecs, stmt)                                    \
  {                                                                            \
    std::promise<bool> completed;                                              \
    auto stmt_future = completed.get_future();                                 \
    std::thread(                                                               \
        [&](std::promise<bool>& completed) {                                   \
          stmt;                                                                \
          completed.set_value(true);                                           \
        },                                                                     \
        std::ref(completed))                                                   \
        .detach();                                                             \
    if (stmt_future.wait_for(std::chrono::milliseconds(millisecs)) ==          \
        std::future_status::timeout)                                           \
      GTEST_NONFATAL_FAILURE_("\tExecution time greater than " #millisecs      \
                              " milliseconds.\n\tRevise algorithm for better " \
                              "performance and check for "                     \
                              "infinite loops.");                              \
  }

namespace {

// Tests IsPrime()

// Tests negative input.
TEST(IsPrimeTest, Negative) {
  // This test belongs to the IsPrimeTest test case.
  EXPECT_DURATION_LE(125, EXPECT_FALSE(IsPrime(-1)));
  EXPECT_DURATION_LE(125, EXPECT_FALSE(IsPrime(-2)));
  EXPECT_DURATION_LE(125, EXPECT_FALSE(IsPrime(INT_MIN)));
}

// Tests some trivial cases.
TEST(IsPrimeTest, Trivial) {
  EXPECT_DURATION_LE(125, EXPECT_FALSE(IsPrime(0)));
  EXPECT_DURATION_LE(125, EXPECT_FALSE(IsPrime(1)));
  EXPECT_DURATION_LE(125, EXPECT_TRUE(IsPrime(2)));
  EXPECT_DURATION_LE(125, EXPECT_TRUE(IsPrime(3)));
}

// Tests positive input.
TEST(IsPrimeTest, Positive) {
  EXPECT_DURATION_LE(125, EXPECT_FALSE(IsPrime(4)));
  EXPECT_DURATION_LE(125, EXPECT_FALSE(IsPrime(6)));
  EXPECT_DURATION_LE(125, EXPECT_TRUE(IsPrime(23)));
  EXPECT_DURATION_LE(125, EXPECT_FALSE(IsPrime(64)));
  EXPECT_DURATION_LE(125, EXPECT_TRUE(IsPrime(601)));
}

// Tests large input for speed.
TEST(IsPrimeTest, Large) {
  std::cout << "Testing 361201, 7901, 62425801, " << INT_MAX << "\n";
  EXPECT_DURATION_LE(125, EXPECT_FALSE(IsPrime(361201)));
  EXPECT_DURATION_LE(125, EXPECT_TRUE(IsPrime(7901)));
  EXPECT_DURATION_LE(125, EXPECT_FALSE(IsPrime(62425801)));
  EXPECT_DURATION_LE(125, EXPECT_TRUE(IsPrime(INT_MAX)));
}

// Tests IntegerSquareRootTest()

// Test negative input
TEST(IntegerSquareRootTest, Negative) {
  EXPECT_DURATION_LE(125, EXPECT_EQ(-1, IntegerSquareRoot(-1)));
  EXPECT_DURATION_LE(125, EXPECT_EQ(-1, IntegerSquareRoot(-5)));
  EXPECT_DURATION_LE(125, EXPECT_EQ(-1, IntegerSquareRoot(-4)));
}

// Test trivial input
TEST(IntegerSquareRootTest, Trivial) {
  EXPECT_DURATION_LE(125, EXPECT_EQ(1, IntegerSquareRoot(1)));
  EXPECT_DURATION_LE(125, EXPECT_EQ(0, IntegerSquareRoot(0)));
  EXPECT_DURATION_LE(125, EXPECT_EQ(1, IntegerSquareRoot(2)));
}

// Test positive numbers
TEST(IntegerSquareRootTest, Positive) {
  EXPECT_DURATION_LE(125, EXPECT_EQ(10, IntegerSquareRoot(100)));
  EXPECT_DURATION_LE(125, EXPECT_EQ(4, IntegerSquareRoot(23)));
  EXPECT_DURATION_LE(125, EXPECT_EQ(10, IntegerSquareRoot(101)));
}

// Test large numbers
TEST(IntegerSquareRootTest, Large) {
  std::cout << "Testing 361201, 7901, 62425801, " << INT_MAX << "\n";
  EXPECT_DURATION_LE(125, EXPECT_EQ(601, IntegerSquareRoot(361201)));
  EXPECT_DURATION_LE(125, EXPECT_EQ(88, IntegerSquareRoot(7901)));
  EXPECT_DURATION_LE(125, EXPECT_EQ(7901, IntegerSquareRoot(62425801)));
  EXPECT_DURATION_LE(125, EXPECT_EQ(46340, IntegerSquareRoot(INT_MAX)));
}

}  // namespace
