int naivePSearch(const char* text, const char* pattern)
{
  int i;
  int j;

  for(i=0; text[i]; ++i)
  {
    for(j=0; pattern[j]; ++j)
    {
      if(pattern[j] != text[i+j])
        break;
    }
    if(pattern[j] == 0)  // pattern found
      return i;
  }
  return -1  // pattern not found
}
