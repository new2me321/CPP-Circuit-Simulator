#include <iostream>
#include <memory>
#include <bits/stdc++.h>
#include "Circuit/circuit.hpp"
#include "Circuit/component.hpp"
#include "Circuit/resistor.hpp"
#include "Circuit/node.hpp"
#include "Circuit/capacitor.hpp"
#include "Circuit/capacitor.hpp"
#include "Circuit/inductor.hpp"
#include "Circuit/voltage_source.hpp"
#include "GUI/gui.hpp"
#include "Solver/solver.hpp"
#include "Circuit/circuit_netlist.hpp"

/*


Note:
- Inside the main function are two (hard coded) solver examples
- We did not have time to integrate the solver into the GUI :(



*/

void SolverExample1()
{
  std::cout << "------------Create a circuit------------ " << std::endl;
  Circuit c;

  // // create some resistor components
  Component *r1 = new Resistor("R1", 100);
  Component *r2 = new Resistor("R2", 100);
  Component *r3 = new Resistor("R3", 100);
  Component *v1 = new DCVoltageSource("V1", 5);

  // add components
  c.AddComponent(r1);
  c.AddComponent(r2);
  c.AddComponent(r3);
  c.AddComponent(v1);

  std::cout << "------------Testing Component GetType------------ " << std::endl;
  std::cout << (*v1).GetType() << std::endl;

  std::cout << "Nodes before connecting components..." << std::endl;
  std::cout << "Nodes on R1 " << r1->GetNode1() << " " << r1->GetNode2() << std::endl; // N0, N1
  std::cout << "Nodes on R2 " << r2->GetNode1() << " " << r2->GetNode2() << std::endl; // N2, N3
  std::cout << "Nodes on R3 " << r3->GetNode1() << " " << r3->GetNode2() << std::endl; // N4, N5
  std::cout << "Nodes on V1 " << v1->GetNode1() << " " << v1->GetNode2() << std::endl; // N6, N7

  std::cout << "------------Connecting components------------ " << std::endl;

  c.ConnectComponent(r1, pinB, r2, pinA);
  c.ConnectComponent(r2, pinB, r3, pinA);
  c.ConnectComponent(r3, pinB, v1, pinB);
  c.ConnectComponent(v1, pinA, r1, pinA);
  c.ConnectGround(v1, pinB);

  std::cout << "Nodes after connecting components... " << std::endl;
  std::cout << "Nodes on R1 " << r1->GetNode1() << " " << r1->GetNode2() << std::endl; // N0, N2
  std::cout << "Nodes on R2 " << r2->GetNode1() << " " << r2->GetNode2() << std::endl; // N2, N4
  std::cout << "Nodes on R3 " << r3->GetNode1() << " " << r3->GetNode2() << std::endl; // N4, N6
  std::cout << "Nodes on V1 " << v1->GetNode1() << " " << v1->GetNode2() << std::endl; // N6, N0

  std::cout << "------------Validating nodes------------ " << std::endl;
  std::cout << "Nodes count: " << c.GetNodes().size() << std::endl; // Should be 4

  for (auto n : c.GetNodes())
  { // should be N0, N2, N4, N6
    std::cout << n.GetID() << " is GND: " << n.IsGND() << std::endl;
  }

  std::cout << "------------Initializing Solver------------ " << std::endl;
  Solver solver(c);

  solver.CreateMatrices(c);
  // solver.ShowMatrices();
  boost::numeric::ublas::matrix<std::complex<double>> A = solver.GetAMatrix();
  boost::numeric::ublas::vector<double> b = solver.GetbVector();
  typedef boost::numeric::ublas::matrix_row<cmatrix> rowThing;

  std::cout << A << std::endl;
  for (size_t i = 0; i < A.size1(); i++)
  {
    auto row = rowThing(A, i);
    for (auto it = row.begin(); it != row.end(); it++)
      std::cout << (*it).real() << "\t";
    std::cout << std::endl;
  }

  auto res = solver.RunBasicSolver(A, b);
  std::cout << "this: " << std::fixed << std::setprecision(2) << res << std::endl;
  auto resCur = solver.ComputeCurrents(c, res);
  for (auto it : resCur)
  {
    std::cout << it.first << " " << it.second << std::endl;
  }

  // c.ClearCircuit();
}

