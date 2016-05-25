int buf; // Buffer

for (int i = 1; i < listLength; ++i)
{
  buf = data[i];
  int j = i;
  while (j > 0 && buf < data[j-1])
  {
    data [j] = data [j-1];
    j = j-1;
  }
  data[j] = buf;
}