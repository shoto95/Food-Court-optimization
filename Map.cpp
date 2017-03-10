#include "DxLib.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "Input.h"
#include "Se_play0.h"
#include "Input.h"
extern int food;
int Map(){
 	int x,y,Mouse,Font1,map,se1,se2,a=0,b=0,back_han,ok_han,Ret=0,Cr,irassyai,sina;
	int back[2];
	int ok[2];
	
	map=LoadGraph("white.png");
	se1=LoadSoundMem("go.wav");
	se2=LoadSoundMem("cancel.wav");
	back_han=LoadDivGraph("back.png",2,2,1,208,55,back);
	ok_han=LoadDivGraph("ok.png",2,2,1,112,55,ok);
	Cr=GetColor(0,0,0);
	irassyai=LoadSoundMem("irassyai.wav");
	sina=LoadGraph("sina1.jpg");
	
	ClearDrawScreen();
	PlaySoundMem(irassyai,DX_PLAYTYPE_NORMAL,false);
	while(ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){
		if(CheckSoundMem(food)==0)	
			PlaySoundMem(food,DX_PLAYTYPE_LOOP);
		Mouse=GetMouseInput();
		GetMousePoint(&x,&y);
		
		DrawGraph(0,0,sina,true);

		DrawGraph( 620,568,ok[0],false);
		DrawGraph( 200,568,back[0],false);
		
		//OKボタン				
		if(x >= 620 && x <= 732 && y >= 568 && y <= 623){
			if(a == 0){
				a=Se();
			}		
			if(Mouse & MOUSE_INPUT_LEFT){
				PlaySoundMem(se1,DX_PLAYTYPE_NORMAL);
				WaitTimer(1000);
				ClearDrawScreen();
				if(CheckSoundMem(food))
					StopSoundMem(food);
				Ret=Input();
				if(Ret == 1){ 
					return 1;
				}
			}	
		}
		else
			a=0;		
		
		//BACKボタン
		if(x >= 200 && x<= 408 && y>= 568 && y<= 623){
			if(b == 0){
				b=Se();
			}		
			if(Mouse & MOUSE_INPUT_LEFT){
				PlaySoundMem(se2,DX_PLAYTYPE_NORMAL,false);
				WaitTimer(1000);
				return 0;
			}
		}
		else
			b=0;
	}
}
	