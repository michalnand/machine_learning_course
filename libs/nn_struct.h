#ifndef _NN_STRUCT_H_
#define _NN_STRUCT_H_

struct sGeometry
{
  unsigned int w, h, d;
};

/*
struct sTensor
{
  unsigned int w, h, d;
  unsigned int size;
  float *v;
};
*/

struct sHyperparameters
{
  float init_weight_range;
  float learning_rate;
  float lambda;
};


#endif
