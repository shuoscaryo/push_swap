all:
	gcc -Iinclude -Ilib/libft/include src/* lib/libft/libft.a -o push_swap