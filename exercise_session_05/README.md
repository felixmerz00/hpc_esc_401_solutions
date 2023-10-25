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
