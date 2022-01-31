// prototype
int sub2(void);
int sub3(int l, int m);

void main(void)
{
    int i = 0;
    int j = 1;

    i = sub2();
    j = i + 1;

}

int sub2(void)
{
    int i = 0;
    int j = 1;

    i = sub3(1, 2) + j;
    return (i);
}

int sub3(int l, int m)
{
    int i = 0;
    int j = 1;
    int k = 2;

        k = i + j + l + m;

    return (k);
}
