#include "DxLib.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "error.h"
#include "Result.h"

int Wait(){
	int back,wait,i;
	int dot[4];
	
	back=LoadGraph("white.png");
	wait=LoadGraph("wait.png");
	dot[1]=LoadGraph("dot0.png");
	dot[2]=LoadGraph("dot1.png");
	dot[3]=LoadGraph("dot2.png");
	
	while(ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0){
		DrawGraph(0,0,back,true);
		DrawGraph(100,300,wait,true);
		ClearDrawScreen();
		Result();
	}
	
}