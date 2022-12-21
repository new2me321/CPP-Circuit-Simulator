#include "solver.hpp"

// Solver-class member functions
using namespace boost::numeric::ublas;
using array_2D = boost::multi_array<double, 2>;

Solver::Solver(Circuit &circuit) : circuit_(circuit)
{
}

void Solver::CreateMatrices(Circuit &circuit)
{
    node_idxs_.clear();
    std::complex<double> admittance;
    int v_count = 0; // counter for voltages

    // Initialize Matrix Formation
    int idx = 0;
    m_ = 0;

    for (auto c : circuit.GetComponents())
    {
        if (c->GetType() == DCSUPPLY)
        {
            m_++;
        }
    }
    if (m_ == 0)
    {
        throw std::runtime_error("Circuit is invalid");
    }

    // Generate node indexes
    for (auto node : circuit.GetNodes())
    {
        idx++;
        // std::cout <<"idx" <<idx <<std::endl;
        node_idxs_.emplace(std::make_pair(node.GetID(), idx));
    }


    n_ = circuit.GetNodes().size() + m_ - 1;
    std::cout << "m_: " << m_ << " " << n_ << "\n";

    boost::numeric::ublas::matrix<std::complex<double>> A(n_, n_, 0.0); // A matrix
    constant_type b(n_, 0.0);                                           // B matrix

    // loop through all components
    for (auto c : circuit.GetComponents())
    {
        if (c->GetType() == RESISTOR || c->GetType() == INDUCTOR || c->GetType() == CAPACITOR)
        {
            admittance = 1 / std::complex<double>(c->GetValue());

            if (c->GetNode1() == "GND")
            {
                A(node_idxs_[c->GetNode2()] - 1, node_idxs_[c->GetNode2()] - 1) += admittance;
            }
            else if (c->GetNode2() == "GND")
            {
                // std::cout << "A[" << node_idxs_[c->GetNode1()] - 1 << "][" << node_idxs_[c->GetNode1()] - 1 << std::endl;
                A(node_idxs_[c->GetNode1()] - 1, node_idxs_[c->GetNode1()] - 1) += admittance;
            }
            else
            {
                A(node_idxs_[c->GetNode1()] - 1, node_idxs_[c->GetNode1()] - 1) += admittance;
                A(node_idxs_[c->GetNode1()] - 1, node_idxs_[c->GetNode2()] - 1) += -admittance;
                A(node_idxs_[c->GetNode2()] - 1, node_idxs_[c->GetNode1()] - 1) += -admittance;
                A(node_idxs_[c->GetNode2()] - 1, node_idxs_[c->GetNode2()] - 1) += admittance;
            }
        }

        if (c->GetType() == DCSUPPLY)
        {
            if (c->GetNode1() == "GND")
            {
                A(node_idxs_[c->GetNode2()] - 1, n_ - m_ + v_count) += -1;
                A(n_ - m_ + v_count, node_idxs_[c->GetNode2()] - 1) += -1;
            }
            else if (c->GetNode2() == "GND")
            {
                A(node_idxs_[c->GetNode1()] - 1, n_ - m_ + v_count) += 1;
                A(n_ - m_ + v_count, node_idxs_[c->GetNode1()] - 1) += 1;
            }
            else
            {
                A(node_idxs_[c->GetNode1()] - 1, n_ - m_ + v_count) += 1;
                A(node_idxs_[c->GetNode2()] - 1, n_ - m_ + v_count) += -1;
                A(n_ - m_ + v_count, node_idxs_[c->GetNode1()] - 1) += 1;
                A(n_ - m_ + v_count, node_idxs_[c->GetNode2()] - 1) += -1;
            }

            //     // b matrix
            b(n_ - m_ + v_count) = c->GetValue();

            v_count++;
        }
    }

    MatA_ = A;
    Vecb_ = b;
}

std::vector<std::pair<std::string, double>> Solver::ComputeCurrents(Circuit &c, complex_state_type &NodeVoltages)
{
    currents_.clear();
    double Vd = 0;        // voltage difference btn nodes
    double c_current = 0; // current
    for (auto n : c.GetComponents())
    {
        double pinBVolt = (NodeVoltages[node_idxs_[n->GetNode2()] - 1]).real();
        double pinAVolt = (NodeVoltages[node_idxs_[n->GetNode1()] - 1]).real();

        if (n->GetNode1() == "GND")
        {
            pinAVolt = 0;
        }
        if (n->GetNode2() == "GND")
        {
            pinBVolt = 0;
        }

        Vd = pinBVolt - pinAVolt;

        if (n->GetType() != DCSUPPLY)
        {
            c_current = Vd / n->GetValue();
        }

        currents_.push_back(make_pair(n->GetName(), c_current));
    }

    return currents_;
}

complex_state_type Solver::RunBasicSolver(const boost::numeric::ublas::matrix<std::complex<double>> &A, const constant_type &z)
{
    size_t n = A.size2();

    boost::numeric::ublas::matrix<std::complex<double>> A_inv(n, n);

    if (!inverse(A, A_inv))
    {
        throw std::invalid_argument("Could not invert matrix");
    }

    auto x = prod(A_inv, z);
    return x;
}

void Solver::Solve(Circuit &c)
{
    // set precision
    std::cout << std::setprecision(3) << std::fixed;

    this->CreateMatrices(c);
    boost::numeric::ublas::matrix<std::complex<double>> A = this->GetAMatrix();
    boost::numeric::ublas::vector<double> b = this->GetbVector();
    auto res = this->RunBasicSolver(A, b);

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
    auto resCur = this->ComputeCurrents(c, res);
    for (auto it : resCur)
    {
        std::cout << it.first << " " << it.second << std::endl;
    }
}