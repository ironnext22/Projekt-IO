
#ifndef PROJEKT_IO_MAILBOX_H
#define PROJEKT_IO_MAILBOX_H
#include "../includes/Emails.h"
#include <string>
#include <vector>
using namespace std;

class Mailbox
{
public:
    Mailbox();
    void addmessage(Email newmessage);
    vector<Email> getmessage(string sender);
private:
    vector<Email> messages;
};

#endif //PROJEKT_IO_MAILBOX_H
