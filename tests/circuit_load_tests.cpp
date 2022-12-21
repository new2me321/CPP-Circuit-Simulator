#include "gtest/gtest.h"
#include "../src/Circuit/circuit_netlist.hpp"

TEST(NetlistTest, LoadAndSaveShouldYieldSameresult) {
  auto instructions = LoadCircuitInstructions("savefiles/resistors.net");

  std::string expectedNode = "vs";
  std::string expectedFunction = "v(vo)";

  SaveCircuitInstructions("build/resistors.net", instructions);

  auto instructions2 = LoadCircuitInstructions("build/resistors.net");
  // instructions2.components[0].pins[0] += 1;

  EXPECT_TRUE(instructions == instructions2);
}
