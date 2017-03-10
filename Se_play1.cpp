#include "DxLib.h"
#include "stdio.h"
#include "stdlib.h"
#include "error.h"

int Se1(){
	int se1=LoadSoundMem("radio.wav");

	PlaySoundMem(se1,DX_PLAYTYPE_NORMAL,true);
	
	return 1;
}