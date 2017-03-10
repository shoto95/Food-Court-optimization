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

char MENU[256][256]={"�������ǂ�","�R�������ǂ�","���˂��ǂ�","��������",
				     "�R��������","�V�[�t�[�h�s�U","�Ă�₫�`�L���s�U",
					 "�o�W��&�K�[���b�N�s�U","�|�e�g�����q�s�U",
					 "�t�@�~���[�s�U","�����[����","�ݖ����[����",
					 "���X���[����","�؍����[����","�������","�n���o�[�K�[",
					 "�`�[�Y�o�[�K�[","�Ă�₫�}�b�N�o�[�K�[",
					 "�`�L���o�[�K�[","�G�r�o�[�K�[","�~�b�N�X�Ă�","�Ă�����",
					 "�L���Ă�","���΂߂�","�X�e�[�L","����","�e�q��",
					 "�}�O����","����","���񂩂���"};

char SABU[256][256]={"�`���[�n��","���傤��","���܂�","���ĕ�","����g��",
					 "���ɂ���","�݂��炵�c�q","�G�r�V","�����g��",
					 "���n����","�t���C�h�|�e�g","���ݕ�",
					 "�m���A���R�[���r�[��","�R�[�q�[","�t���C�h�`�L��",
					 "�o�j���A�C�X","�X�g���x���[�A�C�X","�����A�C�X",
					 "�`���R���[�g�A�C�X","�z�b�s���O�V�����[","�����Ă�",
					 "�I������","�T���_","�`�����\�[",
					 "�E�[�p�[���[�p�[�̂���g��","�n�j�[�g�[�X�g",
					 "�N�����b�T��","�A���p��","�J���[�p��","�T���h�C�b�`"};

int kingaku0[256]={340,340,280,380,420,980,880,970,930,1080,
				   700,810,820,790,820,100,130,320,310,370,
				   810,750,980,640,810,550,500,380,580,780};	//���C��
				   
int kingaku1[256]={550,230,180,230,540,110,60,130,350,90,
				   100,250,350,30,550,290,290,320,320,380,
				   500,650,310,280,1300,200,230,330,420,350};	//�T�u

int menu0[256]={55,52,46,42,48,34,37,34,42,59,
			    64,56,62,68,53,31,34,37,42,39,
				38,33,36,31,39,42,36,39,33,40};//���� �@�����x ���C��  30�i
				
int menu1[256]={43,45,44,39,41,29,31,30,34,45,
				42,39,41,48,38,23,24,24,28,26,
				32,29,31,33,35,32,30,34,29,36};//�j��

int sabu0[256];

int sabu1[256];

int sabu0_st[256]={32,28,28,26,27,20,12,10,19,4,
				24,8,15,13,29,20,21,24,21,23,
				28,32,22,19,13,15,13,18,23,20};//���� �@�����x �T�u    30�i
								
int sabu1_st[256]={28,24,21,18,19,14,9,3,5,2,
				14,4,9,11,16,26,23,21,22,23,
				25,28,26,18,14,15,10,12,13,15};//�j�� 

int menu2[256]={37,42,38,40,45,36,34,39,32,31,
				45,43,40,38,42,23,24,27,25,28,
				38,32,34,33,37,39,37,31,39,32};//���� �@�����x  ���C��
				
int menu3[256]={33,35,34,35,36,45,49,41,43,52,
				43,41,46,49,43,33,36,38,32,30,
				45,39,44,41,47,50,45,49,51,47};//�j��

int sabu2[256]={20,21,25,28,25,18,27,13,19,11,
				21,16,13,22,25,28,27,29,30,32,
				29,26,27,21,2,28,31,26,21,29};//���� �@�����x  �T�u
				
