#include<stdio.h>
#include<stdlib.h>

typedef struct angel
{
	int num;
	struct angel *fr;//注意指向前一节点的指针fr
	struct angel *next;
}angel;

void init(angel *&bt,int x)
{
	int i=2;
	angel *p=bt;
	bt->num =1;   //第一个节点是存储数据的
	bt->fr =NULL;
	bt->next =NULL;
	while(x--!=1)
	{
		p->next=(angel *)malloc(sizeof(angel));
		(p->next)->fr =p;//先把后一个结点的前结点给固定
		p=p->next; //把当前节点修改为正在执行的结点
		p->num =i++;//对新结点进行操作
		p->next =NULL;
	}
	bt->fr =p;//第一个结点的前指针指向最后一个节点
	p->next =bt;//最后一个节点的下一个指向开头节点
}

//这一步find国王，在每删除一个节点都要进行一次节点对接和判断剩余人数的操作
int find(angel *&bt,int m)
{
	int length(angel *&pt);//对求链表长度函数的声明
	angel *p=bt;//用p来指代当前节点
	int i=0;
	while(length(p)!=1)//一直循环到链表只剩下一个元素
	{
		if(i++==0)//如果i=0，则第一位领主出列，将其从列表中删除
		{
			angel *a=p;
			(p->fr)->next =p->next ;
			(p->next)->fr=p->fr;//第一遍时此句忘了加上去，造成程序输出错误
            p=p->next ;
			free(a);//为什么用一个中间量a,因为p是用来指向当前被操作的结点，
			        //一旦赋值完成后，中间被删除的结点会丢失，所以需要用中间量来保存
		            //注意赋值和删除操作的先后顺序
		}
		if(length(p)==1)
			return p->num;
		else
		{//执行此循环时出错，因为没有加(p->next)->fr=p->fr;导致最后找不到值
			for(int a=1;a<m;a++)//此循环用于找到第m个领主
			   p=p->next;
			//找到第m个领主后，把它删除
			angel *aa=p;
			(p->fr)->next =p->next ;
			(p->next)->fr=p->fr;
            p=p->next ;
			free(aa);
		}

	}
	int b=p->num;
	free(p);//把最后一个节点释放掉
	return b ;
}

//用于查看链表中还剩多少人
int length(angel *&pt)//int length(angel *pt)这种写法有问题
{
	int i=1;
	angel *bt=pt;//用于保存传过来的第一个结点地址
	while(pt->next!=bt)//有问题，不能出现后面的引导词
	{
		i++;
		pt=pt->next;
	}
	pt=bt;//把第一个节点位置返回pt
//	printf("%d\n",i);//测试用，看这一步到底执行了多少
	return i;
}

/*
void release(angel *&bt,int x)//用于测试第一步初始化是否成功
{//为什么节点的释放会出错
//注意这一步释放总是出错，原因是，malloc和free是一对，有一个malloc才有一个free
//之前第一个节点的建立：angel bt之后改成angel *bt,这两种分配方式都没用到malloc
//但最后你都用free去释放，所以造成错误
	angel *cc;
    angel *pc=bt;
	while(pc!=NULL)
	{
		cc=pc->next;  //保存后一个节点，
        free(pc);     //释放当前结点
		pc=cc;        //结点位置刷新       
		              //程序中原来缺少这一句pc=cc; ，导致程序运行时一直出错。
		              //这个问题在你编程中很常出现，思路不清楚，还没想好就开始写代码，就是值没更新的问题。
	}
}*/

void main()
{
	angel *bt=(angel *)malloc(sizeof(angel)); //申请一个头结点,注意用malloc来申请
	bt->num =0;
	bt->fr =NULL;
	bt->next =NULL;
	int x=0,m=0;
	int a=0;
	printf("请输入几个领主X：");
	scanf("%d",&x);
	printf("请输入往后找的值M：");
	scanf("%d",&m);
	init(bt,x);//在知道链表中有X个结点后，对链表进行初始化
	a=find(bt,m);
//	release(bt,x);//测试用
	printf("\n在查找之后发现第 %d 位应该继承王位",a);
}