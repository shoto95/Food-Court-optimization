#include "DxLib.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int menu[256];
int sabu[256];

int ran(void);
void graph_st(void);
void sentaku(void);
void ryori(int ryori[31],int ryouri[31],int y);
void matome(int manpuku[256],int manzoku[256],int y);
void stock();
extern int sex;
extern int nenrei;

char MENU[256][256]={"月見うどん","山かけうどん","きつねうどん","月見そば",
				     "山かけそば","シーフードピザ","てりやきチキンピザ",
					 "バジル&ガーリックピザ","ポテト明太子ピザ",
					 "ファミリーピザ","塩ラーメン","醤油ラーメン",
					 "味噌ラーメン","豚骨ラーメン","魚介つけ麺","ハンバーガー",
					 "チーズバーガー","てりやきマックバーガー",
					 "チキンバーガー","エビバーガー","ミックス焼き","焼きそば",
					 "広島焼き","そばめし","ステーキ","かつ丼","親子丼",
					 "マグロ丼","牛丼","あんかけ丼"};

char SABU[256][256]={"チャーハン","ぎょうざ","肉まん","小籠包","から揚げ",
					 "おにぎり","みたらし団子","エビ天","かき揚げ",
					 "半熟温泉卵","フライドポテト","飲み物",
					 "ノンアルコールビール","コーヒー","フライドチキン",
					 "バニラアイス","ストロベリーアイス","抹茶アイス",
					 "チョコレートアイス","ホッピングシャワー","たこ焼き",
					 "オムそば","サラダ","チョリソー",
					 "ウーパールーパーのから揚げ","ハニートースト",
					 "クロワッサン","アンパン","カレーパン","サンドイッチ"};

int kingaku0[256]={340,340,280,380,420,980,880,970,930,1080,
				   700,810,820,790,820,100,130,320,310,370,
				   810,750,980,640,810,550,500,380,580,780};	//メイン
				   
int kingaku1[256]={550,230,180,230,540,110,60,130,350,90,
				   100,250,350,30,550,290,290,320,320,380,
				   500,650,310,280,1300,200,230,330,420,350};	//サブ

int menu0[256]={55,52,46,42,48,34,37,34,42,59,
			    64,56,62,68,53,31,34,37,42,39,
				38,33,36,31,39,42,36,39,33,40};//女性 　満腹度 メイン  30品
				
int menu1[256]={43,45,44,39,41,29,31,30,34,45,
				42,39,41,48,38,23,24,24,28,26,
				32,29,31,33,35,32,30,34,29,36};//男性

int sabu0[256];

int sabu1[256];

int sabu0_st[256]={32,28,28,26,27,20,12,10,19,4,
				24,8,15,13,29,20,21,24,21,23,
				28,32,22,19,13,15,13,18,23,20};//女性 　満腹度 サブ    30品
								
int sabu1_st[256]={28,24,21,18,19,14,9,3,5,2,
				14,4,9,11,16,26,23,21,22,23,
				25,28,26,18,14,15,10,12,13,15};//男性 

int menu2[256]={37,42,38,40,45,36,34,39,32,31,
				45,43,40,38,42,23,24,27,25,28,
				38,32,34,33,37,39,37,31,39,32};//女性 　満足度  メイン
				
int menu3[256]={33,35,34,35,36,45,49,41,43,52,
				43,41,46,49,43,33,36,38,32,30,
				45,39,44,41,47,50,45,49,51,47};//男性

int sabu2[256]={20,21,25,28,25,18,27,13,19,11,
				21,16,13,22,25,28,27,29,30,32,
				29,26,27,21,2,28,31,26,21,29};//女性 　満足度  サブ
				
int sabu3[256]={32,30,27,22,25,19,14,13,11,10,
				22,15,19,17,23,20,21,19,21,25,
				18,16,14,19,15,21,22,19,24,25};//男性
				
int menyu[256];
int menyu_st[256];
int Z,A,N,Y,D,L,V,b,I,F,J,C;
float x;
int money=1500;

int str1,str2,str3;

time_t t;

