#include <stdio.h>
#include <stdlib.h>

#include <dataset_interface.h>
#include <dataset_mnist_tiny.h>
#include <cnn.h>


int main()
{
  DatasetInterface *dataset;
  dataset = new DatasetMnistTiny( "/home/michal/dataset/mnist_tiny/training.txt",
                                  "/home/michal/dataset/mnist_tiny/testing.txt");


  delete dataset;
  printf("program done\n");
}
