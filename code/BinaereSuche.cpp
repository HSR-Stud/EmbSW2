left = 0;               // Index des am weitesten links liegenden Kandidaten
right = listLength-1;   // Index des am weitesten rechts liegenden Kandidaten
while (left <= right)
{
  pos = (left + right) / 2; // pos auf die mittlere Position setzen
  if (list[pos] == k)
    return pos;
  if (list[pos] > k)
    right = pos - 1;
  else
    left = pos + 1;
}
return -1; // nicht gefunden
