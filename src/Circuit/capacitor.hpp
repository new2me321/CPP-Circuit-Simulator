#ifndef CIRCUIT_SIMULATOR_COMPONENT_CAPACITOR_H_
#define CIRCUIT_SIMULATOR_COMPONENT_CAPACITOR_H_

#include "component.hpp"

/**
 * @brief a generic class describing a capacitor, that inherits
 * the pure abstract class "Component".
 *
 */
class Capacitor : public Component {
 public:
  Capacitor(const std::string& name, double value);
  // default destructor
  ~Capacitor() = default;

  void SetValue(const double value);
  double GetValue() const;
  // void Use();
  // int GetID();
   ComponentType GetType() const ;

 private:
  double capacitance_;
};

#endif
