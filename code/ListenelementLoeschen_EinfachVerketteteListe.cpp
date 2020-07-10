void SList::deleteAt(int pos)
{
  assert(pos > 0 && pos <= nr);
  Node* p = pHead; // cursor
  Node* pDel = p; // node to be deleted
  if (pos == 1) // first element
    pHead = pHead->next;
  else
  {
    for (int i = 1; i < pos-1; i++)
    {
      p = p->next;
    }
    pDel = p->next;
    p->next = pDel->next;
  }
  delete pDel;
  --nr;
}
