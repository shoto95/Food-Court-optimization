#include "DxLib.h"
#include "stdio.h"
#include "stdlib.h"
#include "error.h"

int Se2(){
	int se2=LoadSoundMem("go.wav");

	PlaySoundMem(se2,DX_PLAYTYPE_NORMAL,true);
	
	return 1;
}