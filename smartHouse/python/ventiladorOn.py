import serial, time

arduino = serial.Serial('/dev/ttyACM0',9600, timeout = 1)
time.sleep(1)
for a in range(2):
    try:
        msg = "ventiladorOn\n"
        arduino.write(msg.encode("utf-8"));
        time.sleep(1)
    except KeyboardInterrupt:
        break