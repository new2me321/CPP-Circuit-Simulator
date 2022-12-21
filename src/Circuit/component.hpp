#ifndef CIRCUIT_SIMULATOR_COMPONENT_COMPONENT_H_
#define CIRCUIT_SIMULATOR_COMPONENT_COMPONENT_H_

#include <iostream>
#include <map>
#include <string>
// #include "Circuit/node.hpp"

/**
 * @brief Types of components available
 *
 */
enum ComponentType
{
  RESISTOR,
  CAPACITOR,
  INDUCTOR,
  DCSUPPLY,
  ACSUPPLY,
  NONE
};

enum TerminalPin // pinA (negative) ---||||--- pinB (positive)
{
  pinA,
  pinB
};

/**
 * @brief A pure abstract class describing a generic component.
 *
 * Has as member functions getters and accessors defined and used by subclasses.
 *
 * As member values has the terminals and the component value.
 *
 */
class Component
{
public:
  Component(const std::string &name, double value);

  // pure virtual destructor so that subclasses can define a non-default one to
  // and avoid memory leaks
  virtual ~Component() = 0;

  // pure virtual setters, getters and accessors
  virtual void SetValue(const double value) = 0;
  virtual double GetValue() const = 0;

  const std::string &GetName() const; // returns the name i.e R, C, I etc.

  virtual ComponentType GetType() const = 0;

  void SetID(unsigned id) { id_ = id; }
  unsigned GetID() const { return id_; }
  std::string CreateId();

  // node
  const std::string &GetNode1() const { return node1_id; }
  const std::string &GetNode2() const { return node2_id; }
  void SetNode1(const std::string &n) { node1_id = n; }
  void SetNode2(const std::string &n) { node2_id = n; }

protected:
  double value_; // resistance/inductance/capacitance etc
  std::map<std::string, ComponentType> type_ = {{"R", RESISTOR}, {"L", INDUCTOR}, {"C", CAPACITOR}, {"V", DCSUPPLY}, {"ACVS", ACSUPPLY}, {"None", NONE}};

  unsigned id_ = 0;

private:
  std::string name_; // stores component name
  std::string node1_id;
  std::string node2_id;
};

#endif