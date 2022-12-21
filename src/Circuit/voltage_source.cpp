#include "voltage_source.hpp"
DCVoltageSource::DCVoltageSource(const std::string &name, double value)
    : Component(name, value)
{
  voltage_ = value;
}

void DCVoltageSource::SetValue(const double value) { voltage_ = value; }
double DCVoltageSource::GetValue() const { return voltage_; }

ComponentType DCVoltageSource::GetType() const
{
  return DCSUPPLY;
}