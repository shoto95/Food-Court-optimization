#include "DxLib.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "Map.h"
#include "Word.h"
#include "Se_play0.h"

int age(){
	int i,x,y,x1,y1,Mouse,Wheel,Img1,back1,bgm1;
	int se1,se2,se3,zahyou,Cr,Cr1,MouseX,MouseY,u=0,v=0,w=0,c=1,d=0,e=0;
	int title1,title2,copy,start_han,exit_han;
	int start[2],exit[2];
	
	se1=LoadSoundMem("radio.wav");
	
	while(ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0){
		Mouse = GetMouseInput();                //ƒ}ƒEƒX‚Ì“ü—Íó‘ÔŽæ“¾
        GetMousePoint( &x, &y );	
		
	if(x>=340 && x<=450 && y>=120 && y<=230){	//10~30‘ã
		if(Mouse & MOUSE_INPUT_LEFT & c == 0 && d == 1 && e == 0){//d‚ª‰Ÿ‚³‚ê‚Ä‚¢‚é‚Æ‚«
			PlaySoundMem(se1,DX_PLAYTYPE_NORMAL,false);
			c++;
	        d--;
		}
	}
		if(x>=538 && x<=648 && y>=120 && y<=230){
			if(Mouse & MOUSE_INPUT_LEFT & c == 0 && d == 0 && e == 1){//e‚ª‰Ÿ‚³‚ê‚Ä‚¢‚é‚Æ‚«
				PlaySoundMem(se1,DX_PLAYTYPE_NORMAL,false);
				c++;
				e--;
			}
		}
		
	if(x>=340 && x<=450 && y>=120 && y<=230){	//31~60‘ã
		if(Mouse & MOUSE_INPUT_LEFT & c == 1 && d == 0 && e == 0){//c‚ª‰Ÿ‚³‚ê‚Ä‚¢‚é‚Æ‚«
			PlaySoundMem(se1,DX_PLAYTYPE_NORMAL,false);
		    d++;
			c--;
		}
	}
		if(x>=538 && x<=648 && y>=120 && y<=230){
			if(Mouse & MOUSE_INPUT_LEFT & c == 0 && d == 0 && e == 1){//e‚ª‰Ÿ‚³‚ê‚Ä‚¢‚é‚Æ‚«
				PlaySoundMem(se1,DX_PLAYTYPE_NORMAL,false);
				d++;
				e--;
			}
		}
	if(x>=340 && x<=450 && y>=120 && y<=230){	//61~90‘ã
		if(Mouse & MOUSE_INPUT_LEFT & c == 1 && d == 0 && e == 0){//c‚ª‰Ÿ‚³‚ê‚Ä‚¢‚é‚Æ‚«
			PlaySoundMem(se1,DX_PLAYTYPE_NORMAL,false);
			e++;
			c--;
		}
	}
		
		if(x>=538 && x<=648 && y>=120 && y<=230){
			if(Mouse & MOUSE_INPUT_LEFT & c == 0 && d == 1 && e == 0){//d‚ª‰Ÿ‚³‚ê‚Ä‚¢‚é‚Æ‚«
				PlaySoundMem(se1,DX_PLAYTYPE_NORMAL,false);
				e++;
				d--;
			}
		}
	}
}