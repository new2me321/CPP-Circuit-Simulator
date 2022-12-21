#include "capacitor.hpp"

Capacitor::Capacitor(const std::string& name, double value)
    : Component(name, value) {
  capacitance_ = value;
}

void Capacitor::SetValue(const double value) { capacitance_ = value; }
double Capacitor::GetValue() const { return capacitance_; }
// int Capacitor::GetID() { return this->type_['C']; }
ComponentType Capacitor::GetType() const { return CAPACITOR; }
// void Capacitor::Use() {}