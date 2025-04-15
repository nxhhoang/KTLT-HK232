int calcSum(int *ptr, int n)
{
    if (n==0) return 0;
    return *ptr + calcSum(ptr + 1, n-1);
}
