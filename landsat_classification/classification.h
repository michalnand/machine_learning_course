#ifndef _CLASSIFICATION_H_
#define _CLASSIFICATION_H_

#include <dataset_interface.h>
#include <batch.h>

#include <cnn.h>
#include <log.h>

class Classification
{
  private:
    Json::Value parameters;
    DatasetInterface *dataset;
    Batch *batch;
    INN *nn;


  public:
    Classification(Json::Value &parameters, DatasetInterface *dataset);
    ~Classification();

    void main();
    float test();

};

#endif
