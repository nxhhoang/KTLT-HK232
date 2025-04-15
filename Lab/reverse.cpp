void reverse(int *ptr, int n)
{
	if (n <= 1) return;
	swap(*ptr, *(ptr + n - 1));
	reverse(ptr + 1, n - 2);
}
