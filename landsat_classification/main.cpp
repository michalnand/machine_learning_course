#include <stdio.h>
#include <stdlib.h>

#include <dataset_interface.h>
#include <dataset_landsat.h>
#include <cnn.h>

#include <batch.h>

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

  delete dataset;

  printf("program done\n");
}
