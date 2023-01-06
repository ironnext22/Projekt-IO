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

// Create SmtpClient as client and specify server, port, user name and password
System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>(u"mail.server.com", 25, u"Username", u"Password");

// Create instances of MailMessage class and Specify To, From, Subject and Message
System::SharedPtr<MailMessage> message1 = System::MakeObject<MailMessage>(u"msg1@from.com", u"msg1@to.com", u"Subject1", u"message1, how are you?");
System::SharedPtr<MailMessage> message2 = System::MakeObject<MailMessage>(u"msg1@from.com", u"msg2@to.com", u"Subject2", u"message2, how are you?");
System::SharedPtr<MailMessage> message3 = System::MakeObject<MailMessage>(u"msg1@from.com", u"msg3@to.com", u"Subject3", u"message3, how are you?");

// Create an instance of MailMessageCollection class
System::SharedPtr<MailMessageCollection> manyMsg = System::MakeObject<MailMessageCollection>();
manyMsg->Add(message1);
manyMsg->Add(message2);
manyMsg->Add(message3);

// Bulk send
try
{
// Send Messages
client->Send(manyMsg);
}
catch (System::Exception& ex)
{
System::Diagnostics::Trace::WriteLine(System::ObjectExt::ToString(ex));
}

try
{
// Email file path
System::String emlFileName = u"Message.eml";
// A TNEF Email

// Load from eml
System::SharedPtr<MailMessage> eml1 = MailMessage::Load(emlFileName, System::MakeObject<EmlLoadOptions>());
eml1->set_From(u"somename@gmail.com");
eml1->get_To()->Clear();
eml1->get_To()->Add(System::MakeObject<MailAddress>(u"first.last@test.com"));
eml1->set_Subject(u"With PreserveTnef flag during loading");
eml1->set_Date(System::DateTime::get_Now());
System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>(u"smtp.gmail.com", 587, u"somename", u"password");
client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
client->set_UseTnef(true);
// Use this flag to send as TNEF
client->Send(eml1);
}
catch (System::Exception& ex)
{
// catch exception
}

// Create SmtpClient as client and specify server, port, user name and password
System::SharedPtr<SmtpClient> client = System::MakeObject<SmtpClient>(u"mail.server.com", 25, u"Username", u"Password");

// Create instances of MailMessage class and Specify To, From, Subject and Message
System::SharedPtr<MailMessage> message1 = System::MakeObject<MailMessage>(u"msg1@from.com", u"msg1@to.com", u"Subject1", u"message1, how are you?");
System::SharedPtr<MailMessage> message2 = System::MakeObject<MailMessage>(u"msg1@from.com", u"msg2@to.com", u"Subject2", u"message2, how are you?");
System::SharedPtr<MailMessage> message3 = System::MakeObject<MailMessage>(u"msg1@from.com", u"msg3@to.com", u"Subject3", u"message3, how are you?");

// Create an instance of MailMessageCollection class
System::SharedPtr<MailMessageCollection> manyMsg = System::MakeObject<MailMessageCollection>();
manyMsg->Add(message1);
manyMsg->Add(message2);
manyMsg->Add(message3);

// Bulk send
try
{
// Send Messages
client->Send(manyMsg);
}
catch (System::Exception& ex)
{
System::Diagnostics::Trace::WriteLine(System::ObjectExt::ToString(ex));
}