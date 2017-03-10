#include "DxLib.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "Map.h"
#include "Word.h"
#include "Se_play0.h"
#include "Se_play2.h"
#include "Se_play3.h"

int food;

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){	
	SetMainWindowText("Food Court") ;
	ChangeWindowMode(TRUE),SetGraphMode(1000,650,32); 
	DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK ); //ウィンドウモード変更,初期化,裏画面設定

	int i,x,y,x1,y1,Mouse,Wheel,Img1,back1,bgm1;
	int strCr,boxCr,se1,se2,se3,Cr,Cr1,MouseX,MouseY,a=0,b=0;
	int title1,title2,copy,start_han,exit_han,Ret=0;
	int start[2],exit[2];
                
        
    double size=1.0;
	char strBuf1[128],strBuf2[32];
        	
    Img1 = LoadGraph("pict.jpg");//画像ロード
	back1=LoadGraph("back.jpg");
	Cr=GetColor(255,255,255);
	Cr1=GetColor(221,222,211);
	se1=LoadSoundMem("se1.wav");
	se2=LoadSoundMem("cancel.wav");
	se3=LoadSoundMem("go.wav");
	food=LoadSoundMem("food.mp3");
		
	title1=LoadGraph("title1.png");
	title2=LoadGraph("title2.png");
	copy=LoadGraph("copyright.png");
	start_han=LoadDivGraph("start.png",2,2,1,263,55,start);
	exit_han=LoadDivGraph("end.png",2,2,1,208,55,exit);
	
	

	SetVolumeMusic(-100) ;
	PlaySoundMem(food,DX_PLAYTYPE_LOOP);
	SetMouseDispFlag( TRUE );	//マウスを認識状態にする
        // while( 裏画面を表画面に反映, メッセージ処理, 画面クリア )
        while(ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){	//メイン画面処理
                Mouse = GetMouseInput();                //マウスの入力状態取得
                GetMousePoint( &x, &y );                //マウスの座標取得
		
		DrawGraph(0,0,back1,true);

		DrawGraph(80,60,title1,true);
		DrawGraph(320,200,title2,true);
		DrawGraph(102,620,copy,true);
		DrawGraph(364,405,start[0],true);
		DrawGraph(387,490,exit[0],true);
		
		     
		//STARTのプログラム			
		if(x>=365 && x<=600 && y>=415 && y<=455){
			if(a==0){
				a=Se();
			}	
			if(Mouse & MOUSE_INPUT_LEFT){
				Se2();
				Ret=Map();
				if(Ret == 1){
					continue;
				}
			}
		}
		else
			a=0;
		
		//EXITのプログラム			
		if(x>=393 && x<=585 && y>=503 && y<=540){
			if(b == 0){
				b=Se();
			}
			if(Mouse & MOUSE_INPUT_LEFT){
				Se3();
				return 0;
			}
		}
		else
			b=0;						 
	}
}

