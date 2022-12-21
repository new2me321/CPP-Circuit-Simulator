#ifndef CIRCUIT_SIMULATOR_NODE_H_
#define CIRCUIT_SIMULATOR_NODE_H_

#include "../Circuit/component.hpp"
#include <list>

class Node
{
public:
    // constructor taking the node ID string as a parameter
    Node(const std::string &node_id);

    // specialised destructor to release memory
    ~Node();

    // GETTERS

    std::string GetID() const { return node_id_; }
    auto GetConnections() const { return connections_; }
    bool IsGND() const { return is_ground_; }
    double GetPotential() const { return potential_; }

    // SETTERS

    // set the Node id to be a specified value
    void SetID(std::string new_id) { node_id_ = new_id; }
    // set the node as GND, also at the same time setting its potential to be 0.0.
    void SetGND()
    {
        is_ground_ = true;
        potential_ = 0.0;
    }
    // set the potential value of the node currently
    // TODO: check if is ground and throw error if user is trying to set GND != 0.0.
    void SetPotential(double new_pot) { potential_ = new_pot; }

    // ACCESSORS

    // add a connection to the list of connections.
    /**
     * @brief Add a connection to the list of connections.
     * Used when constructing the circuit in constructors, and testing.
     *
     * @param val a Component-Node pair to be added: created with make_pair for example.
     */
    void Add(std::pair<Component *, Node> val) { connections_.push_back(val); }

    /**
     * @brief Get the Components connected to this node, regardless of what they are connected to.
     *
     * @return std::list<Component> containing the Component-derived objects connected to the node.
     */
    std::list<Component *> GetComponents() const;

    /**
     * @brief Get the Node-objects connected to this one, regardless of what connnects them.
     *
     * @return std::list<Node> containing the Node-objects connected to this Node, self not contained.
     */
    std::list<Node> GetNodes() const;

    /**
     * @brief Get the Component-objects connected between this and some other specified Node.
     *
     * TODO: throw an error if the connections_ lists of the two objects do not match.
     *
     * @param other Node-object to which compare with
     * @return std::list<Component> containing the Component-objects between this and Node other.
     */
    std::list<Component *> GetComponents(Node other) const;

    /**
     * @brief Create a list of mappings from node_ids and corresponding connected component values.
     * If the node is GND, return an empty map.
     *
     * TODO:
     *
     * @return std::map<std::string, double> containing the mappings of connected components. Empty if node is GND.
     */
    std::map<std::string, double> CreateEquation() const;

private:
    // Unique node ID
    std::string node_id_;
    // list of pairs storing the information about the connections between nodes.
    // pairs instead of maps as two nodes can be connected with multiple components in parallel.
    std::list<std::pair<Component *, Node>> connections_;
    // bool variable indicating if the node is GND, false by default.
    bool is_ground_ = false;
    // double storing the node's potential at the current timestep. (do we use this?)
    double potential_;
};

#endif
