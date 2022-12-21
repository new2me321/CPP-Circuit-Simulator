#ifndef __WIRE_NODE_H__
#define __WIRE_NODE_H__

#include "element.hpp"

/**
 * @brief WireNode is a pin in an electrical component or one end of a wire
 * 
 * @details
 *  Will be used by ComponentElement and WireElement.
 *  Can be moved in a Workspace
 * 
 * @see workspace.hpp
 */
class WireNode : public Element{
public:
  /**
   * @brief Construct a new Wire Node object at a given position
   * 
   * @param position start of first WireNode
   */
  WireNode(sf::Vector2f position);

  /**
   * @brief override Element::Draw
   * 
   * @details Draws a rectangle at its position
   * 
   * @param window 
   */
  virtual void Draw(sf::RenderWindow& window) const override;

  /**
   * @brief override Element::HandleEvent
   * 
   * @details Node can be dragged around in a Workspace with a mouse.
   * 
   * @param event 
   */
  virtual void HandleEvent(const sf::Event& event) override;

  virtual void HandleDimensionsUpdated() override;

private:
  /**
   * @brief boolean flag wether the node is currently being dragged.
   */
  bool beingDragged_;

  /**
   * @brief A rectangle object used for drawing.
   */
  sf::RectangleShape wireNodeShape_;

  /**
   * @brief Rectangle size for drawing.
   */
  const sf::Vector2f wireNodeShapeSize_ = sf::Vector2f(10, 10);

  /**
   * @brief Rectangle size for dragging with mouse.
   * 
   * @details
   *  It is more comfortable to have a larger rectangle for draggin nodes, even
   *  when the drawn rectangle is smaller.
   */
  const sf::Vector2f wireNodeHandleSize_ = sf::Vector2f(30, 30);

  /**
   * @brief Color of the WireNode
   */
  const sf::Color wireNodeColor_ = sf::Color::Black;
};

#endif // __WIRE_NODE_H__