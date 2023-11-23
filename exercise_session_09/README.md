# Exercise 1
I observe changes in the terminal output from compiling the file with the -0g flag. It tells me that it saves files into a new directory.
```
WARNING: PerfTools is saving object files from a temporary directory into directory '/users/fmerz/.craypat/nbody/244369'
INFO: creating the PerfTools-instrumented executable 'nbody' (lite-samples) ...OK
```

Details about the output structure in the manual:

At the end of normal program execution, Perftools-Lite produces the following output:
A text report to stdout, profiling the program’s behavior, identifying where the program spends its execution time, and offering recommendations for further analysis and possible optimizations.
An experiment data directory, with contents including the following.
A rpt-files subdirectory, which contains a copy of the text report.
An ap2-files subdirectory, which contains processed data files, in the format required to examine the program’s behavior more closely using Cray Apprentice2 or pat_report.
An xf-files subdirectory, which contains the raw data files written by the instrumented executable.
One or more MPICH_RANK_ORDER_FILE files (each with different suffixes), containing suggestions for optimizing MPI rank placement in subsequent program runs. The number and types of files produced is determined by the information captured during program execution. The files can include rank reordering suggestions based on sent message data from MPI functions, time spent in user functions, or a hybrid of the two.

All of the time is spent in the forces function. It says for 61% of the samples the code was in line 23, which means line 22 took the most time. This makes sense because line 22 contains a division.

# Exercise 2
```
ssh -i .ssh/sciencecloud.key  ubuntu@172.23.53.206
sudo apt update
sudo apt-get install -y cowsay
cowsay hello
```

```
sudo abt update
    sudo install cowsay
sudo apt-get install -y cowsay
cowsay hello

git clone https://github.com/jbucko/hpc_esc_401.git
sudo apt install g++
sudo apt install make
cd hpc_esc_401/exercise_session_09/poisson_solver_serial/
make
./main
sudo apt install -q python3-pip
pip3 install matplotlib
pip3 install tk
sudo apt install -q python-tk

python3 output/plot.py 
python3 output/plot.py 
    display output/test.png 
open output/test.png
```

## Bonus
I used the solutions provided in the course repository. In the Makefile I changed the second line to `CC=g++`. Then I compiled and ran it. It was all I had to do.


# Exercise 3
I ran these commands
```
sudo docker build --tag poisson .
sudo docker images
sudo docker run poisson
```

I couldn't mount a folder. I tried the command from the lecture slides with "--mount" and an alternative with "-v".
```
sudo docker run --rm --mount type=bind,source=/home/ubuntu,target=/home/ubuntu/hpc_esc_401/exercise_session_09/poisson_solver_serial poisson
```
I also tried this
```
sudo docker run poisson -v ./output:/home/ubuntu/hpc_esc_401/exercise_session_09/poisson_solver_serial
```

docker tag poisson:latest <Docker ID>/poisson:latest
Docker ID refers to my Docker Hub username.
```
sudo docker tag poisson:latest felixmerz/poisson:latest
sudo docker login
sudo docker push felixmerz/poisson:latest
```
