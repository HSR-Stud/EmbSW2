void DList::deleteAt(int pos)
{
  assert(pos > 0 && pos <= nr);
  Node* pDel = nodePtr(pos); // node to be deleted
  assert (pDel != nullptr);
  if (pos == 1) // first element
    pHead = pHead->next;
  else
  {
    pDel->prev->next = pDel->next;
  }
  if (pDel->next != nullptr) // not last element in list
    pDel->next->prev = pDel->prev;
  delete pDel;
  --nr;
}
