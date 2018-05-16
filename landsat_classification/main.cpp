#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <dataset_interface.h>
#include <dataset_landsat.h>
#include <cnn.h>

#include <batch.h>
#include <classification_compare.h>


void train(CNN &nn, Batch &batch)
{
  unsigned epoch_count = 100;

  for (unsigned int epoch = 0; epoch < epoch_count; epoch++)
  {
    for (unsigned int i = 0; i < batch.size(); i++)
    {
      batch.set_random();
      nn.learn(batch.get_output(), batch.get_input());
    }

    std::cout << "training done " << epoch*100.0/epoch_count << "\n";
  }
}


void test(INN *nn, DatasetInterface *dataset)
{
  std::vector<float> nn_output;
  nn_output.resize(dataset->get_output_size());

  ClassificationCompare comparator(dataset->get_output_size());

  for (unsigned int i = 0; i < dataset->get_testing_size(); i++)
  {
    sDatasetItem item = dataset->training[i];

    nn->forward(nn_output, item.input);

    comparator.compare(item.output, nn_output);
  }

  comparator.process(true);

  std::cout << comparator.get_text_result();

}

int main()
{
  DatasetInterface *dataset;
  dataset = new DatasetLANDSAT("/home/michal/dataset/landsat/sat.trn",
                               "/home/michal/dataset/landsat/sat.tst");

  sGeometry input_geometry, output_geometry;

  input_geometry.w = dataset->get_width();
  input_geometry.h = dataset->get_height();
  input_geometry.d = dataset->get_channels();

  output_geometry.w = 1;
  output_geometry.h = 1;
  output_geometry.d = dataset->get_output_size();

  Batch batch(input_geometry,
              output_geometry,
              dataset->get_training_size());

  for (unsigned int i = 0; i < batch.size(); i++)
  {
    sDatasetItem item = dataset->training[i];
    batch.add(item.output, item.input);
  }

  CNN nn("network_parameters.json",
          input_geometry,
          output_geometry);

  train(nn, batch);

  test(&nn, dataset);

  delete dataset;

  printf("program done\n");
}
