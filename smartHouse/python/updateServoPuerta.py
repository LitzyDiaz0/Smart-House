import serial, time, mysql.connector

rasp = serial.Serial('/dev/ttyACM1', 9600, timeout = 1)#conexion serial
rasp.flushInput()


def update_servo_puerta(estado):
    if estado == "on":
        query = "UPDATE componentes SET estado = 'on', fecha = CURRENT_DATE, hora = CURRENT_TIME WHERE id = 8"
    elif estado == "off":
        query = "UPDATE componentes SET estado = 'off', fecha = CURRENT_DATE, hora = CURRENT_TIME WHERE id = 8"

    try:
        con = mysql.connector.connect(host='localhost',user='root',password='12345',database='smarthouse')  #conexion con mysq
        cursor = con.cursor()
        cursor.execute(query)
        
        con.commit()
        con.close()
    except importError as error:
        print(error)

def get_servo_data():
    query = "SELECT * FROM componentes WHERE id = 8"
    
    try:
        con = mysql.connector.connect(host='localhost',user='root',password='12345',database='smarthouse')  #conexion con mysq
        cursor = con.cursor()
        cursor.execute(query)
        
        print(cursor.fetchone())
        con.close()
    except KeyboardInterrupt:
        print('an error has ocurred')

while True:
    ser = rasp.read(20)
    line = ser.decode("utf-8").strip()
    #print(line,'\n')
    if line == "on":
        print(line,'\n')
        update_servo_puerta("on")
        get_servo_data()
    elif line == "off":
        print(line,'\n')
        update_servo_puerta("off")
        get_servo_data()
#results = query.fetchone()

#se imprime results
#print(results)