#include "classification.h"

#include <classification_compare.h>

#include <math.h>

Classification::Classification(Json::Value &parameters, DatasetInterface *dataset)
{
  this->parameters = parameters;
  this->dataset = dataset;

  sGeometry input_geometry;
  sGeometry output_geometry;

  input_geometry.w = dataset->get_width();
  input_geometry.h = dataset->get_height();
  input_geometry.d = dataset->get_channels();

  output_geometry.w = 1;
  output_geometry.h = 1;
  output_geometry.d = dataset->get_output_size();

  printf("creating batch\n");
  batch = new Batch(input_geometry, output_geometry, dataset->get_training_size());

  for (unsigned int i = 0; i < batch->size(); i++)
  {
    sDatasetItem item = dataset->get_training(i);
    batch->add(item.output, item.input);
  }

  printf("creating network\n");
  nn = new CNN(parameters, input_geometry, output_geometry);

  printf("init done\n");
}

Classification::~Classification()
{
  if (batch != nullptr)
  {
    delete batch;
    batch = nullptr;
  }

  if (nn != nullptr)
  {
    delete nn;
    nn = nullptr;
  }
}


void Classification::main()
{
  unsigned int epoch_count = 1;


  for (unsigned int epoch = 0; epoch < epoch_count; epoch++)
  {
    for (unsigned int i = 0; i < batch->size(); i++)
    {
      batch->set_random();
      nn->learn(batch->get_output(), batch->get_input());
    }
  }

  printf("traing done\n");

}



float Classification::test()
{
  ClassificationCompare compare(dataset->get_output_size());

  std::vector<float> nn_output;
  nn_output.resize(dataset->get_output_size());


  for (unsigned int i = 0; i < dataset->get_testing_size(); i++)
  {
    sDatasetItem ground_truth = dataset->get_testing(i);

    nn->forward(nn_output, ground_truth.input);

    compare.compare(ground_truth.output, nn_output);
  }

  compare.process(true);

  float error = 100.0 - compare.get_success();

  std::string result;
  result = compare.get_text_result();

  printf("%s\n", result.c_str());

  return error;
}
