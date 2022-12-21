#ifndef __ELEMENT_COLLECTION_H__
#define __ELEMENT_COLLECTION_H__

#include "element.hpp"
#include <vector>
#include <memory>
#include <algorithm>
#include <limits>
#include <iostream>
#include <functional>

/**
 * @brief ElementCollection is a helper class that stores a collection of element type T
 * 
 * @details
 *  Calls the respective functions for children
 *  e.g. Update -> UpdateChildren
 * 
 * @tparam T 
 */
template<typename T>
class ElementCollection : public Element{
public:
  /**
   * @brief Add new child to collection.
   * 
   * @param child 
   */
	void AddChild(std::shared_ptr<T> child){
    children_.push_back(child);
    ArrangeChildren();
  }

  /**
   * @brief Removes child given its id
   * 
   * @param id 
   * @return true if child was successfully removed
   */
	bool RemoveChild(unsigned id){
    auto it = std::find_if(children_.begin(), children_.end(), [id](const auto& child){ return child->GetID() == id; });
    if(it != children_.end())
      children_.erase(it);

    return it != children_.end();
  }

  /**
   * @brief Draw will call DrawChildren by default
   * 
   * @param window 
   */
  void Draw(sf::RenderWindow& window) const {
    DrawChildren(window);
  }

  /**
   * @brief HandleEvent will call HandleEventChildren by default
   * 
   * @param window 
   */
  void HandleEvent(const sf::Event& event) {
    HandleEventChildren(event);
  }

  /**
   * @brief Update will call UpdateChildren by default
   * 
   * @param window 
   */
  void Update() {
    UpdateChildren();
  }

  /**
   * @brief Override Element::HandleDimensionsUpdated
   * 
   * @details Calls ArrangeChildren
   * 
   * @see ArrangeChildren
   */
	virtual void HandleDimensionsUpdated() override{
    ArrangeChildren();
  }

  /**
   * @brief Get the size of the collection
   * 
   * @details Find the total area occupied by all its children.
   * 
   * @return sf::Vector2f 
   */
	virtual sf::Vector2f GetSize() const override{
    // find min and max for x and y, then return the differences as sf::Vector
    if(children_.empty()){
      return sf::Vector2f(0.f, 0.f);
    }

    float minx = std::numeric_limits<float>::max(), maxx = std::numeric_limits<float>::min();
    float miny = std::numeric_limits<float>::max(), maxy = std::numeric_limits<float>::min();

    for(auto& child : children_){
      minx = std::min(minx, child->GetPosition().x);
      maxx = std::max(maxx, child->GetPosition().x + child->GetSize().x);
      miny = std::min(miny, child->GetPosition().y);
      maxy = std::max(maxy, child->GetPosition().y + child->GetSize().y);
    };

    return sf::Vector2f(maxx - minx, maxy - miny);
  }

  /**
   * @brief Get children that are located at position
   * 
   * @details Calls GetElementsThatContain for all children and combines the results.
   * 
   * @param position 
   * @return std::vector<unsigned> childrenIds
   */
	virtual std::vector<unsigned> GetElementsThatContain(sf::Vector2f position) const override{
    std::vector<unsigned> result;
    std::for_each(children_.begin(), children_.end(), [&result, &position](const auto& child){
      auto childResult = child->GetElementsThatContain(position);
      result.insert(result.end(), childResult.begin(), childResult.end());
    });
    return result;
  }

  /**
   * @brief Get element with id and store it in element
   * 
   * @details Calls GetElementWithId for all chilren and returns the element when found.
   * 
   * @param id 
   * @param element 
   * @return true if element was found and successfully stored in element
   */
	virtual bool GetElementWithId(unsigned id, Element*& element) const override{
    std::find_if(children_.begin(), children_.end(), [id, &element](const auto& child){
      return child->GetElementWithId(id, element);
    });
    return element != nullptr;
  }

  /**
   * @brief Helper function for find_if
   * 
   * @param condition
   * @return unsigned
   */
  unsigned FindIf(std::function<bool(const std::shared_ptr<T>&)> condition){
    auto it = std::find_if(children_.begin(), children_.end(), condition);
    return (it == children_.end() ? 0 : (*it)->GetID());
  }

  /**
   * @brief Get all children
   * 
   * @return const std::vector<std::shared_ptr<T>>& 
   */
  const std::vector<std::shared_ptr<T>>& GetChildren() const{
    return children_;
  }

  /**
   * @brief Removes all children
   */
  void Clear(){
    children_.clear();
  }

protected:
  /**
   * @brief ArrangeChildren will place children in specified order and set their parent position.
   * 
   * @note
   *  By default it will not arrange them in any order.
   *  This function will be overriden.
   * 
   * @see component_menu.hpp
   */
	virtual void ArrangeChildren(){
	  std::for_each(children_.begin(), children_.end(), [this](auto& child){ child->SetRelativePosition(this->GetPosition()); });
  }

  /**
   * @brief Call Draw for each child
   * 
   * @param window 
   */
	void DrawChildren(sf::RenderWindow& window) const{
    std::for_each(children_.begin(), children_.end(), [&window=window](const auto& child){ child->Draw(window); });
  }

  /**
   * @brief Call HandleEvent for each child
   * 
   * @param event
   */
	void HandleEventChildren(const sf::Event& event){
    std::for_each(children_.begin(), children_.end(), [&event=event](auto& child){ child->HandleEvent(event); });
  }

  /**
   * @brief Call Update for each child
   */
	void UpdateChildren(){
	  std::for_each(children_.begin(), children_.end(), [](auto& child){ child->Update(); });
  }

  /**
   * @brief container for children.
   */
	std::vector<std::shared_ptr<T>> children_;
};

#endif // __ELEMENT_COLLECTION_H__