int sabu3[256]={32,30,27,22,25,19,14,13,11,10,
				22,15,19,17,23,20,21,19,21,25,
				18,16,14,19,15,21,22,19,24,25};//�j��
				
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
			y=ran();                                                             //����
			if(sex==0){
				if(money==1500){                                                 //���C�����j���[����
					ryori(menu,menu0,y);
					matome(menu0,menu2,y);
					
				}
				else if(sabu0[y]!=0&&money-kingaku1[y]>=0&&Z+sabu0[y]<100){      //�T�u���j���[����
					ryori(sabu,sabu0,y);
					matome(sabu0,sabu2,y);
							
				}
			}
			else if(sex==1){                                                     //�j���@����
				if(money==1500){
					ryori(menu,menu1,y);
					matome(menu1,menu3,y);
					
				}
				else if(sabu1[y]!=0&&money-kingaku1[y]>=0&&Z+sabu1[y]<100){
					ryori(sabu,sabu1,y);
					matome(sabu1,sabu3,y);
					
				}
			}
			if(sabu0[11]==0||sabu1[11]==0){			//���ݕ�
				if(sex==0){
					sabu0[12]=0;
					sabu0[13]=0;
				}
			    else{
					sabu1[12]=0;
					sabu1[13]=0;
				}
			}
			else if(sabu0[12]==0||sabu1[12]==0){		//�m���A���R�[���r�[��
				if(sex==0){
					sabu0[11]=0;
					sabu0[13]=0;
				}
				else{
					sabu1[11]=0;
					sabu1[13]=0;
				}
			}
			else if(sabu0[13]==0||sabu1[13]==0){		//�R�[�q�[	   	  	
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
	while(menyu_st[xx]!=-1){             //stock�֐��ŏ����������̕\��
		y=menyu_st[xx];
		if(xx==0){
		 	DrawGraph(390,290,menu[y],true);
			DrawFormatString(50,480,cr,"�����߂̃��C�����j���[");
			DrawFormatString(50,500,cr,"�u%s�v",MENU[y]);
		}
		else
		{
			if(xx==1)
				DrawFormatString(400,x,cr,"�����߂̃T�u���j���[");
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
			DrawFormatString(C,x,cr,"�u%s�v",SABU[y]);
		}
		X+=113;		
		xx++; 
	}
	DrawFormatString(700,150,cr,"�����x�́u%d�v�ł�.",str1);
	DrawFormatString(700,200,cr,"�����x�́u%d�v�ł�.",str2);
	DrawFormatString(700,250,cr,"�c���́u%d�v�ł�.",str3);
	
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

//�����x�A�����x�A���z����//
void matome(int manpuku[256],int manzoku[256],int y)
{	
	if(V==1){
		Z+=manpuku[y];
		D+=manzoku[y];
		manpuku[y]=0;
		V=0;
		if(money==1500)     		//��H
			money-=kingaku0[y];
		else                        //�T�u���j���[
			money-=kingaku1[y];
	}
}

//���ʕ\��//
void stock()
{
	int y;
	if(str1<Z){
		str1=Z;			 //�����x�i�[
		str2=D;  		 //�����x�i�[
		str3=money;		 //��  �z�i�[
		for(I=0;I<256;I++)
			menyu_st[I]=-1;
		for(I=0;menyu[I]!=-1;I++)
			menyu_st[I]=menyu[I];
	}
	for(I=0;I<256;I++)   //----����������----
		menyu[I]=-1;
	I=0;
	Z=0;
	money=1500;
	for(y=0;y<31;y++){
		sabu0[y]=sabu0_st[y];	//���C�����j���[�̏������͍s��Ȃ��B
		sabu1[y]=sabu1_st[y];   //�������ʂ��o��̂�h���ׁB
		sabu0[y]*=x;
		sabu1[y]*=x;
	}    
	D=0;                 //----�����܂�----
}
void graph_st()
{
	menu[0]=LoadGraph("�������ǂ�.png");
	menu[1]=LoadGraph("�R�������ǂ�.png");
	menu[2]=LoadGraph("���˂��ǂ�.png");
	menu[3]=LoadGraph("��������.png");
	menu[4]=LoadGraph("�R��������.png");
	menu[5]=LoadGraph("�V�[�t�[�h�s�U.png");
	menu[6]=LoadGraph("�Ă�₫�`�L���s�U.png");
	menu[7]=LoadGraph("�o�W��&�K�[���b�N�s�U.png");
	menu[8]=LoadGraph("�|�e�g�����q�s�U.png");
	menu[9]=LoadGraph("�t�@�~���[�s�U.png");
	menu[10]=LoadGraph("�����[����.png");
	menu[11]=LoadGraph("�ݖ����[����.png");
	menu[12]=LoadGraph("���X���[����.png");
	menu[13]=LoadGraph("�؍����[����.png");
	menu[14]=LoadGraph("�������.png");
	menu[15]=LoadGraph("�n���o�[�K�[.png");
	menu[16]=LoadGraph("�`�[�Y�o�[�K�[.png");
	menu[17]=LoadGraph("�Ă�₫�o�[�K�[.png");
	menu[18]=LoadGraph("�`�L���o�[�K�[.png");
	menu[19]=LoadGraph("�G�r�o�[�K�[.png");
	menu[20]=LoadGraph("�~�b�N�X�Ă�.png");
	menu[21]=LoadGraph("�Ă�����.png");
	menu[22]=LoadGraph("�L���Ă�.png");
	menu[23]=LoadGraph("���΂߂�.png");
	menu[24]=LoadGraph("�X�e�[�L.png");
	menu[25]=LoadGraph("����.png");
	menu[26]=LoadGraph("�e�q��.png");
	menu[27]=LoadGraph("�}�O����.png");
	menu[28]=LoadGraph("����.png");
	menu[29]=LoadGraph("���񂩂���.png");
            
	sabu[0]=LoadGraph("�`���[�n��.png");
	sabu[1]=LoadGraph("���傤��.png");
	sabu[2]=LoadGraph("���܂�.png");
	sabu[3]=LoadGraph("���ĕ�.png");
	sabu[4]=LoadGraph("����g��.png");
	sabu[5]=LoadGraph("���ɂ���.png");
	sabu[6]=LoadGraph("�݂��炵�c�q.png");
	sabu[7]=LoadGraph("�G�r�V.png");
	sabu[8]=LoadGraph("�����g��.png");
	sabu[9]=LoadGraph("���n����.png");
	sabu[10]=LoadGraph("�t���C�h�|�e�g.png");
	sabu[11]=LoadGraph("���ݕ�.png");
	sabu[12]=LoadGraph("�m���A���R�[���r�[��.png");
	sabu[13]=LoadGraph("�R�[�q�[.png");
	sabu[14]=LoadGraph("�t���C�h�`�L��.png");
	sabu[15]=LoadGraph("�o�j���A�C�X.png");
	sabu[16]=LoadGraph("�X�g���x���[�A�C�X.png");
	sabu[17]=LoadGraph("�����A�C�X.png");
	sabu[18]=LoadGraph("�`���R���[�g�A�C�X.png");
	sabu[19]=LoadGraph("�~���g�A�C�X.png");
	sabu[20]=LoadGraph("�����Ă�.png");
	sabu[21]=LoadGraph("�I������.png");
	sabu[22]=LoadGraph("�T���_.png");
	sabu[23]=LoadGraph("�`�����\�[.png");
	sabu[24]=LoadGraph("�E�[�p�[���[�p�[�̂���g��.png");
	sabu[25]=LoadGraph("�n�j�[�g�[�X�g.png");
	sabu[26]=LoadGraph("�N�����b�T��.png");
	sabu[27]=LoadGraph("�A���p��.png");
	sabu[28]=LoadGraph("�J���[�p��.png");
	sabu[29]=LoadGraph("�T���h�C�b�`.png");
}