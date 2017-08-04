#include <stdexcept>

#include "../include/args.hh"

static const ::argp_option option[] =
{
    { "host", 'h', "HOST",
      0, "The name of the machine; localhost by default", 0 },
    { "name", 'n', "NAME",
      0, "The team's name", 0 },
    { "port", 'p', "PORT",
      0, "The port number", 0 },
    { }
};

static const ::argp argp = { option, parser, nullptr, nullptr,
                             nullptr, nullptr, nullptr };

static inline ::error_t
parser_p(const char* arg, ::argp_state* state)
{
    try
    {
        int status = std::stoi(arg);

        if (status < 0)
        {
            throw std::out_of_range { "The port can't be negative" };
        }

        return status;
    }
    catch (const std::invalid_argument&)
    {
        ::argp_error(state, "Invalid port.");
        return -1;
    }
    catch (const std::out_of_range&)
    {
        ::argp_error(state, "Port number is out of range.");
        return -1;
    }
}

::error_t
parser(int key, char* arg, ::argp_state* state)
{
    Argp* args = static_cast<Argp*> (state->input);

    switch (key)
    {
    case 'h':

        args->host_ = arg;
        break;

    case 'n':

        args->name_ = arg;
        break;

    case 'p':

        if ((args->port_ = parser_p(arg, state)) < 0)
        {
            return -1;
        }

        break;

    case ARGP_KEY_END:

        if (args->port_ == -1)
        {
            ::argp_error(state, "The --port option is mandatory.");
            return -1;
        }

        if (args->name_ == nullptr)
        {
            ::argp_error(state, "The --name option is mandatory.");
            return -1;
        }

        break;

    default:

        return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

Argp::Argp(int argc, char* argv[])
    : host_ { "localhost" }, name_ { nullptr }, port_ { -1 }
{
    if (::argp_parse(&argp, argc, argv, 0, nullptr, this) != 0)
    {
        throw std::runtime_error { "Argument parsing failed" };
    }
}

const char* Argp::host() const
{
    return host_;
}

const char* Argp::name() const
{
    return name_;
}

int Argp::port() const
{
    return port_;
}
