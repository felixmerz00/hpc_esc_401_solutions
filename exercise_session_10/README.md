# Exercise 2
I map each word to a count and sort them alphabetically.
```
python3 mapper.py < trump_tweets_01.csv trump_tweets_02.csv trump_tweets_03.csv trump_tweets_04.csv trump_tweets_05.csv trump_tweets_06.csv trump_tweets_07.csv | sort
```

“working”	1
“you	1
“you	1
“you	1
“you	1
…you	1
❤️	1

```
python3 mapper.py < trump_tweets_01.csv trump_tweets_02.csv trump_tweets_03.csv trump_tweets_04.csv trump_tweets_05.csv trump_tweets_06.csv trump_tweets_07.csv | sort | python3 reducer.py
```

“we	3
“when	1
“winners	1
“working”	1
“you	4
…you	1
❤️	1

```
hadoop fs -mkdir DonaldTrump
hadoop fs -ls
hadoop fs -put trump_tweets_*.csv DonaldTrump/
hadoop fs -ls DonaldTrump
./pymapred.sh
```

How many map and reduction operations were performed?
For each word one map operation is done. In total 538568 operations. There are 538568 words. 47090 of them are unique. The program performed 538568-47090=491478 reduce operations.

How many lines/entries were treated? \newline
In the mapping step 35371 lines were treated. In the reduction step 538568 were treated. \\
Map input records=35371, Reduce input records=538568 \\
These two output files were created: output/_SUCCESS and output/part-00000.

I see all the words he uses and their counts.__
hadoop fs -cat output/part-00000
“totally	1
“toure	1
“trending	1
“true	1
“trump	94
“trumpbacked	1
“trumpchicago	1

I can find the output files under the following path.
I go to http://localhost:9870/ --> Utilities --> Browse file system --> user --> ubuntu --> output
http://localhost:9870/explorer.html#/user/ubuntu
