#include "DxLib.h"
#include "stdio.h"
#include "stdlib.h"
#include "error.h"

int Se(){
	int se1=LoadSoundMem("se1.wav");

	PlaySoundMem(se1,DX_PLAYTYPE_NORMAL,true);
	
	return 1;
}