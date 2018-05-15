#ifndef _TENSOR_H_
#define _TENSOR_H_


#include "nn_struct.h"
#include "network_config.h"
#include <vector>
#include <string>

unsigned int get_tensor_allocated();

struct sTensor8Bit
{
  float scale;
  std::vector<char> v;
};

class Tensor
{
  public:
    // sGeometry geometry;
    unsigned int w, h, d;
    unsigned int size;
    float *v;

  public:

    Tensor();
    Tensor(unsigned int d);
    Tensor(unsigned int w, unsigned int h, unsigned int d);
    Tensor(sGeometry geometry);
    Tensor(Tensor &tensor);

    ~Tensor();

    void init(unsigned int d);
    void init(unsigned int w, unsigned int h, unsigned int d);
    void init(sGeometry geometry);
    void uninit();

    void clear();

    void set_from_host(float *host_src);
    void set_from_host(std::vector<float> &host_src);

    void set_to_host(float *host_dest);
    void set_to_host(std::vector<float> &host_dest);

    void set_const(float value);
    void set_random(float range);
    void add_noise(float level);

    void set_element(float value, unsigned int x, unsigned int y = 0, unsigned int z = 0);

    void add(Tensor &rhs);
    void add(Tensor &rhs_a, Tensor &rhs_b);

    void sub(Tensor &rhs);
    void sub(Tensor &rhs_a, Tensor &rhs_b);

    void mul(float value);
    void copy(Tensor &rhs);

    void print();

    void save(std::string file_name);
    void load(std::string file_name);

    float get_rms(Tensor &rhs);
    float get_euclidean_size();

    void sparse(float lambda);

    sTensor8Bit get_8_bit();
    void set_from_8_bit(sTensor8Bit &init_8_bit);

    bool check_valid();


  public:
    Tensor& operator=(Tensor &rhs)
    {
      copy(rhs);
      return *this;
    }

    Tensor& operator=(float *host_src)
    {
      set_from_host(host_src);
      return *this;
    }

    Tensor& operator=(std::vector<float> &host_src)
    {
      set_from_host(host_src);
      return *this;
    }
};

#endif
