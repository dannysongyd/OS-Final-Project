# OS-Final-Project

## Team members

1. Danny Song - ys4242
2. Wenbo Nan - wn391

## How to compile

### 1. Get permission on the script files

```
chmod +x build.sh
chmod +x part2.sh
chmod +x part3and4.sh
chmod +x part5.sh
```

### 2. Compile C programs

`./build.sh`

## Part 1

```
./run <filename> [-r|-w] <block_size> <block_count>
```

```
➜  OS-Final-Project git:(main) ✗ ./run ubuntu -r 262144 107522
xor is a7eeb2d9
➜  OS-Final-Project git:(main) ✗ ./run testWrite -w 2621 107522
File craeted
```

## Part 2

```
./part2.sh
```

```
➜  OS-Final-Project git:(main) ✗ ./part2.sh
Running experiment for part 2

time: 2.674458
Given block_size 1024 (0.000977 MB), our program can read block_count: 4194304 in 2.674458 seconds
File size read 4294967296 bytes (4.000000 GB)
Reading speed is: 1531.525266 Mib/s
-----------------------

time: 1.479322
Given block_size 2048 (0.001953 MB), our program can read block_count: 2097152 in 1.479322 seconds
File size read 4294967296 bytes (4.000000 GB)
Reading speed is: 2768.835994 Mib/s
-----------------------

time: 0.890077
Given block_size 4096 (0.003906 MB), our program can read block_count: 1048576 in 0.890077 seconds
File size read 4294967296 bytes (4.000000 GB)
Reading speed is: 4601.849054 Mib/s
-----------------------

time: 0.587356
Given block_size 8192 (0.007812 MB), our program can read block_count: 524288 in 0.587356 seconds
File size read 4294967296 bytes (4.000000 GB)
Reading speed is: 6973.624173 Mib/s
-----------------------

time: 0.432374
Given block_size 16384 (0.015625 MB), our program can read block_count: 262144 in 0.432374 seconds
File size read 4294967296 bytes (4.000000 GB)
Reading speed is: 9473.280077 Mib/s
-----------------------

time: 0.339365
Given block_size 32768 (0.031250 MB), our program can read block_count: 131072 in 0.339365 seconds
File size read 4294967296 bytes (4.000000 GB)
Reading speed is: 12069.600578 Mib/s
-----------------------

...................................
...................................

```

## Part 3 and Part 4

```
./part3and4.sh
```

```
➜  OS-Final-Project git:(main) ✗ ./part3and4.sh
Running experiment for part 3 and 4

Block Size: 1024
Uncached:
Given block_size 1024 (0.000977 MB), our program can read block_count: 4194304 in 1.751466 seconds
File size read 4294967296 bytes (4.000000 GB)
Reading speed is: 2338.612340 Mib/s
Reading speed is: 2452212772.614484 B/s

Cached:
Given block_size 1024 (0.000977 MB), our program can read block_count: 4194304 in 1.582952 seconds
File size read 4294967296 bytes (4.000000 GB)
Reading speed is: 2587.570564 Mib/s
Reading speed is: 2713264392.097802 B/s

dd command:
4194304+0 records in
4194304+0 records out
4294967296 bytes transferred in 2.791020 secs (1538852125 bytes/sec)
-----------------------

Block Size: 2048
Uncached:
Given block_size 2048 (0.001953 MB), our program can read block_count: 2097152 in 1.115706 seconds
File size read 4294967296 bytes (4.000000 GB)
Reading speed is: 3671.218045 Mib/s
Reading speed is: 3849551132.646055 B/s

Cached:
Given block_size 2048 (0.001953 MB), our program can read block_count: 2097152 in 0.939261 seconds
File size read 4294967296 bytes (4.000000 GB)
Reading speed is: 4360.875199 Mib/s
Reading speed is: 4572709072.345174 B/s

dd command:
2097152+0 records in
2097152+0 records out
4294967296 bytes transferred in 1.613567 secs (2661784105 bytes/sec)
-----------------------

Block Size: 4096
Uncached:
Given block_size 4096 (0.003906 MB), our program can read block_count: 1048576 in 0.778125 seconds
File size read 4294967296 bytes (4.000000 GB)
Reading speed is: 5263.935743 Mib/s
Reading speed is: 5519636685.622490 B/s

Cached:
Given block_size 4096 (0.003906 MB), our program can read block_count: 1048576 in 0.620451 seconds
File size read 4294967296 bytes (4.000000 GB)
Reading speed is: 6601.649445 Mib/s
Reading speed is: 6922331168.778840 B/s

dd command:
1048576+0 records in
1048576+0 records out
4294967296 bytes transferred in 1.054411 secs (4073332497 bytes/sec)
-----------------------

..........................
```

## Part 5

```
./part5.sh

```

```
➜  OS-Final-Project git:(main) ✗ ./part5.sh
Running experiment for part 5

Block Count: 1024
read() Time is 0.001066
Reading speed is: 0.916100 Mib/s
Reading speed is: 960600.375235 B/s

lseek() Time is 0.000588
Reading speed is: 1.660821 Mib/s
Reading speed is: 1741496.598639 B/s
-----------------------

Block Count: 2048
read() Time is 0.001668
Reading speed is: 1.170938 Mib/s
Reading speed is: 1227817.745803 B/s

lseek() Time is 0.000936
Reading speed is: 2.086672 Mib/s
Reading speed is: 2188034.188034 B/s
-----------------------

Block Count: 4096
read() Time is 0.002800
Reading speed is: 1.395089 Mib/s
Reading speed is: 1462857.142857 B/s

lseek() Time is 0.001584
Reading speed is: 2.466067 Mib/s
Reading speed is: 2585858.585859 B/s
-----------------------

Block Count: 8192
read() Time is 0.004829
Reading speed is: 1.617830 Mib/s
Reading speed is: 1696417.477739 B/s

lseek() Time is 0.002635
Reading speed is: 2.964896 Mib/s
Reading speed is: 3108918.406072 B/s
-----------------------

............................
```

## Part 6

```
sudo purge
./fast ubuntu
```

```
➜  OS-Final-Project git:(main) ✗ sudo purge
➜  OS-Final-Project git:(main) ✗ ./fast ubuntu
The best block_size we tested is 262144 bytes
Reading given file ubuntu with file size 2818738176(2.625154 GB)

Raw performance
xor is a7eeb2d9
Reading speed is: 3177.365057 Mib/s

Cached performance
xor is a7eeb2d9
Reading speed is: 3627.251345 Mib/s
```
