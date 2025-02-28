typedef struct {  // 类型定义
    char ch[500];
    int length;
} SString;

int Index(SString S, SString T) {  // 普通模式匹配
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T.length) {
        return i - T.length;  // 匹配成功
    } else {
        return 0;  // 匹配失败
    }
}

int Index_KMP(SString S, SString T, int next[]) {  // KMP
    int i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j > T.length) {
        return i - T.length;  // 匹配成功
    } else {
        return 0;  // 匹配失败  
    }
}

int Index(SString S, SString T) {  // nextval 版本的 KMP
    int* next = (int *) malloc (sizeof(int) * (T.length + 1));
    int* nextval = (int *) malloc (sizeof(int) * (T.length + 1));
    next[1] = nextval[1] = 0;

    int i = 1, j = 0;
    while (i < T.length) {
        if (j == 0 || T.ch[i] == T.ch[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }

    for (i = 2; i <= T.length; i++) {
        if (T.ch[next[i]] == T.ch[i]) {
            nextval[i] = nextval[next[i]];
        } else {
            nextval[i] = next[i];
        }
    }

    i = 1, j = 1;
    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j > T.length) {
        free(next); free(nextval);
        return i - T.length;
    } else {
        free(next); free(nextval);
        return 0;
    }
}
