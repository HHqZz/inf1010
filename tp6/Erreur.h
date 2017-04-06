#ifndef ERREUR_H
#define ERREUR_H

using namespace std;
class InvalidValueException : public logic_error
{
public:
    InvalidValueException(string what_arg = "");

};

#endif // ERREUR_H
InvalidValueException::InvalidValueException(string
what_arg) : logic_error(what_arg)
{
}
