#include "gtest/gtest.h"
#include "../src/Circuit/circuit_netlist.hpp"

TEST(NetlistTest, LoadBasicFile_CorrectComponentCount) {
  auto instructions = LoadCircuitInstructions(SAVEFILES_PATH "/basiccircuit.net");

  const int expected = 3;

  EXPECT_EQ(expected, instructions.components.size());
}

TEST(NetlistTest, LoadBasicFile_AllComponentsExist) {
  auto instructions = LoadCircuitInstructions(SAVEFILES_PATH "basiccircuit.net");

  auto expected = {"V1", "R2", "R3"};

  bool allExist = std::all_of(
    expected.begin(),
    expected.end(),
    [&](auto exp){
      return instructions.components.count(exp);
    }
  );

  EXPECT_TRUE(allExist);
}

TEST(NetlistTest, LoadBasicFile_CorrectNodes) {
  auto instructions = LoadCircuitInstructions(SAVEFILES_PATH "basiccircuit.net");

  auto expectedNodesV1 = {"1", "0"};

  EXPECT_TRUE(instructions.components[std::string("V1")].pins.size() == 2);

  bool allV1NodesExist = std::all_of(
    expectedNodesV1.begin(),
    expectedNodesV1.end(),
    [&](auto exp){
      return 
        (instructions.components[std::string("V1")].pins[0]  == exp ||
         instructions.components[std::string("V1")].pins[1] == exp);
    }
  );

  EXPECT_TRUE(allV1NodesExist);
}

TEST(NetlistTest, LoadBasicFile_CorrectValues) {
  auto instructions = LoadCircuitInstructions(SAVEFILES_PATH "basiccircuit.net");

  auto expectedValuesR3 = {"220"};

  auto& values = instructions.components[std::string("R3")].values;

  bool allR3ValuesExist = std::all_of(
    expectedValuesR3.begin(),
    expectedValuesR3.end(),
    [&](auto exp){
      return std::find(values.begin(), values.end(), exp) != values.end();
    }
  );

  bool noMoreValues = expectedValuesR3.size() == values.size();

  EXPECT_TRUE(allR3ValuesExist && noMoreValues);
}
