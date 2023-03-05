#defines
COMPILE=gcc
CFLAGS=-W -Wall -Werror -std=c99
SERVER=server
CLIENT=client

#path to client-server dirs
PROJECT_ROOT=$(shell pwd)
PREF_SERVER=$(PROJECT_ROOT)/server_d/
PREF_CLIENT=$(PROJECT_ROOT)/client_d/

#source server-client
SRC_SERVER=$(wildcard $(PREF_SERVER)*.c)
SRC_CLIENT=$(wildcard $(PREF_CLIENT)*.c)

all: debug

release:
	$(COMPILE) $(SRC_SERVER) $(CFLAGS) -o $(SERVER)
	$(COMPILE) $(SRC_CLIENT) $(CFLAGS) -o $(CLIENT)

debug:
	$(COMPILE) -g $(SRC_SERVER) $(CFLAGS) -o $(SERVER)
	$(COMPILE) -g $(SRC_CLIENT) $(CFLAGS) -o $(CLIENT)

clean:
	rm -rf $(SERVER) $(CLIENT)