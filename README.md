<h1>Based client-server application</h1>

<h2>Compile server</h2>

```
 gcc server.c erproc.c -W -Wall -Werror -std=c99 -o server
```

<h2>Compile client</h2>

```
 gcc server.c erproc.c -W -Wall -Werror -std=c99 -o server
 ```

<h2>Started app</h2>
<p>For started server you need enter port what you want listen</p>

```
./server 34543
```
<p>For started client you need enter port what you want read</p> 

```
./client 34543
```