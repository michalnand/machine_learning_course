#ifndef _I_LAYER_H_
#define _I_LAYER_H_

#include "nn_struct.h"
#include "tensor.h"
#include <string>

class ILayer
{
  protected:
    sGeometry input_geometry;
    sGeometry kernel_geometry;
    sGeometry output_geometry;
    sHyperparameters hyperparameters;

  public:
    Tensor w, bias;
    Tensor output, error;

  public:
    ILayer( sGeometry input_geometry,
            sGeometry kernel_geometry,
            sHyperparameters hyperparameters);

    virtual ~ILayer();

    sGeometry get_input_geometry();
    sGeometry get_kernel_geometry();
    sGeometry get_output_geometry();

    unsigned int get_input_size();
    unsigned int get_output_size();

    virtual void forward(Tensor &input);
    virtual void backward(Tensor &input, Tensor &error_back);

    void save(std::string file_name_prefix);
    void load(std::string file_name_prefix);

    void save_image(std::string file_name);

    void decrease_learning_rate(float ratio);


    virtual bool has_weights()
    {
      return false;
    }

  protected:
    void print_info(std::string layer_type = "FC");
};


#endif
