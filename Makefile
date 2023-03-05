all: compile

compile:
	gcc server.c erproc.c -W -Wall -Werror -std=c99 -o server
	gcc client.c erproc.c -W -Wall -Werror -std=c99 -o client

clean:
	rm -rf server client