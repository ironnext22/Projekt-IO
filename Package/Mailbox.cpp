#include "../includes/Mailbox.h"
using namespace std;

void Mailbox:: addmessage (Email newmessage)
{
    messages.push_back(newmessage);
}

vector <Email> Mailbox:: getmessage(string sender)
{
    vector<Email> temp;
    for(int i=0; i<messages.size();i++)
    { if(messages[i].getSender()==sender)
        {
            temp.push_back(messages[i]);
        }
    }
    return temp;
}