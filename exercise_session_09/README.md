# Exercise 1
I observe changes in the terminal output from compiling the file with the -0g flag. It tells me that it saves files into a new directory.
```
WARNING: PerfTools is saving object files from a temporary directory into directory '/users/fmerz/.craypat/nbody/244369'
INFO: creating the PerfTools-instrumented executable 'nbody' (lite-samples) ...OK
```

Perftools-Lite produces a folder containing different output files. 
* In the folder rpt-files the file RUNTIME.rpt contains a report about my program with the most important information and analysis including which line takes the most time. Some of the content is also printed into tghe output file from my slurm job.
* The ap2-files subdirectory contains files that are needed for the examination of my program.
All of the time is spent in the forces function. It says for 61% of the samples the code was in line 23, which means line 22 took the most time. This makes sense because line 22 contains a division.
* The xf-files subdirectory contains some other files with raw data.
* Also there is a file called "index.ap2" that I can't open.

# Exercise 2
```
ssh -i .ssh/sciencecloud.key  ubuntu@172.23.53.206
sudo abt update
sudo apt-get install -y cowsay
cowsay hello
 _______
< hello >
 -------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||

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
This is the content of my Dockerfile. 
```
# syntax=docker/dockerfile:1

FROM ubuntu:latest
COPY . /docker-container-folder
RUN apt-get update && apt-get install -y g++ && apt-get install -y make
WORKDIR docker-container-folder/
CMD make all && ./main
```

I ran these commands.
```
sudo docker build --tag poisson .
sudo docker images
sudo docker run poisson
```
With these commands I get no output in my output folder. I ran my poisson image again and mounted my own output folder which is located in the same directory as my Dockerfile.
```
sudo docker run -v ./output:/docker-container-folder/output poisson
```

In the given command `docker tag poisson:latest <Docker ID>/poisson:latest` Docker ID refers to my Docker Hub username.
```
sudo docker tag poisson:latest felixmerz/poisson:latest
sudo docker login
sudo docker push felixmerz/poisson:latest
```
