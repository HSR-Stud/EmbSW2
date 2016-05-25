void quickSort(int leftBound, int rightBound)
{
  int left = leftBound;                // Index der linken Grenze
  int right = rightBound;              // Index der rechten Grenze
  int pivot = data[(left+right) / 2];  // Gewähltes Element in der Mitte
  do
  {
    while (data[left] < pivot)
      ++left;
    while (data[right] > pivot)
      --right;

    if (left <= right)
    {
      if (left < right)
        swap(left, right);
      ++left;
      --right;
    }
  } while (left <= right);

  if (leftBound < right)
    quickSort(leftBound, right);
  if (rightBound > left)
    quickSort(left, rightBound);
}