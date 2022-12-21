#ifndef CIRCUIT_SIMULATOR_COMPONENT_RESISTOR_H_
#define CIRCUIT_SIMULATOR_COMPONENT_RESISTOR_H_

#include "component.hpp"

class Resistor : public Component
{
public:
  Resistor(const std::string &name, double value);
  ~Resistor() = default;

  void SetValue(const double value);
  double GetValue() const;

  ComponentType GetType() const;

private:
  double resistance_;
};

#endif