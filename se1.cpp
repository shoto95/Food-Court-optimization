#include "DxLib.h"
#include "stdio.h"
#include "stdlib.h"
#include "error.h"

int se1(){
	int se=LoadSoundMem("se1.wav");

	PlaySoundMem(se,DX_PLAYTYPE_NORMAL,true);
	
	return 0;
}