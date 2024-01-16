//����ʽ�ڵ�����ݽṹ 
struct PolyNode
{
	int coef;
	int expon;
	struct PolyNode *link;	
};
typedef struct PolyNode *Polynomial;
Polynomial p1,p2;
//������ʵ�ֶ���ʽ�ӷ��ĺ���
Polynomial Poly(Polynomial p1, Polynomial p2)
{
	Polynomial front, temp, t1, t2;
	temp = (Polynomial)malloc(sizeof(struct PolyNode));
	if (temp == NULL)
	{
		exit(1);//exit��һ����ֹ�������ڱ�׼��stdlib.h�У����þ��ǽ�������ֹ���ɹ���ֹ�򷵻ؽ��ܵĲ���������Ϊ 1�� 
	}
	front = temp;
	temp->link = NULL;//��Ȼ�������ظ��Ƚ϶࣬����Ϊ�˷�ֹҰָ�벻�ò���һЩ׼�� 
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

