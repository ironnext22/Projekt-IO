// Create a new instance of MailMessage class
System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();
System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>();

// Set subject of the message, Html body and sender information
message->set_Subject(u"New message created by Aspose.Email for .NET");
message->set_From(System::MakeObject<MailAddress>(L"from@domain.com", L"Sender Name", false));
message->set_Body(System::String(u"<b>This line is in bold.</b> <br/> <br/>") + u"<font color=blue>This line is in blue color</font>");
message->set_BodyEncoding(System::Text::Encoding::get_ASCII());
// Add TO recipients and Add CC recipients
message->get_To()->Add(System::MakeObject<MailAddress>(L"to1@domain.com", L"Recipient 1", false));
message->get_To()->Add(System::MakeObject<MailAddress>(L"to2@domain.com", L"Recipient 2", false));
message->get_CC()->Add(System::MakeObject<MailAddress>(L"cc1@domain.com", L"Recipient 3", false));

// Specify your mailing host server, Username, Password, Port # and Security option
client->set_Host(u"mail.server.com");
client->set_Username(u"username");
client->set_Password(u"password");
client->set_Port(587);
client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::SSLExplicit);

try
{
// Send this message
client->Send(message);
}
catch (System::Exception& ex)
{

}

// Create an instance of MailMessage class
System::SharedPtr<MailMessage> message = System::MakeObject<MailMessage>();

// From and To field
message->set_From(u"sender@sender.com");
message->get_To()->Add(u"receiver@receiver.com");

System::SharedPtr<AlternateView> alternate;

// Create an instance of AlternateView to view an email message using the content specified in the string
alternate = AlternateView::CreateAlternateViewFromString(u"This is the alternate Text");

// Add alternate text
message->get_AlternateViews()->Add(alternate);

// Create an instance of SmtpClient Class
System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>();

// Specify your mailing host server, user name, mail password and Port #
client->set_Host(u"smtp.server.com");
client->set_Username(u"Username");
client->set_Password(u"Password");
client->set_Port(25);
try
{
// Client->Send will send this message
client->Send(message);
}
catch (System::Exception& ex)
{
System::Diagnostics::Trace::WriteLine(System::ObjectExt::ToString(ex));
}

