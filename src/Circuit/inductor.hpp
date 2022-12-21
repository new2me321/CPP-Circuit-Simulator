#ifndef CIRCUIT_SIMULATOR_COMPONENT_INDUCTOR_H_
#define CIRCUIT_SIMULATOR_COMPONENT_INDUCTOR_H_

#include "component.hpp"

class Inductor : public Component
{
public:
  Inductor(const std::string &name, double value);
  ~Inductor() = default;

  void SetValue(const double value);
  double GetValue() const;

  ComponentType GetType() const;

private:
  double inductance_;
};

#endif