#ifndef _I_ENVIRONMENT_H_
#define _I_ENVIRONMENT_H_

#include <vector>

struct sEnvironmentGeometry
{
  unsigned w, h, d;
};

class IAgent;
//#include "iagent.h"

class IEnvironment
{

  protected:

    std::vector<float>    state;
    sEnvironmentGeometry  geometry;

    unsigned int actions_count;
    float reward, score;

  public:

    IEnvironment();
    virtual ~IEnvironment();

    std::vector<float>& get_state();

    float get_reward();
    float get_score();

    sEnvironmentGeometry get_geometry();
    unsigned int get_state_size();
    unsigned int get_actions_count();

  public:
    virtual void reset();
    virtual void do_action(unsigned int action_id, IAgent *agent_id = nullptr);
    virtual void print();

  protected:
    void init_state(sEnvironmentGeometry  geometry);
};


#endif