void sentaku()
{
	int cr;
	cr=GetColor(0,0,255);
	
	int y,a,Max,LL=0,xx,X,i=0;
	
	SetFontSize(21);
	
	time(&t);
	srand(t);
	
	graph_st();
	
	if(nenrei==0)
		x=1.2;
	else if(nenrei==1)
		x=1.25;
	else if(nenrei==2)
		x=1.4;
	for(y=0;y<31;y++){
		sabu0[y]=sabu0_st[y];
		sabu1[y]=sabu1_st[y];
	}
	
	for(y=0;y<=256;y++){       
		menu0[y]*=x;
		sabu0[y]*=x;
		menu1[y]*=x;
		sabu1[y]*=x;
		menyu[y]=-1;
		menyu_st[y]=-1;
	}

	while(L<30){
		do{
			y=ran();                                                             //女性
			if(sex==0){
				if(money==1500){                                                 //メインメニュー処理
					ryori(menu,menu0,y);
					matome(menu0,menu2,y);
					
				}
				else if(sabu0[y]!=0&&money-kingaku1[y]>=0&&Z+sabu0[y]<100){      //サブメニュー処理
					ryori(sabu,sabu0,y);
					matome(sabu0,sabu2,y);
							
				}
			}
			else if(sex==1){                                                     //男性　同上
				if(money==1500){
					ryori(menu,menu1,y);
					matome(menu1,menu3,y);
					
				}
				else if(sabu1[y]!=0&&money-kingaku1[y]>=0&&Z+sabu1[y]<100){
					ryori(sabu,sabu1,y);
					matome(sabu1,sabu3,y);
					
				}
			}
			if(sabu0[11]==0||sabu1[11]==0){			//飲み物
				if(sex==0){
					sabu0[12]=0;
					sabu0[13]=0;
				}
			    else{
					sabu1[12]=0;
					sabu1[13]=0;
				}
			}
			else if(sabu0[12]==0||sabu1[12]==0){		//ノンアルコールビール
				if(sex==0){
					sabu0[11]=0;
					sabu0[13]=0;
				}
				else{
					sabu1[11]=0;
					sabu1[13]=0;
				}
			}
			else if(sabu0[13]==0||sabu1[13]==0){		//コーヒー	   	  	
				if(sex==0){
					sabu0[11]=0;
					sabu0[12]=0;
				}
				else{
					sabu1[11]=0;
					sabu1[12]=0;
				}
			}
			if(sabu0[15]==0||sabu1[15]==0){
				if(sex==0){
					sabu0[16]=0;							
			        sabu0[17]=0;
					sabu0[18]=0;
					sabu0[19]=0;
				}
				else{
					sabu1[16]=0;
			        sabu1[17]=0;
					sabu1[18]=0;
					sabu1[19]=0;
				}
			}
			else if(sabu0[16]==0||sabu1[16]==0){
				if(sex==0){
					sabu0[15]=0;					
			        sabu0[17]=0;
					sabu0[18]=0;
					sabu0[19]=0;
				}
				else{
					sabu1[15]=0;							
			        sabu1[17]=0;
					sabu1[18]=0;
					sabu1[19]=0;
				}
			}
			else if(sabu0[17]==0||sabu1[17]==0){
				if(sex==0){
					sabu0[15]=0;					
			        sabu0[16]=0;
					sabu0[18]=0;
					sabu0[19]=0;
				}
				else{
					sabu1[15]=0;							
			        sabu1[16]=0;
					sabu1[18]=0;
					sabu1[19]=0;
				}
			}		
			else if(sabu0[18]==0||sabu1[18]==0){
				if(sex==0){
					sabu0[15]=0;					
			        sabu0[16]=0;
					sabu0[17]=0;
					sabu0[19]=0;
				}
				else{
					sabu1[15]=0;							
			        sabu1[16]=0;
					sabu1[17]=0;
					sabu1[19]=0;
				}
			}
			else if(sabu0[19]==0||sabu1[19]==0){
				if(sex==0){
					sabu0[15]=0;					
			        sabu0[16]=0;
					sabu0[17]=0;
					sabu0[18]=0;
				}
				else{
					sabu1[15]=0;							
			        sabu1[16]=0;
					sabu1[17]=0;
					sabu1[18]=0;
				}
			}
			
			b++;
		}while(b!=2000);
		L++;
		stock();
		b=0;	
	}
	xx=0;
	X=45;
	Y=160;
	x=480;
	C=400;
	while(menyu_st[xx]!=-1){             //stock関数で処理したもの表示
		y=menyu_st[xx];
		if(xx==0){
		 	DrawGraph(390,290,menu[y],true);
			DrawFormatString(50,480,cr,"お勧めのメインメニュー");
			DrawFormatString(50,500,cr,"「%s」",MENU[y]);
		}
		else
		{
			if(xx==1)
				DrawFormatString(400,x,cr,"お勧めのサブメニュー");
			if(xx%4==0){
				X=125;
				Y=260;
			}
			DrawGraph(X,Y,sabu[y],true);
			x+=20;
			if(xx%5==0){
				C+=300;
				x=500;
			}
			DrawFormatString(C,x,cr,"「%s」",SABU[y]);
		}
		X+=113;		
		xx++; 
	}
	DrawFormatString(700,150,cr,"満腹度は「%d」です.",str1);
	DrawFormatString(700,200,cr,"満足度は「%d」です.",str2);
	DrawFormatString(700,250,cr,"残金は「%d」です.",str3);
	
	ProcessMessage(),ScreenFlip(),WaitKey();
	DxLib_End();
}

ran()
{
	int a,b;                          
	a=rand();
	b=a%30;
		
	return b;
}


void ryori(int ryori[31],int ryouri[31],int y)
{
	int x;
	if(sabu0[y]!=0&&sabu1[y]!=0&&Z+ryouri[y]<100&&money-kingaku1[y]>=0){
		menyu[I]=y;
		I++;
		V=1;
	}
}

