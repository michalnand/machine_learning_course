#ifndef _I_NN_H_
#define _I_NN_H_

#include <vector>
#include <string>
#include <stdio.h>

#include <layer_type.h>
#include <tensor.h>
#include <network_config.h>
#include <nn_struct.h>

class INN
{
  protected:
    Tensor nn_input, nn_output, nn_required_output, nn_error;
    sGeometry input_geometry, output_geometry;

  public:
    INN();
    virtual ~INN();



    virtual void forward(float *output, float *input);
    virtual void forward(std::vector<float> &output, std::vector<float> &input);
    virtual void forward(Tensor &output, Tensor &input);

    virtual void learn(Tensor &required_output, Tensor &input);

    virtual void learn_single_output(float required_output, float *input, unsigned int output_idx);
    virtual void learn_single_output(float required_output, std::vector<float> &input, unsigned int output_idx);
    virtual void learn_single_output(float required_output, Tensor &input, unsigned int output_idx);


    sGeometry get_input_geometry();
    sGeometry get_output_geometry();

    unsigned int get_input_size();
    unsigned int get_output_size();

    virtual void save(std::string file_name_prefix);

    virtual void print();
};


#endif
