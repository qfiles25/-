#include<stdio.h>
#include<stdlib.h>
//链表结点结构体
typedef struct student{
	int no;//储存学号
	struct student *next;//指向下一结点
}link;
//尾插法创建链表，输入0结束录入
void create_node(link *p){
	int no;
	printf("请输入学号(输入0退出):");
	scanf("%d",&no);
	while(no>0){
        //分配新结点内存
	    link *temp=(link*)malloc(sizeof(link));
    	temp->no=no;//存入学号
    	temp->next=NULL;//新结点作为尾部，next置空
    	p->next=temp;//新结点连接到链表末尾
    	p=temp;//尾指针后移
    	printf("请输入学号:");
    	scanf("%d",&no);
    }
}
//历遍打印链表所有学号
void show(link *head){
	link *p=head->next;
	while(p!=NULL){
		printf("%d\n",p->no);
		p=p->next;
	}
}
//删除第一个符合该学号的结点
void sss(link *head,int no){
	link *p=head;//p作为前驱指针
	while(p->next!=NULL){
		if(p->next->no==no){//找到待删除结点
			link *del=p->next;//保存待删除结点位置
			p->next=p->next->next;//断开结点
			free(del);//释放内存
			return;
		}
		p=p->next;
	}
	printf("未找到想要删除学号\n");
}
//在posno后插入newno
void add(link *head,int posno,int newno){
	link *p=head->next;//从第一个数据结点开始查找
	while(p!=NULL){
		if(p->no==posno) break;//找到结点退出
		p=p->next;
	}
	if(p==NULL){//未找到对应学号退出并提示
		printf("为找到%d\n",posno);
		return;
	}
	link *temp=(link*)malloc(sizeof(link));
	temp->no=newno;
	temp->next=p->next;//新结点接后面结点
	p->next=temp;//前结点指向新结点
	printf("成功在%d后面插入%d\n",posno,newno);
}
//释放链表全部内存
void Freelist(link *head){
	link *p=head;
	link *q;
	while(p!=NULL){
		q=p->next;//暂存下一个节点
		free(p);//释放当前节点
		p=q;
	}
}
int main(){
	int a,b;
    //申请头结点，头结点不存数据
	link *head=(link*)malloc(sizeof(link));
	head->next=NULL;
	link *tail=head;
	create_node(tail);//构建链表
	printf("---------------------\n");
	show(head);//打印原始链表
	printf("---------------------\n");
	printf("请输入要删除学号:");
	scanf("%d",&a);
	sss(head,a);//执行删除
	show(head);
	printf("---------------------\n"); 
	printf("请输入想要在a后添加b(示例a b):");
	scanf("%d %d",&a,&b);
	add(head,a,b);//执行插入
	show(head);
	Freelist(head);//释放内存，防止内存泄漏
	return 0;
}
