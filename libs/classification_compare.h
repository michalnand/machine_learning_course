#ifndef _CLASSIFICATION_COMPARE_H_
#define _CLASSIFICATION_COMPARE_H_


#include <string>
#include <vector>

#include "json_config.h"

class ClassificationCompare
{
  private:
    unsigned int classes_count;
    std::vector<std::vector<unsigned int>> confusion_matrix;
    std::vector<float> class_success_rate;

    unsigned int sum_all, sum_correct;

    float succes_result;

    std::vector<float> summary_result;
    std::string text_result;
    Json::Value json_result;

  public:
    ClassificationCompare();
    ClassificationCompare(unsigned int classes_count_);

    ~ClassificationCompare();

    void compare(std::vector<float> &required_value, std::vector<float> &output_value);
    void compare(float *required_value, float *output_value);
    void set_classes_count(unsigned int classes_count);


    float process(bool percent_result);
    float get_success();

    std::vector<float> get_summary_result()
    {
      return summary_result;
    }

    std::string get_text_result()
    {
      return text_result;
    }

    Json::Value get_json_result()
    {
      return json_result;
    }

    void save_text_file(std::string file_name);
    void save_json_file(std::string file_name);

  private:
    std::vector<float> process_summary_result();
    std::string process_text_result();
    Json::Value process_json_result();

    unsigned int argmax(float *v, unsigned int size);


};

#endif
