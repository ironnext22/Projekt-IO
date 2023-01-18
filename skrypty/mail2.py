import gmail
# Twój adres e-mail i hasło
username = 'gabinetdentystycznyiodent@gmail.com'
password = 'ppbrnlloepwfgjau'
def mail1(mail = "X",data=""):
    client = gmail.GMail('Klinika Dentystyczna<'+username+'>',password)
    msg = gmail.Message('Wizyta',to='pacjent<'+mail+'>',text='Dzień dobry,\nPrzypominamy o wizycie w dniu: '+data+
    '\nProszę o informacię zwrotną z potwierdzeniem wizyty\n\nProzrawiamy,\nZespół IO-Dent')
    client.send(msg)

# Adres e-mail odbiorcy
obd = 'wiktor.k.2002@icloud.com'
obd = open("mail2.txt","r")
data = open("data.txt","r")
mail1(obd.read(),data.read())

