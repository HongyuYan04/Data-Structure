// 顺序表的定义：
// 静态分配
#define MAXSIZE 100
#define ElemType int
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;

// 动态分配
#define InitSize 100
#define ElemType int
#define Increment 20
typedef struct {
    ElemType *data;
    int MaxSize, length;
} SqList;

// 初始化：
bool InitList(SqList *L) {
    L->length = 0;
}

bool InitList(SqList *L) {
    L->data = (ElemType *) malloc (sizeof(ElemType) * InitSize);
    if (L->data == NULL) {
        return false;
    }
    L->MaxSize = InitSize;
    L->length = 0;
    return true;
}
