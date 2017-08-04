#ifndef AI_HH_
# define AI_HH_

#include "Action.hh"

class Ai
{
    public:
    Ai();
    ~Ai() = default;
    
    Ai& operator=(const Ai&) = delete;
    Ai& operator=(Ai&&) = default;

    Action  best();
    void eval(const Answer&);
    void save();
};

#endif 
