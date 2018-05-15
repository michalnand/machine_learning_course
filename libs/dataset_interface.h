#ifndef _DATASET_INTERFACE_H_
#define _DATASET_INTERFACE_H_

#include <string>
#include <vector>
#include <stdio.h>


struct sDatasetItem
{
  std::vector<float> input;
  std::vector<float> output;
};

class DatasetInterface
{
  public:
    std::vector<sDatasetItem> unlabeled, training, testing;

  protected:
    unsigned int width;
    unsigned int height;
    unsigned int channels;

  public:
    DatasetInterface();
    ~DatasetInterface();

    unsigned int get_training_size();
    unsigned int get_testing_size();
    unsigned int get_unlabeled_size();

    unsigned int get_input_size();
    unsigned int get_output_size();

    unsigned int get_width();
    unsigned int get_height();
    unsigned int get_channels();

    sDatasetItem get_training(unsigned int idx);
    sDatasetItem get_random_training();

    sDatasetItem get_testing(unsigned int idx);
    sDatasetItem get_random_testing();

    sDatasetItem get_unlabeled(unsigned int idx);
    sDatasetItem get_random_unlabeled();

    sDatasetItem get_random_training(float noise);
    sDatasetItem get_random_unlabeled(float noise);

    void print_training_item(unsigned int idx);
    void print_testing_item(unsigned int idx);


    unsigned int compare_biggest(unsigned int idx, char *output);

  protected:
    float rnd();

};


#endif
