#ifndef CIRCUIT_SIMULATOR_COMPONENT_VOLTAGE_SOURCE_H_
#define CIRCUIT_SIMULATOR_COMPONENT_VOLTAGE_SOURCE_H_

#include "component.hpp"

class DCVoltageSource : public Component
{
public:
    DCVoltageSource(const std::string &name, 
                    double voltage = 0);

    void SetValue(const double value);
    double GetValue() const;
    ComponentType GetType() const ;

private:
    double voltage_;
};

// TODO: Create AC voltage constructor
class ACVoltageSource : public Component
{
};

#endif