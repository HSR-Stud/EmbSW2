void SList::insertAt(int pos, double val)
{
  assert(pos >= 0);
  Node* pEl = new Node;
  pEl->value = val;
  if (pos != 0) // not at head
  {
    Node* p = nodePtr(pos);
    assert(p != 0);
    pEl->next = p->next;
    p->next = pEl;
  }
  else // insert at head
  {
    pEl->next = pHead;
    pHead = pEl;
  }
  ++nr;
}