void SolverExample2()
{
  std::cout << "------------Create a circuit------------ " << std::endl;
  Circuit c;

  Component *r1 = new Inductor("I1", 2);
  Component *r2 = new Resistor("R2", 4);
  Component *r3 = new Resistor("R3", 4);
  Component *v1 = new DCVoltageSource("V1", 10);
  Component *v2 = new DCVoltageSource("V2", 12);

  // add components
  c.AddComponent(r1);
  c.AddComponent(r2);
  c.AddComponent(r3);
  c.AddComponent(v1);
  c.AddComponent(v2);

  std::cout << "------------Testing Component GetType------------ " << std::endl;
  // std::cout << (*v1).GetType() << std::endl;

  std::cout << "Nodes before connecting components..." << std::endl;
  std::cout << "Nodes on R1 " << r1->GetNode1() << " " << r1->GetNode2() << std::endl; // N0, N1
  std::cout << "Nodes on R2 " << r2->GetNode1() << " " << r2->GetNode2() << std::endl; // N2, N3
  std::cout << "Nodes on R3 " << r3->GetNode1() << " " << r3->GetNode2() << std::endl; // N4, N5
  std::cout << "Nodes on V1 " << v1->GetNode1() << " " << v1->GetNode2() << std::endl; // N6, N7
  std::cout << "Nodes on V2 " << v2->GetNode1() << " " << v2->GetNode2() << std::endl; // N6, N0

  std::cout << "------------Connecting components------------ " << std::endl;

  // c.ConnectComponent(v1, pinB, r1, pinA);
  // c.ConnectComponent(r1, pinB, r2, pinA);
  // c.ConnectComponent(r2, pinB, v1, pinA);
  // c.ConnectComponent(r3, pinA, r1, pinB);
  // c.ConnectComponent(r3, pinB, v2, pinB);
  // c.ConnectComponent(v2, pinA, v1, pinA);
  // c.ConnectGround(v1, pinA);

  c.ConnectComponent(v1, pinA, r1, pinA);
  c.ConnectComponent(v2, pinB, v1, pinB);
  c.ConnectComponent(r1, pinB, r2, pinA);
  c.ConnectComponent(r3, pinA, r1, pinB);
  c.ConnectComponent(r2, pinB, v1, pinB);
  c.ConnectComponent(r3, pinB, v2, pinA);
  c.ConnectGround(v1, pinB);

  std::cout << "Nodes after connecting components... " << std::endl;
  std::cout << "Nodes on R1 " << r1->GetNode1() << " " << r1->GetNode2() << std::endl; // N0, N2
  std::cout << "Nodes on R2 " << r2->GetNode1() << " " << r2->GetNode2() << std::endl; // N2, N4
  std::cout << "Nodes on R3 " << r3->GetNode1() << " " << r3->GetNode2() << std::endl; // N4, N6
  std::cout << "Nodes on V1 " << v1->GetNode1() << " " << v1->GetNode2() << std::endl; // N6, N0
  std::cout << "Nodes on V2 " << v2->GetNode1() << " " << v2->GetNode2() << std::endl; // N6, N0

  std::cout << "------------Validating nodes------------ " << std::endl;
  std::cout << "Nodes count: " << c.GetNodes().size() << std::endl; // Should be 4

  for (auto n : c.GetNodes())
  { // should be N0, N2, N4, N6
    std::cout << n.GetID() << " is GND: " << n.IsGND() << std::endl;
  }

  std::cout << "------------Initializing Solver------------ " << std::endl
            << std::fixed << std::setprecision(2);
  Solver solver(c);

  solver.CreateMatrices(c);
  // solver.ShowMatrices();
  boost::numeric::ublas::matrix<std::complex<double>> A = solver.GetAMatrix();
  boost::numeric::ublas::vector<double> b = solver.GetbVector();
  typedef boost::numeric::ublas::matrix_row<cmatrix> rowThing;

  std::cout << "\nA Matrix"
            << "\n\n";
  for (size_t i = 0; i < A.size1(); i++)
  {
    auto row = rowThing(A, i);
    for (auto it = row.begin(); it != row.end(); it++)
      std::cout << (*it).real() << "\t";
    std::cout << std::endl;
  }

  std::cout << "\nb Vector:"
            << "\n\n";
  for (auto it : b)
  {
    std::cout << it << std::endl;
  }

  auto res = solver.RunBasicSolver(A, b);
  int i = 0;
  std::cout << "Voltages at each Node: " << std::endl;
  for (auto it : c.GetNodes())
  {
    double pinVolt = res[i].real();
    if (it.GetID() == "GND")
    {
      pinVolt = 0;
    }
    if (it.GetID() == "GND")
    {
      pinVolt = 0;
    }
    std::cout << it.GetID() << " " << pinVolt
              << std::endl;
    i++;
  }

  std::cout << "Currents through components: " << std::endl;
  auto resCur = solver.ComputeCurrents(c, res);
  for (auto it : resCur)
  {
    std::cout << it.first << " " << it.second << std::endl;
  }
}

