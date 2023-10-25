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
