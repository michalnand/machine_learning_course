#include <stdio.h>
#include <stdlib.h>

#include <dataset_interface.h>
#include <dataset_mnist_tiny.h>
#include <cnn.h>

#include <classification.h>

int main()
{
  DatasetInterface *dataset;
  dataset = new DatasetMnistTiny( "/home/michal/dataset/mnist_tiny/training.txt",
                                  "/home/michal/dataset/mnist_tiny/testing.txt");

  Json::Value parameters;
  Classification classification(parameters, dataset);

  delete dataset;
  printf("program done\n");
}
