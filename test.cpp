// Copyright 2022
// By Dr. Rykalova
// Editted by Dr. Daly
// test.cpp for PS1a
// updated 1/8/2024

#include <iostream>
#include <string>

#include "FibLFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

using PhotoMagic::FibLFSR;

// Test to check if step works
BOOST_AUTO_TEST_CASE(testStepInstr) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
}

// Test to check if generate works
BOOST_AUTO_TEST_CASE(testGenerateInstr) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.generate(9), 51);
}

// Test to check if step returns a new bit correctly after 8 steps
BOOST_AUTO_TEST_CASE(testStepUpdatesSeed) {
    FibLFSR l("1011011000110110");
    std::ostringstream output;
    output.str("");
    output << l;
    BOOST_REQUIRE_EQUAL(output.str(), "1011011000110110");

    l.step();
    output.str("");
    output << l;
    BOOST_REQUIRE_EQUAL(output.str(), "0110110001101100");

    l.step();
    output.str("");
    output << l;
    BOOST_REQUIRE_EQUAL(output.str(), "1101100011011000");

    l.step();
    output.str("");
    output << l;
    BOOST_REQUIRE_EQUAL(output.str(), "1011000110110000");

    l.step();
    output.str("");
    output << l;
    BOOST_REQUIRE_EQUAL(output.str(), "0110001101100001");

    l.step();
    output.str("");
    output << l;
    BOOST_REQUIRE_EQUAL(output.str(), "1100011011000011");

    l.step();
    output.str("");
    output << l;
    BOOST_REQUIRE_EQUAL(output.str(), "1000110110000110");

    l.step();
    output.str("");
    output << l;
    BOOST_REQUIRE_EQUAL(output.str(), "0001101100001100");

    l.step();
    output.str("");
    output << l;
    BOOST_REQUIRE_EQUAL(output.str(), "0011011000011001");
}

// Test to check for invalid inputs in the constructor
BOOST_AUTO_TEST_CASE(testConstructorInvalidInput) {
  BOOST_REQUIRE_THROW(FibLFSR l("1011012000110110"), std::invalid_argument);
  BOOST_REQUIRE_THROW(FibLFSR l("-1011011000110110"), std::invalid_argument);
}

// Test to check for invalid parameter in generate
BOOST_AUTO_TEST_CASE(testGenerateInvalidInput) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_THROW(l.generate(-1), std::invalid_argument);
}

// Test to check insertion operator
BOOST_AUTO_TEST_CASE(testStream) {
  FibLFSR l("1011011000110110");
  std::ostringstream output;
  output << l;
  BOOST_REQUIRE_EQUAL(output.str(), "1011011000110110");
}
