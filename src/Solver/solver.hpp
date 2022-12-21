#ifndef CIRCUIT_SIMULATOR_SOLVER_SOLVER_H_
#define CIRCUIT_SIMULATOR_SOLVER_SOLVER_H_

#include "inverse.hpp"
#include "../Circuit/circuit.hpp"
#include "../Circuit/component.hpp"
#include "../Circuit/node.hpp"

#include <list>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include <boost/numeric/odeint.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/multi_array.hpp>
#include "inverse.hpp"

typedef boost::numeric::ublas::vector<double> state_type;                       // two dimensional array to store the values of vector x as a function of time
typedef boost::numeric::ublas::matrix<double> parameter_type;                   // parameter matrix
typedef boost::numeric::ublas::vector<double> constant_type;                    // this is the scalars on the right side of the equation
typedef boost::numeric::ublas::vector<std::complex<double>> complex_state_type; // two dimensional array to store the values of vector x as a function of time
typedef boost::numeric::ublas::matrix_row<cmatrix> rowThing;
/**
 * @brief Solver-class created and used to solve the simulation.
 *
 * An instance of Solver is created every time a simulation command is run, and destroyed when the program terminates or a new simulation is run.
 *
 */
class Solver
{
public:
    Solver(Circuit &c);

    void CreateMatrices(Circuit &c);

    const boost::numeric::ublas::matrix<std::complex<double>> GetAMatrix() { return MatA_; };
    const constant_type GetbVector() { return Vecb_; };

    std::vector<std::pair<std::string, double>> ComputeCurrents(Circuit &c, complex_state_type &NodeVoltages);
    
    complex_state_type RunBasicSolver(const boost::numeric::ublas::matrix<std::complex<double>> &A, const constant_type &b);

    void Solve(Circuit& c); //just a complete wrapper around solving steps
private:
    Circuit& circuit_;

    int v_count = 0;
    int m_ = 0;
    int n_ = 0;

    complex_state_type x_vec_;
    boost::numeric::ublas::matrix<std::complex<double>> MatA_;
    constant_type Vecb_;

    std::map<std::string, int>node_idxs_;
    std::vector<std::pair<std::string, double>> currents_;
};

#endif