Import("env")
import serial

def before_upload(source, target, env):
    print("Enable onstep uploading")    
    ser = serial.Serial(env.subst("$UPLOAD_PORT"))
    msg = ":hF#:ESPFLASH#\r\n"
    ser.write(msg.encode())
    ser.flush()
    ser.close()

env.AddPreAction("upload", before_upload)