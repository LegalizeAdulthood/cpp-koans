# C++ Koans

This repository exists as a set of C++ koans.  A [koan](https://en.wikipedia.org/wiki/K%C5%8Dan) in general terms is:

> a story, dialogue, question, or statement, which is used in Zen practice to provoke the "great doubt" and test
> a student's progress in Zen practice. [Wikipedia]

In programming terms, a koan is expressed as a series of programming questions written as failing unit test assertions.
You progress through the koan by modifying the code to make  the assertions pass.  By answering the questions it is
hoped that you achieve "enlightenment" about the feature in question.

# Organization

This repository is organized as a set of source files, each representing a particular area of study in koan form.
Each koan corresponds to a unit test executable described by the [CMake](http://www.cmake.org) build script.
There is an associated header file for each koan that contains just enough infrastructure to express the koans.
You can safely ignore this header file if you are only interested in consuming the koans as a student.  If you
are interested in writing new koans, you may find useful tricks inside those header files.

Current [list of koans](koans.md).

# Practicing the Koans

Each koan consists of a number of test cases.  Each test case consists of a number of related statements posed
as assertions.  Initially all the assertions fail.  To practice the koan, edit each assertion to make the
assertion true.  Typically each assertion will contain the symbol `XXX` or `xxx` representing the portion you
edit to make the assertion true.

A koan is designed to increase your understanding in some way; it is not a test.  Feel free to consult documentation,
leverage your IDE to research function signatures, etc., in order to figure out how to make an assertion pass.
Sometimes running the tests will tell you how the right answer compared to your incorrect answer.  Feel free to
copy/paste correct answers from the build output to pass the assertion!

The build script is configured to run the tests after a successful compile, so simply building the code will run
the tests and report failed assertions.

# First Time Setup

1. Obtain the [dependencies](#dependencies) and install them appropriately.
2. Generate a suitable project/build script with CMake.
3. Build the code to validate that your dependencies and build are correctly configured and working.  You should
   see the code being compiled and the unit test executables being run after compilation.

# Dependencies

- [CMake 3.8.0](http://www.cmake.org) for the build infrastructure.
- [Catch2](http://catch-lib.net) for the unit test framework.  Catch2 is included in the cpp-koans repository,
  so there is nothing to download.
  
# Contributing

New koans or improvements to existing koans are most welcome!  Simply fork and submit a pull request as usual on github.
