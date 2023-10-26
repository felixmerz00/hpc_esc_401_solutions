## Exercise 2
$HOME<br>
drwx------ 14 fmerz uzh8 8192 Okt 26 12:21
For the $HOME directory I have all the permissons and the group and others have no permissions. Also I have no permission for other student's $HOME directory.
```
cd /users/jblum
-bash: cd: /users/jblum: Permission denied
```

$SCRATCH<br>
`drwxr-x---+ 2 fmerz uzh8 4096 Sep 26 17:01 /capstor/scratch/cscs/fmerz``
For the $scratch directory, again I have all the permissions. But also my group can read, access and examine what files are inside my $SCRATCH directory. Likewise I can other student's $SCRATCH directory. E.g., the command to access Jonas Blums $SCRATCH directory `cd /capstor/scratch/cscs/jblum` works.

When I create a file in my $HOME directory the default permissions allow me to read and write. Also my group and everybody else can technically read the file (if they had access to the directory). For files in my $SCRATCH directory the default permissions allow me to read and write and my group can read too.

I do not have permissions to access change my directory to /users/jbucko. jbucko can read, write and access content of this directory. Also members of his group can read the directory. But he is in groupt uzh27. I am in group uzh8. So I have no permissions whatsoever for this directory.
```
drwxr-----+ 75 jbucko uzh27 8192 Okt 26 11:55 /users/jbucko
```
I can't access the files inside the directory either, like hpc exam solution.txt. I cannot see if this file exists. The content of the direcory are inaccassible to me.


## Exercise 3
1) end with 00
grep .*00$ binary.txt
2) start and end with 1
grep ^1.*1$ binary.txt
3) contain the pattern 110
grep --color 110 binary.txt
4) contain at least three times a 1
grep '^\(0*1\)\{3,\}0*$' binary.txt
5) contain at least three consecutive 1s
grep --color 111 binary.txt


## Exerise 4
The check if the given number is prime is done in no time.

felixmerz@MacBook-Felix exercise_session_05 % time ./is-prime.sh 4230283
4230283 is prime
./is-prime.sh 4230283  0.00s user 0.01s system 101% cpu 0.013 total
felixmerz@MacBook-Felix exercise_session_05 % time ./is-prime.sh 4572862171001
4572862171001 is prime
./is-prime.sh 4572862171001  0.00s user 0.01s system 38% cpu 0.042 total
felixmerz@MacBook-Felix exercise_session_05 % time ./is-prime.sh 4572862171002
4572862171002 is composite
./is-prime.sh 4572862171002  0.00s user 0.01s system 106% cpu 0.013 total
