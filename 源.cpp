/*
������־
1.������Ŀ
2.�����ز�
3.��Ϸ����
�������̣��û���������


���ر���
��Ⱦ
�ҿ�Դ֧��png͸��ͼ
���ù����ٶȺ�ѭ������


��������
�������


//������Ϸ����
//������Ϸ����(3�����ٶȲ�ͬ��ʵ���Ӿ�Ч����ѭ������)
*/

#include<stdio.h>
#include<graphics.h>//���ڡ�esayX��
#include"tools.h"

#define WIN_WIDTH 1012
#define WIN_HEIGHT 396

IMAGE  imgBgs[3];//����ͼƬ
int i;
int bgX[3];//��������
int speed[3] = { 1,3,6 };//�����ٶ�

double heroX, heroY;
int heroIndex = 0;

IMAGE  imgHeros[12];//����ͼƬ



//��ʼ��
void init()
{


	//������Ϸ����
	initgraph(WIN_WIDTH, WIN_HEIGHT);

	char name[100];
	for( i=0;i<3;i++)
	{
		sprintf_s(name, "res/bg%03d.png", i + 1);//ͼƬ�����ļ�
		loadimage(&imgBgs[i], name);
		bgX[i] = 0;
		
	}
	for (i = 0; i < 12; i++)
	{
		sprintf_s(name, "res/hero%d.png",i+1);//ͼƬ�����ļ�
		loadimage(&imgHeros[i], name);
	}

	heroX = WIN_WIDTH * 0.5 - imgHeros[0].getwidth() * 0.5;
	heroY = 300- imgHeros[0].getheight() * 0.5;
	
}



//��Ⱦ��Ϸ����
void updateBg()
{
	
	putimagePNG2(bgX[0], 0, &imgBgs[0]);
	putimagePNG2(bgX[1], 119, &imgBgs[1]);
	putimagePNG2(bgX[2], 330, &imgBgs[2]);

}



//����
void fly()
{
	for (i = 0; i < 3;i++)
	{
		bgX[i] -= speed[i];//��ͼ�����ٶ�

		if (bgX[i] < -WIN_WIDTH)
		{
			bgX[i] = 0;//ѭ������
		}
	}
	heroIndex = (heroIndex + 1) % 12;//����
}




int main(void)
{
	init();
	while (1) 
	{
		BeginBatchDraw();
		updateBg();//��Ⱦ
		putimagePNG2( heroX, heroY ,&imgHeros[heroIndex]);//�����ټ�
		EndBatchDraw();
		fly();//����
		Sleep(30);//����
	 }
		
	
		system("pause");
	return 0;
}