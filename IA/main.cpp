#include <cstdlib>
#include <iostream>

#include "../include/args.hh"
#include "../include/protocol.hh"
#include "../include/socket.hh"

static void
zappy(Socket& sock, const char* name)
{
    Protocol protocol (sock, name);
/*    protocol.forward();
    Ai ai {};

    while (protocol.active())
    {
        auto action = ai.best();
        auto answer = protocol.send(action);
        ai.eval(answer);
    }

    ai.save();
*/
}

int main(int argc, char* argv[])
{
    Argp argp (argc, argv);

    const char* host = argp.host();
    const char* name = argp.name();
    int port = argp.port();

    try
    {
        auto sock = connector(host, port);
        zappy(sock, name);
    }
    catch (const std::runtime_error& err)
    {
        std::cerr << "Cannot run zappy on " << host << ":" << port << ": "
                  << err.what()
                  << "."
                  << std::endl;

        return EXIT_FAILURE;
    }
}