void TestSolver3()
{
  std::cout << "------------Create a circuit------------ " << std::endl;
  Circuit c;

  // // create some resistor components
  // Component *r1 = new Resistor("R1", 100);
  Component *r1 = new Inductor("I1", 1e-6);
  // Component *r2 = new Resistor("R2", 100);
  Component *r2 = new Capacitor("C1", 1e-6);
  // Component *r2 = new Capacitor("C1", 1e-6);
  Component *r3 = new Resistor("R3", 100);
  Component *v1 = new DCVoltageSource("V1", 5);

  // add components
  c.AddComponent(r1);
  c.AddComponent(r2);
  c.AddComponent(r3);
  c.AddComponent(v1);

  std::cout << "------------Testing Component GetType------------ " << std::endl;
  std::cout << (*v1).GetType() << std::endl;

  std::cout << "Nodes before connecting components..." << std::endl;
  std::cout << "Nodes on R1 " << r1->GetNode1() << " " << r1->GetNode2() << std::endl; // N0, N1
  std::cout << "Nodes on R2 " << r2->GetNode1() << " " << r2->GetNode2() << std::endl; // N2, N3
  std::cout << "Nodes on R3 " << r3->GetNode1() << " " << r3->GetNode2() << std::endl; // N4, N5
  std::cout << "Nodes on V1 " << v1->GetNode1() << " " << v1->GetNode2() << std::endl; // N6, N7

  std::cout << "------------Connecting components------------ " << std::endl;

  c.ConnectComponent(r1, pinB, r2, pinA);
  c.ConnectComponent(r2, pinB, r3, pinA);
  c.ConnectComponent(r3, pinB, v1, pinB);
  c.ConnectComponent(v1, pinA, r1, pinA);
  c.ConnectGround(v1, pinB);

  std::cout << "Nodes after connecting components... " << std::endl;
  std::cout << "Nodes on R1 " << r1->GetNode1() << " " << r1->GetNode2() << std::endl; // N0, N2
  std::cout << "Nodes on R2 " << r2->GetNode1() << " " << r2->GetNode2() << std::endl; // N2, N4
  std::cout << "Nodes on R3 " << r3->GetNode1() << " " << r3->GetNode2() << std::endl; // N4, N6
  std::cout << "Nodes on V1 " << v1->GetNode1() << " " << v1->GetNode2() << std::endl; // N6, N0

  std::cout << "------------Validating nodes------------ " << std::endl;
  std::cout << "Nodes count: " << c.GetNodes().size() << std::endl; // Should be 4

  for (auto n : c.GetNodes())
  { // should be N0, N2, N4, N6
    std::cout << n.GetID() << " is GND: " << n.IsGND() << std::endl;
  }

  std::cout << "------------Initializing Solver------------ " << std::endl;
  Solver solver(c);

  solver.CreateMatrices(c);
  // solver.ShowMatrices();
  boost::numeric::ublas::matrix<std::complex<double>> A = solver.GetAMatrix();
  boost::numeric::ublas::vector<double> b = solver.GetbVector();

  auto res = solver.RunBasicSolver(A, b);
  std::cout << "this: " << std::fixed << std::setprecision(2) << res << std::endl;
}

