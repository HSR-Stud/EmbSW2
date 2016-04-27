void DList::insertAt(int pos, double val)
{
  assert(pos >= 0);
  Node* pEl = new Node;
  pEl->value = val;
  if (pos != 0) // not at head
  {
    Node* p = nodePtr(pos);
    assert(p != 0);
    pEl->next = p->next;
    pEl->prev = p;
    p->next = pEl;
  }
  else // insert at head
  {
    pEl->next = pHead;
    pEl->prev = 0;
    pHead = pEl;
  }
  if (pEl->next != 0) // not last element in list
  pEl->next->prev = pEl;
  ++nr;
}