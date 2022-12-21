#include "component.hpp"

Component::Component(const std::string &name, double value) : node1_id(CreateId()),
                                                              node2_id(CreateId())
{
  name_ = name;
  value_ = value;
}
Component::~Component() {}
double Component::GetValue() const { return value_; }
const std::string &Component::GetName() const { return name_; }

std::string Component::CreateId()
{
  static unsigned int c = 0;
  return std::string("N") + std::to_string(c++);
}