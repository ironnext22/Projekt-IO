import gmail
# Twój adres e-mail i hasło
username = 'gabinetdentystycznyiodent@gmail.com'
password = 'ppbrnlloepwfgjau'
def mail1(mail = "X",data=""):
    client = gmail.GMail('Klinika Dentystyczna<'+username+'>',password)
    msg = gmail.Message('Wizyta',to='pacjent<'+mail+'>',text='Przypominamy o wizycie w dniu: '+data)
    client.send(msg)

# Adres e-mail odbiorcy
obd = 'wiktor.k.2002@icloud.com'
obd = open("mail2.txt","r")
data = open("data.txt","r")
mail1(obd.read(),data.read())