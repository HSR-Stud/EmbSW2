do
{
  v1 = 2 * static_cast<double> (rand()) / RAND_MAX - 1.0;
  v2 = 2 * static_cast<double> (rand()) / RAND_MAX - 1.0;
  s = v1 * v1 + v2 * v2;
} while (s >= 1.0 || s == 0.0);
double temp = sqrt(-2.0 * log(s) / s);
w1 = (v1 * temp * sdev);
w2 = (v2 * temp * sdev);
return lround(sqrt(w1 * w1 + w2 * w2));