void TestSolver4()
{
  std::cout << "------------Create a circuit------------ " << std::endl;
  Circuit c;

  Component *r1 = new Inductor("R1", 2);
  Component *r2 = new Resistor("R2", 4);
  Component *r3 = new Resistor("R3", 4);
  Component *v1 = new DCVoltageSource("V1", 10);
  Component *v2 = new DCVoltageSource("V2", 12);

  // add components
  c.AddComponent(r1);
  c.AddComponent(r2);
  c.AddComponent(r3);
  c.AddComponent(v1);
  c.AddComponent(v2);

  std::cout << "------------Testing Component GetType------------ " << std::endl;
  // std::cout << (*v1).GetType() << std::endl;

  std::cout << "Nodes before connecting components..." << std::endl;
  std::cout << "Nodes on R1 " << r1->GetNode1() << " " << r1->GetNode2() << std::endl; // N0, N1
  std::cout << "Nodes on R2 " << r2->GetNode1() << " " << r2->GetNode2() << std::endl; // N2, N3
  std::cout << "Nodes on R3 " << r3->GetNode1() << " " << r3->GetNode2() << std::endl; // N4, N5
  std::cout << "Nodes on V1 " << v1->GetNode1() << " " << v1->GetNode2() << std::endl; // N6, N7

  std::cout << "------------Connecting components------------ " << std::endl;

  c.ConnectGround(v1, pinB);
  c.ConnectComponent(v1, pinA, r1, pinA);
  c.ConnectComponent(v2, pinB, v1, pinB);
  c.ConnectComponent(r1, pinB, r2, pinA);
  c.ConnectComponent(r3, pinA, r1, pinB);
  c.ConnectComponent(r2, pinB, v1, pinB);
  c.ConnectComponent(r3, pinB, v2, pinA);

  std::cout << "Nodes after connecting components... " << std::endl;
  std::cout << "Nodes on R1 " << r1->GetNode1() << " " << r1->GetNode2() << std::endl; // N0, N2
  std::cout << "Nodes on R2 " << r2->GetNode1() << " " << r2->GetNode2() << std::endl; // N2, N4
  std::cout << "Nodes on R3 " << r3->GetNode1() << " " << r3->GetNode2() << std::endl; // N4, N6
  std::cout << "Nodes on V1 " << v1->GetNode1() << " " << v1->GetNode2() << std::endl; // N6, N0
  std::cout << "Nodes on V2 " << v2->GetNode1() << " " << v2->GetNode2() << std::endl; // N6, N0

  std::cout << "------------Validating nodes------------ " << std::endl;
  std::cout << "Nodes count: " << c.GetNodes().size() << std::endl; // Should be 4

  for (auto n : c.GetNodes())
  { // should be N0, N2, N4, N6
    std::cout << n.GetID() << " is GND: " << n.IsGND() << std::endl;
  }

  std::cout << "------------Initializing Solver------------ " << std::endl
            << std::fixed << std::setprecision(2);
  Solver solver(c);

  solver.CreateMatrices(c);
  // solver.ShowMatrices();
  boost::numeric::ublas::matrix<std::complex<double>> A = solver.GetAMatrix();
  boost::numeric::ublas::vector<double> b = solver.GetbVector();
  typedef boost::numeric::ublas::matrix_row<cmatrix> rowThing;

  std::cout << A << std::endl;
  for (size_t i = 0; i < A.size1(); i++)
  {
    auto row = rowThing(A, i);
    for (auto it = row.begin(); it != row.end(); it++)
      std::cout << *it << "\t";
    std::cout << std::endl;
  }

  auto res = solver.RunBasicSolver(A, b);
  std::cout << "this: " << std::fixed << std::setprecision(2) << res << std::endl;
}

void TestNetlist(){
  auto instructions = LoadCircuitInstructions("savefiles/circuit_test1.net");
  // auto instructions = LoadCircuitInstructions("savefiles/basiccircuit.net");
  if(!instructions.loadSuccess){
    std::cout << "Instructions not loaded successfully.\n";
  }

  Circuit circuit;
  circuit.ConstructFromInstructions(instructions);

  Solver solver(circuit);
  solver.Solve(circuit);
}

int main()
{
  // SolverExample1();
  // SolverExample2();
  // TestNetlist();
  auto gui = std::make_shared<GUI>(1200, 800, "Circuit simulator");
  gui->Run();

  return 0;
}
