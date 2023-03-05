all: release

release:
	gcc server.c erproc.c -W -Wall -Werror -std=c99 -o server
	gcc client.c erproc.c -W -Wall -Werror -std=c99 -o client

debug:
	gcc -d server.c erproc.c -W -Wall -Werror -std=c99 -o server
	gcc -d client.c erproc.c -W -Wall -Werror -std=c99 -o client

clean:
	rm -rf server client