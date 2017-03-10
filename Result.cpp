#include "DxLib.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "Result.h"
#include "Se_play0.h"
#include "Result.h"
#include "Map.h"
#include "ryori.h"

int Result(){
	int i,x,y,x1,y1,Mouse,Wheel,Img1,back1,bgm1;
	int strCr,boxCr,se1,se2,se3,zahyou,Cr,Cr1,MouseX,MouseY,a=0,b=0;
	int title1,title2,copy,korega,obon,arigatou;
	
	korega=LoadGraph("korega.png");
	back1=LoadGraph("white.png");
	obon=LoadGraph("obon.jpg");
	arigatou=LoadSoundMem("arigatou.wav");
	
	PlaySoundMem(arigatou,DX_PLAYTYPE_NORMAL,false);
	while(ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){
		Mouse = GetMouseInput();                
		GetMousePoint( &x, &y ); 
		
		DrawGraph(0,0,back1,false);
		DrawGraph(35,120,obon,false);
		DrawGraph(35,35,korega,false);
	
		sentaku();
	
		if(x>=690 && x<=800 && y>=465 && y<=520){	//homeのボタン
			if(a == 0){
				a=Se();
			}		
			if(Mouse & MOUSE_INPUT_LEFT){
				PlaySoundMem(se2,DX_PLAYTYPE_NORMAL,false);		
				return 1;
			}
		}
		else
			a=0;	
			
		if(x >= 764 && x<= 800 && y>= 530 && y<= 605){	//retryボタン
			if(b == 0){
				b=Se();
			}		
			if(Mouse & MOUSE_INPUT_LEFT){
				PlaySoundMem(se2,DX_PLAYTYPE_NORMAL,false);
				sentaku();
			}
		}
		else
			b=0;
	}
}
	