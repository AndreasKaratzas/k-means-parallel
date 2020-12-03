void optimize(void)
{
  int i, j, k, cluster;
  long double distance;

#pragma omp parallel num_threads(2)
  {
#pragma omp master
    {
      memset(Classes, 0, Nc * sizeof(Classes[0]));
    }
#pragma omp single
    {
      memset(new_Center, 0.0, Nc * Nv * sizeof(new_Center[0][0]));
    }
  }

  for (i = 0; i < N; i += 1)
  {
    distance = 0.0;
    cluster = -1;

    long double min = DBL_MAX;

    for (j = 0; j < Nc; j += 1)
    {
#pragma omp parallel for num_threads(NUM_THR) reduction(+ \
                                          : distance)
      for (k = 0; k < Nv; k += 1)
      {
        distance += (Vec[i][k] - old_Center[j][k]) *
                    (Vec[i][k] - old_Center[j][k]);
      }
      if (distance < min)
      {
        min = distance;
        cluster = j;
      }
    }

    Classes[cluster] += 1;
#pragma omp parallel for num_threads(NUM_THR) reduction(+ \
                                          : new_Center[cluster])
    for (k = 0; k < Nv; k += 1)
    {
      new_Center[cluster][k] += Vec[i][k];
    }
  }
}