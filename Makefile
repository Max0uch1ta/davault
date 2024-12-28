
main : davault.c
	gcc -g -Wall davault.c -o davault

clean: 
	rm -r ~/.local/share/davault/
