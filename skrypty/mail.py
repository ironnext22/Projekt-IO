import gmail
# Twój adres e-mail i hasło
username = 'wiktor.k.2002@gmail.com'
password = 'jzsrhjzaklpwyabo'
def mail1(mail = "X",kod=""):
    client = gmail.GMail('Klinika Dentystyczna<'+username+'>',password)
    msg = gmail.Message('Kod Werfikacyjny',to='pacjent<'+mail+'>',text='Twój kod werfikacyjny: '+kod)
    client.send(msg)

# Adres e-mail odbiorcy
obd = 'wiktor.k.2002@icloud.com'

mail1(obd,"123098")