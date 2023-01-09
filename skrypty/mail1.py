import gmail
# Twój adres e-mail i hasło
username = 'gabinetdentystycznyiodent@gmail.com'
password = 'ppbrnlloepwfgjau'
def mail1(mail = "X",kod=""):
    client = gmail.GMail('Klinika Dentystyczna<'+username+'>',password)
    msg = gmail.Message('Kod Werfikacyjny',to='pacjent<'+mail+'>',text='Twój kod werfikacyjny: '+kod)
    client.send(msg)

# Adres e-mail odbiorcy
obd = 'wiktor.k.2002@icloud.com'
obd = open("mail.txt","r")
kod = open("kod.txt","r")
mail1(obd.read(),kod.read())