#include "resistor.hpp"

Resistor::Resistor(const std::string &name, double value)
    : Component(name, value)
{
  resistance_ = value;
}

void Resistor::SetValue(const double value) { resistance_ = value; }
double Resistor::GetValue() const { return resistance_; }

ComponentType Resistor::GetType() const { return RESISTOR; }
