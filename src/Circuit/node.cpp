#include "node.hpp"

// Node-class member functions
Node::Node(const std::string &node_id)
    : node_id_(node_id) {}

Node::~Node()
{
    for (auto p :connections_){
        delete p.first;
    }
    connections_.clear();
}

std::list<Component *> Node::GetComponents() const
{
    std::list<Component *> ret_list;
    for (auto it = connections_.begin(); it != connections_.end(); ++it)
    {
        ret_list.push_back(it->first);
    }
    return ret_list;
}

std::list<Node> Node::GetNodes() const
{
    std::list<Node> ret_list;
    for (auto it = connections_.begin(); it != connections_.end(); ++it)
    {
        ret_list.push_back(it->second);
    }
    return ret_list;
}

std::list<Component *> Node::GetComponents(Node other) const
{
    std::list<Component *> ret_list;
    for (auto it = connections_.begin(); it != connections_.end(); ++it)
    {
        if (it->second.GetID() == other.GetID())
        {
            ret_list.push_back(it->first);
        }
    }
    return ret_list;
}

std::map<std::string, double> Node::CreateEquation() const
{
    std::map<std::string, double> ret_list;
    if (!IsGND())
    {
        return ret_list;
    }

    double self = 0;
    std::string holder1;
    double holder2;
    for (auto it = connections_.begin(); it != connections_.end(); ++it)
    {
        holder1 = (*it).second.GetID();
        holder2 = it->first->GetValue();
        self += holder2;
        // negative sign in the equation due to "leaving" from the node
        if (ret_list.find(holder1) != ret_list.end())
        {
            ret_list[holder1] = -holder2;
        }
        else
        {
            ret_list[holder1] = ret_list[holder1] - holder2;
        }
    }
    ret_list[node_id_] = self;

    return ret_list;
}
