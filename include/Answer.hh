#ifndef ANSWER_HH_
# define ANSWER_HH_

class Answer
{
    public:
    enum class Type
    {
        FORWARD,
        LEFT,
        RIGHT,
        LOOK,
        INVENTORY,
        BROADCAST,
        CONNECT_NBR,
        FORK,
        EJECT,
        TAKE,
        SET,
        INCANTATION
    };

    using Look = std::vector<Tile>;
    using Inventory = Tile;
    using Connect_nbr = unsigned int;
    using Eject = bool;
    using Take = bool;
    using Set = bool;
    using Incantation = bool;

    union
    {
        Look look;
        Inventory inventory;
        Connect_nbr connect_nbr;
        Eject eject;
        Take take;
        Set set;
        Incantation incantation;
    } value;

    Type tag;

    Answer();
    ~Answer();    
};

#endif /* ! ANSWER_HH_ */
