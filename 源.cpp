/*
开发日志
1.创建项目
2.导入素材
3.游戏界面
开发流程：用户界面入手


加载背景
渲染
找开源支持png透明图
设置滚动速度和循环滚动


加载人物
坐标加载


//创建游戏窗口
//创建游戏背景(3背景速度不同，实现视觉效果；循环滚动)
*/

#include<stdio.h>
#include<graphics.h>//基于“esayX”
#include"tools.h"

#define WIN_WIDTH 1012
#define WIN_HEIGHT 396

IMAGE  imgBgs[3];//背景图片
int i;
int bgX[3];//背景坐标
int speed[3] = { 1,3,6 };//滚动速度

double heroX, heroY;
int heroIndex = 0;

IMAGE  imgHeros[12];//人物图片



//初始化
void init()
{


	//创建游戏窗口
	initgraph(WIN_WIDTH, WIN_HEIGHT);

	char name[100];
	for( i=0;i<3;i++)
	{
		sprintf_s(name, "res/bg%03d.png", i + 1);//图片所在文件
		loadimage(&imgBgs[i], name);
		bgX[i] = 0;
		
	}
	for (i = 0; i < 12; i++)
	{
		sprintf_s(name, "res/hero%d.png",i+1);//图片所在文件
		loadimage(&imgHeros[i], name);
	}

	heroX = WIN_WIDTH * 0.5 - imgHeros[0].getwidth() * 0.5;
	heroY = 300- imgHeros[0].getheight() * 0.5;
	
}



//渲染游戏背景
void updateBg()
{
	
	putimagePNG2(bgX[0], 0, &imgBgs[0]);
	putimagePNG2(bgX[1], 119, &imgBgs[1]);
	putimagePNG2(bgX[2], 330, &imgBgs[2]);

}



//滚动
void fly()
{
	for (i = 0; i < 3;i++)
	{
		bgX[i] -= speed[i];//三图做差速度

		if (bgX[i] < -WIN_WIDTH)
		{
			bgX[i] = 0;//循环滚动
		}
	}
	heroIndex = (heroIndex + 1) % 12;//人物
}




int main(void)
{
	init();
	while (1) 
	{
		BeginBatchDraw();
		updateBg();//渲染
		putimagePNG2( heroX, heroY ,&imgHeros[heroIndex]);//人物踪迹
		EndBatchDraw();
		fly();//滚动
		Sleep(30);//休眠
	 }
		
	
		system("pause");
	return 0;
}