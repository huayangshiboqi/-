#include<stdio.h>
#include<stdlib.h>

typedef struct angel
{
	int num;
	struct angel *fr;//ע��ָ��ǰһ�ڵ��ָ��fr
	struct angel *next;
}angel;

void init(angel *&bt,int x)
{
	int i=2;
	angel *p=bt;
	bt->num =1;   //��һ���ڵ��Ǵ洢���ݵ�
	bt->fr =NULL;
	bt->next =NULL;
	while(x--!=1)
	{
		p->next=(angel *)malloc(sizeof(angel));
		(p->next)->fr =p;//�ȰѺ�һ������ǰ�����̶�
		p=p->next; //�ѵ�ǰ�ڵ��޸�Ϊ����ִ�еĽ��
		p->num =i++;//���½����в���
		p->next =NULL;
	}
	bt->fr =p;//��һ������ǰָ��ָ�����һ���ڵ�
	p->next =bt;//���һ���ڵ����һ��ָ��ͷ�ڵ�
}

//��һ��find��������ÿɾ��һ���ڵ㶼Ҫ����һ�νڵ�ԽӺ��ж�ʣ�������Ĳ���
int find(angel *&bt,int m)
{
	int length(angel *&pt);//���������Ⱥ���������
	angel *p=bt;//��p��ָ����ǰ�ڵ�
	int i=0;
	while(length(p)!=1)//һֱѭ��������ֻʣ��һ��Ԫ��
	{
		if(i++==0)//���i=0�����һλ�������У�������б���ɾ��
		{
			angel *a=p;
			(p->fr)->next =p->next ;
			(p->next)->fr=p->fr;//��һ��ʱ�˾����˼���ȥ����ɳ����������
            p=p->next ;
			free(a);//Ϊʲô��һ���м���a,��Ϊp������ָ��ǰ�������Ľ�㣬
			        //һ����ֵ��ɺ��м䱻ɾ���Ľ��ᶪʧ��������Ҫ���м���������
		            //ע�⸳ֵ��ɾ���������Ⱥ�˳��
		}
		if(length(p)==1)
			return p->num;
		else
		{//ִ�д�ѭ��ʱ������Ϊû�м�(p->next)->fr=p->fr;��������Ҳ���ֵ
			for(int a=1;a<m;a++)//��ѭ�������ҵ���m������
			   p=p->next;
			//�ҵ���m�������󣬰���ɾ��
			angel *aa=p;
			(p->fr)->next =p->next ;
			(p->next)->fr=p->fr;
            p=p->next ;
			free(aa);
		}

	}
	int b=p->num;
	free(p);//�����һ���ڵ��ͷŵ�
	return b ;
}

//���ڲ鿴�����л�ʣ������
int length(angel *&pt)//int length(angel *pt)����д��������
{
	int i=1;
	angel *bt=pt;//���ڱ��洫�����ĵ�һ������ַ
	while(pt->next!=bt)//�����⣬���ܳ��ֺ����������
	{
		i++;
		pt=pt->next;
	}
	pt=bt;//�ѵ�һ���ڵ�λ�÷���pt
//	printf("%d\n",i);//�����ã�����һ������ִ���˶���
	return i;
}

/*
void release(angel *&bt,int x)//���ڲ��Ե�һ����ʼ���Ƿ�ɹ�
{//Ϊʲô�ڵ���ͷŻ����
//ע����һ���ͷ����ǳ���ԭ���ǣ�malloc��free��һ�ԣ���һ��malloc����һ��free
//֮ǰ��һ���ڵ�Ľ�����angel bt֮��ĳ�angel *bt,�����ַ��䷽ʽ��û�õ�malloc
//������㶼��freeȥ�ͷţ�������ɴ���
	angel *cc;
    angel *pc=bt;
	while(pc!=NULL)
	{
		cc=pc->next;  //�����һ���ڵ㣬
        free(pc);     //�ͷŵ�ǰ���
		pc=cc;        //���λ��ˢ��       
		              //������ԭ��ȱ����һ��pc=cc; �����³�������ʱһֱ����
		              //��������������кܳ����֣�˼·���������û��þͿ�ʼд���룬����ֵû���µ����⡣
	}
}*/

void main()
{
	angel *bt=(angel *)malloc(sizeof(angel)); //����һ��ͷ���,ע����malloc������
	bt->num =0;
	bt->fr =NULL;
	bt->next =NULL;
	int x=0,m=0;
	int a=0;
	printf("�����뼸������X��");
	scanf("%d",&x);
	printf("�����������ҵ�ֵM��");
	scanf("%d",&m);
	init(bt,x);//��֪����������X�����󣬶�������г�ʼ��
	a=find(bt,m);
//	release(bt,x);//������
	printf("\n�ڲ���֮���ֵ� %d λӦ�ü̳���λ",a);
}