#include "../includes/Emails.h"
using namespace std;

Email:: Email(string sender, string recipient, string subject, string text)
{
    this->sender = sender;
    this->recipient = recipient;
    this->subject = subject;
    this->text = text;
}

string Email:: getSender()
{
    return sender;
}