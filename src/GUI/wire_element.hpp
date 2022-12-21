#ifndef __WIRE_ELEMENT_H__
#define __WIRE_ELEMENT_H__

#include "element_collection.hpp"
#include "wire_node.hpp"

/**
 * @brief WireElement is the Workspace representation of wire.
 * 
 * @details
 *  Draws a line between two WireNodes
 */
class WireElement : public Element{
public:
  /**
   * @brief Construct a new Wire Element object
   * 
   * @param node1 first node of the wire
   * @param node2 second node of the wire
   */
  WireElement(std::shared_ptr<WireNode> node1, std::shared_ptr<WireNode> node2);

  /**
   * @brief override Element::Draw
   * 
   * @details Draw line between the two nodes
   * 
   * @param window 
   */
	virtual void Draw(sf::RenderWindow& window) const override;

  /**
   * @brief Helper function to determine if a node with given id is an end of this wire.
   * 
   * @param nodeId 
   * @return true if node is one end of WireElement
   */
  bool Contains(unsigned nodeId) const;
  
  /**
   * @brief Get the Node object
   * 
   * @warning
   *  GetNode return value should not be stored. The return value is a raw pointer,
   *  because this function does not manage memory.
   * 
   * @param index, either 0 or 1, otherwise invalid
   * @return WireNode*, nullptr if element is not contained here
   */
  WireNode* GetNode(int index) const;

  /**
   * @brief Set the Node object
   * 
   * @param index, either 0 or 1, otherwise invalid
   * @param node
   */
  void SetNode(int index, std::shared_ptr<WireNode> node);

  /**
   * @brief override Element::GetElementsThatContain
   * 
   * @details Will give the id of WireNode that contain the position
   * 
   * @param position 
   * @return std::vector<unsigned> 
   */
  virtual std::vector<unsigned> GetElementsThatContain(sf::Vector2f position) const override;

private:
  /**
   * @brief The two ends of WireElement
   */
  std::shared_ptr<WireNode> node1_, node2_;

  /**
   * @brief Color of the wire
   */
  const sf::Color wireColor_ = sf::Color::Black;
  const float wireThickness = 4.0;
};

#endif // __WIRE_ELEMENT_H__