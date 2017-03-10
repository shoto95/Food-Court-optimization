#-------------------------------------------------------
# BCC Developer 1.2.21
# Copyright (C) 2003 jun_miura@hi-ho.ne.jp
#-------------------------------------------------------
.autodepend
CC=bcc32
RC=brc32
CFLAG=-W  -3 -Od -w- -AT -pc -H- -k -b -v -y  -DDEBUG
OUTDIR=-nDebug
CINCS=
TARGET=Debug\FoodCoart.exe
SRC1=C:\Users\kk\Desktop\フードコート(完成品)\フードコート\age.cpp
OBJ1=Debug\age.obj
SRC2=C:\Users\kk\Desktop\フードコート(完成品)\フードコート\Result.cpp
OBJ2=Debug\Result.obj
SRC3=C:\Users\kk\Desktop\フードコート(完成品)\フードコート\Map.cpp
OBJ3=Debug\Map.obj
SRC4=C:\Users\kk\Desktop\フードコート(完成品)\フードコート\Se_play0.cpp
OBJ4=Debug\Se_play0.obj
SRC5=C:\Users\kk\Desktop\フードコート(完成品)\フードコート\Se_play3.cpp
OBJ5=Debug\Se_play3.obj
SRC6=C:\Users\kk\Desktop\フードコート(完成品)\フードコート\Se_play2.cpp
OBJ6=Debug\Se_play2.obj
SRC7=C:\Users\kk\Desktop\フードコート(完成品)\フードコート\main.cpp
OBJ7=Debug\main.obj
SRC8=C:\Users\kk\Desktop\フードコート(完成品)\フードコート\Se_play1.cpp
OBJ8=Debug\Se_play1.obj
SRC9=C:\Users\kk\Desktop\フードコート(完成品)\フードコート\ryori.cpp
OBJ9=Debug\ryori.obj
SRC10=C:\Users\kk\Desktop\フードコート(完成品)\フードコート\Input.cpp
OBJ10=Debug\Input.obj
SRC11=C:\Users\kk\Desktop\フードコート(完成品)\フードコート\Wait.cpp
OBJ11=Debug\Wait.obj
RC1=C:\Users\kk\Desktop\フードコート(完成品)\フードコート\FoodCoart.rc
RES1=Debug\FoodCoart.res

TARGET: $(TARGET)

$(TARGET): $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) $(OBJ7) $(OBJ8) $(OBJ9) $(OBJ10) $(OBJ11) $(RES1)
    $(CC) $(CFLAG) -e$(TARGET) $(OBJ1) $(OBJ2) $(OBJ3) $(OBJ4) $(OBJ5) $(OBJ6) $(OBJ7) $(OBJ8) $(OBJ9) $(OBJ10) $(OBJ11)
    $(RC) $(RES1) $(TARGET)

$(OBJ1): $(SRC1)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC1)

$(OBJ2): $(SRC2)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC2)

$(OBJ3): $(SRC3)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC3)

$(OBJ4): $(SRC4)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC4)

$(OBJ5): $(SRC5)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC5)

$(OBJ6): $(SRC6)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC6)

$(OBJ7): $(SRC7)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC7)

$(OBJ8): $(SRC8)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC8)

$(OBJ9): $(SRC9)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC9)

$(OBJ10): $(SRC10)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC10)

$(OBJ11): $(SRC11)
    $(CC) $(CFLAG) $(OUTDIR) $(CINCS) -c $(SRC11)

$(RES1): $(RC1)
    $(RC) $(RESINCS) -r -fo$(RES1) $(RC1)
