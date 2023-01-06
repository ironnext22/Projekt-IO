#ifndef PROJEKT_IO_EMAILS_H
#define PROJEKT_IO_EMAILS_H
#include <string>
#include <vector>
using namespace std;

class Email
{
public:
    Email();
    Email(string sender, string recipient, string subject, string text);
    string getSender();
    string getSubject();
    string getRecipient();
    string getText();
private:
    string sender;
    string recipient;
    string subject;
    string text;
};

#endif //PROJEKT_IO_EMAILS_H
