int k; 	// Index des kleinsten Elementes 
        // im nicht sortierten Teil

for (int i = 0; i < listLength-1; ++i)
{
  k = i;
  for (int j = i+1; j < listLength; ++j)
  {
    if (data[j] < data[k])
    k = j;
  }
  swap(i, k);
}