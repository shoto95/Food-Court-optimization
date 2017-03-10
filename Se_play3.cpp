#include "DxLib.h"
#include "stdio.h"
#include "stdlib.h"
#include "error.h"

int Se3(){
	int se3=LoadSoundMem("cancel.wav");

	PlaySoundMem(se3,DX_PLAYTYPE_NORMAL,true);
	
	return 1;
}