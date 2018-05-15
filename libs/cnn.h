#ifndef _CNN_H_
#define _CNN_H_

#include <inn.h>
#include <json_config.h>
#include <layers/ilayer.h>


class CNN: public INN
{
  protected:
    Json::Value json_config;

    std::vector<ILayer*> layers;

  public:
    CNN(std::string json_file_name, sGeometry input_geometry_ = {0, 0, 0}, sGeometry output_geometry_ = {0, 0, 0});
    CNN(Json::Value &json_config, sGeometry input_geometry_ = {0, 0, 0}, sGeometry output_geometry_ = {0, 0, 0});
    ~CNN();

    void init(Json::Value &json_config, sGeometry input_geometry_ = {0, 0, 0}, sGeometry output_geometry_ = {0, 0, 0});

    void forward(Tensor &output, Tensor &input);
    void learn(Tensor &required_output, Tensor &input);
    void learn_single_output(float required_output, Tensor &input, unsigned int output_idx);

    void save(std::string file_name_prefix);

  protected:
    void learn_from_error();
};

#endif
