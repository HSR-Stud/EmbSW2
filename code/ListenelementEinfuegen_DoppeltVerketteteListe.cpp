void DList::insertAt(int pos, double val)
{
  assert(pos >= 0);
  Node* pEl = new Node;
  pEl->value = val;
  if (pos != 0) // not at head
  {
    Node* p = nodePtr(pos);
    assert(p != nullptr);
    pEl->next = p->next;
    pEl->prev = p;
    p->next = pEl;
  }
  else // insert at head
  {
    pEl->next = pHead;
    pEl->prev = nullptr;
    pHead = pEl;
  }
  if (pEl->next != nullptr) // not last element in list
  pEl->next->prev = pEl;
  ++nr;
}
