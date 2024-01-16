//多项式节点的数据结构 
struct PolyNode
{
	int coef;
	int expon;
	struct PolyNode *link;	
};
typedef struct PolyNode *Polynomial;
Polynomial p1,p2;
//下面是实现多项式加法的函数
Polynomial Poly(Polynomial p1, Polynomial p2)
{
	Polynomial front, temp, t1, t2;
	temp = (Polynomial)malloc(sizeof(struct PolyNode));
	if (temp == NULL)
	{
		exit(1);//exit是一个终止函数，在标准库stdlib.h中，作用就是将程序终止，成功终止则返回接受的参数（这里为 1） 
	}
	front = temp;
	temp->link = NULL;//虽然这个语句重复比较多，但是为了防止野指针不得不做一些准备 
	while (p1 && p2)
	{
		if (p1->expon > p2->expon)
		{
			*temp = *p1;
			p1 = p1->link;
		}
		else if (p1->expon < p2->expon)
		{
			*temp = *p2;
			p2 = p2->link;
		}
		else
		{
			if (p1->coef + p2->coef != 0)
			{
				temp->coef = p1->coef + p2->coef;
				temp->expon = p1->expon;
				p1 = p1->link;
				p2 = p2->link;
				temp->link = NULL; 
			}
			else
			{
				p1 = p1->link;
				p2 = p2->link;
				continue;
			}
		}
		if (p1 && p2)
		{
			temp->link = (Polynomial)malloc(sizeof(struct PolyNode));
			if (temp->link == NULL)
			{
				exit(1);
			}
			temp = temp->link;
			temp->link = NULL; 
		}
	}
	if (p1)
		temp->link = p1;
	else if (p2)
		temp->link = p2;

	return front;
}

