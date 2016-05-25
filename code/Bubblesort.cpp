for (int i = listLength-1; i > 0; --i)
{
  for (int j = 1; j <= i; ++j)
  {
    if (data[j-1] > data[j])
      swap(j-1, j);
  }
}