#include "inductor.hpp"

Inductor::Inductor(const std::string& name, double value)
    : Component(name, value) {
  inductance_ = value;
}

void Inductor::SetValue(const double value) { inductance_ = value; }
double Inductor::GetValue() const { return inductance_; }
ComponentType Inductor::GetType() const{ return INDUCTOR; }
