#define LH 1
#define EH 0
#degine RH -1

typedef struct BiTNode {
	int data;
	int bf;
	struct BiTNode lchild;
	struct BiTNode rchild;
}BiTNode, *BiTree;

void R_Rotate(BiTree *P){
	BiTree L;
	L = (*P)->lchild;
	(*P)-lchild = L->rchild;
	L->rchild = (*P);
	*P = L;
}

void L_Rotate(BiTree *P){
	BiTree R;
	R = (*P)->rchild;
	(*P)->rchild = R->lchild;
	R->lchild = (*P);
	*P = R;
}

void LeftBalance(BiTree *T){
	BiTree L, Lr;
	L = (*T)->lchild;
	switch (L->bf){
		case LH :
			(*T)->bf = EH;
			L->bf = EH;
			R_Rotate(T);
			break;
		
		case RH :
			Lr = L->rchild;
			switch (Lr->bf){
				case LH :
					(*T)->bf = RH;
					L->bf = EH;
					break;
				
				case EH :
					(*T)->bf = EH;
					L->bf = EH;
					break;
			}
			Lr->bf = EH;
			L_Rotate(&(T)->lchild);
			R_Rotate(T);
	}
}

