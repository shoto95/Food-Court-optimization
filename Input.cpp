#include "DxLib.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "Result.h"
#include "Se_play0.h"
#include "Result.h"
#include "age.h"
#include "Se_play1.h"
#include "ryori.h"
int sex=1;
int nenrei;

int Input(){
	StopMusic();
	int bgm,back,i=1,j=0,x,y,Mouse,se1,se2,se3,ok,modoru,a=0,b=0,a1=0,b1=0,u=0,v=0,w=0,c=1,d=0,e=0,K=1,C=0,CC=0,KK=1,ZZ=0,VV=0;
	int man[2],woman[2],ok_ok[2],modoru_modoru[2],kid_kid[2],wakai_wakai[2],oi_oi[2],Ret=0,nendai,seibetu,kid,wakai,oi,huti,huti2;
	int cr=0;
	back=LoadGraph("white.png");
	LoadDivGraph("man.jpg",2,2,1,110,110,man);	//graph input
	LoadDivGraph("woman.jpg",2,2,1,110,110,woman);
	
	se1=LoadSoundMem("radio.wav");
	se2=LoadSoundMem("go.wav");
	se3=LoadSoundMem("cancel.wav");
	ok=LoadDivGraph("ok.png",2,2,1,112,55,ok_ok);
	modoru=LoadDivGraph("back.png",2,2,1,208,55,modoru_modoru);
	kid=LoadDivGraph("kid.png",2,2,1,110,110,kid_kid);
	wakai=LoadDivGraph("wakai.png",2,2,1,110,110,wakai_wakai);
	oi=LoadDivGraph("oi.png",2,2,1,110,110,oi_oi);
	
	nendai=LoadGraph("nendai.png");
	seibetu=LoadGraph("seibetu.png");
	huti=LoadGraph("huti.png");
	huti2=LoadGraph("huti2.png");
	
	SetFontSize(30);
	while(ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){
		Mouse = GetMouseInput();                //マウスの入力状態取得
                GetMousePoint( &x, &y );
		
		DrawGraph(0,0,back,true);
		
		
		if(KK==1)
			DrawGraph(240,340,huti2,true);
		else if(KK==2)
			DrawGraph(440,340,huti2,true);
		else if(KK==3)
			DrawGraph(640,340,huti2,true);
		
		if(a == 0 || a == 1 && b == 0 || b == 1){
			DrawGraph(250,350,kid_kid[c],false);
			DrawGraph(450,350,wakai_wakai[d],false);
			DrawGraph(650,350,oi_oi[e],false);
			DrawGraph(250,258,nendai,true);
			DrawGraph(240,20,seibetu,true);
		}
        if(sex==1)
			DrawFormatString(100,550,cr,"男性");
		else
			DrawFormatString(100,550,cr,"女性");
		
		if(nenrei==0)
			DrawFormatString(200,550,cr,"30歳以下");
			
		else if(nenrei==1)
			DrawFormatString(200,550,cr,"31～60歳");
			
		else
			DrawFormatString(200,550,cr,"61以上");		

		DrawGraph(340,120,man[i],false);
		DrawGraph(538,120,woman[j],false);
		DrawGraph(764,485,ok_ok[0],false);
		DrawGraph(764,550,modoru_modoru[0],false);
	
		
		if(x>=340 && x<=450 && y>=120 && y<=230){
			if(Mouse & MOUSE_INPUT_LEFT & i == 0 && j == 1){
			        Se1();
				i++;
				j--;
				sex=1;
				K=1;
				C=1;
				CC=0;
			}	
					
		}
			
		if(x>=538 && x<=648 && y>=120 && y<=230){
			if(Mouse & MOUSE_INPUT_LEFT & j == 0 && i == 1){
				Se1();
				j++;
				i--;
				sex=0;
				K=2;
				C=0;
				CC=0;
			}
		}
		if(C<8){
			if(huti!=0)
				huti=0;
			else
				huti=LoadGraph("huti.png");
		}
		if(C>8&&CC==0){
			huti=LoadGraph("huti.png");
			CC=1;
		}
		if(ZZ<8){
			if(huti2!=0)
				huti2=0;
			else
				huti2=LoadGraph("huti2.png");
		}
		if(ZZ>8&&VV==0){
			huti2=LoadGraph("huti2.png");
			VV=1;
		}

		ZZ++;
		C++;		
		if(K==1)
			DrawGraph(330,110,huti,false);	
		else if(K==2)
			DrawGraph(528,110,huti,false);		
		
		if(x>=250 && x<=360 && y>=350 && y<=460){	//10~30代
			if(Mouse & MOUSE_INPUT_LEFT & c == 0 && d == 1 && e == 0){//dが押されているとき
				Se1();
				c++;
				d--;
				nenrei=0;
				KK=1;
				ZZ=VV=0;
			}
			if(Mouse & MOUSE_INPUT_LEFT & c == 0 && d == 0 && e == 1){//eが押されているとき
				Se1();
				c++;
				e--;
				nenrei=0;
				KK=1;
				ZZ=VV=0;
			}					
		}
		
		if(x>=450 && x<=560 && y>=350 && y<=460){	//31~60代
			if(Mouse & MOUSE_INPUT_LEFT & c == 1 && d == 0 && e == 0){//cが押されているとき
				Se1();
				d++;
				c--;
				nenrei=1;
				KK=2;
				ZZ=VV=0;
			}
			if(Mouse & MOUSE_INPUT_LEFT & c == 0 && d == 0 && e == 1){//eが押されているとき
				Se1();
				d++;
				e--;
				nenrei=1;
				KK=2;
				ZZ=VV=0;
			}
			
					
		}
		
		if(x>=650 && x<=760 && y>=350 && y<=460){
			if(Mouse & MOUSE_INPUT_LEFT & c == 1 && d == 0 && e == 0){//cが押されているとき
				Se1();
				e++;
				c--;
				nenrei=2;
				KK=3;
				ZZ=VV=0;
			}
			if(Mouse & MOUSE_INPUT_LEFT & c == 0 && d == 1 && e == 0){//dが押されているとき
				Se1();
				e++;
				d--;	
				nenrei=2;
				KK=3;
				ZZ=VV=0;
			}			
		}
	    DrawGraph(340,120,man[i],false);
		DrawGraph(538,120,woman[j],false);
		DrawGraph(764,485,ok_ok[0],false);
		DrawGraph(764,550,modoru_modoru[0],false);
		if(x>=764 && x<=870 && y>=485 && y<=530){	//okのボタン
			if(a == 0){
				a=Se();
			}
			if(Mouse & MOUSE_INPUT_LEFT){
				PlaySoundMem(se2,DX_PLAYTYPE_NORMAL,false);		
				Ret=Result();
				if(Ret ==  1){
					return 1;
				}
			}
		}
		else
			a=0;
						
		if(x >= 764 && x<= 960 && y>= 550 && y<= 605){	//backボタン
			if(b == 0){
				b=Se();
			}			
			if(Mouse & MOUSE_INPUT_LEFT){
				PlaySoundMem(se3,DX_PLAYTYPE_NORMAL,false);
				return 0;
			}
		}
		else
			b=0;
		WaitTimer(60);	
	}
}