#include "Bag3.h"
#include "linkedlist.h"

Bag::size_type Bag::erase(const value_type& target)
{
  size_type result = 0;
  node *target_ptr;

  target_ptr = list_search(head_ptr, target);
  while (target_ptr != nullptr)
  {
    target_ptr->set_data(head_ptr->data());
    target_ptr = target_ptr->link();
    target_ptr = list_search(target_ptr, target);
    list_head_remove(head_ptr);
    --sz;
    ++result;
  }
  return result;