//満腹度、満足度、金額処理//
void matome(int manpuku[256],int manzoku[256],int y)
{	
	if(V==1){
		Z+=manpuku[y];
		D+=manzoku[y];
		manpuku[y]=0;
		V=0;
		if(money==1500)     		//主食
			money-=kingaku0[y];
		else                        //サブメニュー
			money-=kingaku1[y];
	}
}

//結果表示//
void stock()
{
	int y;
	if(str1<Z){
		str1=Z;			 //満腹度格納
		str2=D;  		 //満足度格納
		str3=money;		 //金  額格納
		for(I=0;I<256;I++)
			menyu_st[I]=-1;
		for(I=0;menyu[I]!=-1;I++)
			menyu_st[I]=menyu[I];
	}
	for(I=0;I<256;I++)   //----初期化処理----
		menyu[I]=-1;
	I=0;
	Z=0;
	money=1500;
	for(y=0;y<31;y++){
		sabu0[y]=sabu0_st[y];	//メインメニューの初期化は行わない。
		sabu1[y]=sabu1_st[y];   //同じ結果が出るのを防ぐ為。
		sabu0[y]*=x;
		sabu1[y]*=x;
	}    
	D=0;                 //----ここまで----
}
void graph_st()
{
	menu[0]=LoadGraph("月見うどん.png");
	menu[1]=LoadGraph("山かけうどん.png");
	menu[2]=LoadGraph("きつねうどん.png");
	menu[3]=LoadGraph("月見そば.png");
	menu[4]=LoadGraph("山かけそば.png");
	menu[5]=LoadGraph("シーフードピザ.png");
	menu[6]=LoadGraph("てりやきチキンピザ.png");
	menu[7]=LoadGraph("バジル&ガーリックピザ.png");
	menu[8]=LoadGraph("ポテト明太子ピザ.png");
	menu[9]=LoadGraph("ファミリーピザ.png");
	menu[10]=LoadGraph("塩ラーメン.png");
	menu[11]=LoadGraph("醤油ラーメン.png");
	menu[12]=LoadGraph("味噌ラーメン.png");
	menu[13]=LoadGraph("豚骨ラーメン.png");
	menu[14]=LoadGraph("魚介つけ麺.png");
	menu[15]=LoadGraph("ハンバーガー.png");
	menu[16]=LoadGraph("チーズバーガー.png");
	menu[17]=LoadGraph("てりやきバーガー.png");
	menu[18]=LoadGraph("チキンバーガー.png");
	menu[19]=LoadGraph("エビバーガー.png");
	menu[20]=LoadGraph("ミックス焼き.png");
	menu[21]=LoadGraph("焼きそば.png");
	menu[22]=LoadGraph("広島焼き.png");
	menu[23]=LoadGraph("そばめし.png");
	menu[24]=LoadGraph("ステーキ.png");
	menu[25]=LoadGraph("かつ丼.png");
	menu[26]=LoadGraph("親子丼.png");
	menu[27]=LoadGraph("マグロ丼.png");
	menu[28]=LoadGraph("牛丼.png");
	menu[29]=LoadGraph("あんかけ丼.png");
            
	sabu[0]=LoadGraph("チャーハン.png");
	sabu[1]=LoadGraph("ぎょうざ.png");
	sabu[2]=LoadGraph("肉まん.png");
	sabu[3]=LoadGraph("小籠包.png");
	sabu[4]=LoadGraph("から揚げ.png");
	sabu[5]=LoadGraph("おにぎり.png");
	sabu[6]=LoadGraph("みたらし団子.png");
	sabu[7]=LoadGraph("エビ天.png");
	sabu[8]=LoadGraph("かき揚げ.png");
	sabu[9]=LoadGraph("半熟温泉卵.png");
	sabu[10]=LoadGraph("フライドポテト.png");
	sabu[11]=LoadGraph("飲み物.png");
	sabu[12]=LoadGraph("ノンアルコールビール.png");
	sabu[13]=LoadGraph("コーヒー.png");
	sabu[14]=LoadGraph("フライドチキン.png");
	sabu[15]=LoadGraph("バニラアイス.png");
	sabu[16]=LoadGraph("ストロベリーアイス.png");
	sabu[17]=LoadGraph("抹茶アイス.png");
	sabu[18]=LoadGraph("チョコレートアイス.png");
	sabu[19]=LoadGraph("ミントアイス.png");
	sabu[20]=LoadGraph("たこ焼き.png");
	sabu[21]=LoadGraph("オムそば.png");
	sabu[22]=LoadGraph("サラダ.png");
	sabu[23]=LoadGraph("チョリソー.png");
	sabu[24]=LoadGraph("ウーパールーパーのから揚げ.png");
	sabu[25]=LoadGraph("ハニートースト.png");
	sabu[26]=LoadGraph("クロワッサン.png");
	sabu[27]=LoadGraph("アンパン.png");
	sabu[28]=LoadGraph("カレーパン.png");
	sabu[29]=LoadGraph("サンドイッチ.png");
}