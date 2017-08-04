#ifndef INCLUDED_ARGS_HH
#define INCLUDED_ARGS_HH

#include <argp.h>

extern "C" const char* argp_program_bug_address;
extern "C" const char* argp_program_version;

class Argp
{
    const char* host_;
    const char* name_;
    int port_;

    friend ::error_t parser(int key, char* arg, ::argp_state* state);

public:

    Argp(int argc, char* argv[]);
    ~Argp() = default;

    Argp(const Argp&) = delete;
    Argp(Argp&&) = default;

    Argp& operator=(const Argp&) = delete;
    Argp& operator=(Argp&&) = default;

    const char* host() const;
    const char* name() const;
    int port() const;
};

::error_t parser(int key, char* arg, ::argp_state* state);

#endif
