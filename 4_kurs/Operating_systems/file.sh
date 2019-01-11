read dirname
mkdir ~/$dirname
cd ~/$dirname
counter=1
R=16
N1=50
N2=45
r1=14
r2=16
a1=13
a2=15
a3=9
a4=10
t1=-13
t2=-12
while [[ $counter -le $R ]]
do
    echo $counter
    mkdir $counter
    cd $counter
    (( counter++ ))
done
counter=1
cd ~/$dirname/$counter
while [[ $counter -le $R ]]
do
    if [[ $counter = $r1 ]]; then
	echo $counter
	cd /home/echufy/CLionProjects/os2_process
	gcc *.c
	./a.out
	chmod 777 test_process.txt
	mv /home/echufy/CLionProjects/os2_process/test_process.txt ~/$dirname/1/2/3/4/5/6/7/8/9/10/11/12/13/14
    elif [[ $counter = $r2 ]]; then
	echo $counter
	cd /home/echufy/CLionProjects/os2_thread
	gcc *.c -pthread
	./a.out
	chmod 777 test_thread.txt
	mv /home/echufy/CLionProjects/os2_thread/test_thread.txt ~/$dirname/1/2/3/4/5/6/7/8/9/10/11/12/13/14/15/16
    fi
    echo $counter
    (( counter++ ))
    if [[ -f "/$counter" ]]; then
	cd $counter
	fi
done
cd
tar -cvf process.tar ~/$dirname/1/2/3/4/5/6/7/8/9/10/11/12/13/14/
mv ~/process.tar ~/$dirname/1/2/3/4/5/6/7/8/9/10/11/12/13
tar -cvf thread.tar ~/$dirname/1/2/3/4/5/6/7/8/9/10/11/12/13/14/15/16
mv ~/thread.tar ~/$dirname/1/2/3/4/5/6/7/8/9/10/11/12/13/14/15
cd ~/$dirname/1/2/3/4/5/6/7/8/9/10/11/12/13/14
ls -alS > sort_file.txt
mv sort_file.txt ~/$dirname/1/
cp ~/$dirname/1/sort_file.txt ~/$dirname/1/2/3/4/5/6/7/8/9/10/11/12/13
cd ~/$dirname/1/2/3/4/5/6/7/8/9/10/11/12/13/14/15/16
ls -alS > sort_file2.txt
mv sort_file2.txt ~/$dirname/1/2/3/4
cp ~/$dirname/1/2/3/4/sort_file2.txt ~/$dirname/1/2/3/4/5/6/7/8/9/10/11/12/13/14/15
cd
tar -cvf result1.tar ~/$dirname/1/2/3/4/5/6/7/8/9/10/11/12/13
mv ~/result1.tar ~/$dirname/1/2/3/4/5/6/7/8/9
cd ~/$dirname/1/2/3/4/5/6/7/8/9
tar -xvf ~/$dirname/1/2/3/4/5/6/7/8/9/result1.tar
cd
tar -cvf result2.tar ~/$dirname/1/2/3/4/5/6/7/8/9/10/11/12/13/14/15
mv ~/result2.tar ~/$dirname/1/2/3/4/5/6/7/8/9/10
cd ~/$dirname/1/2/3/4/5/6/7/8/9/10
tar -xvf ~/$dirname/1/2/3/4/5/6/7/8/9/10/result2.tar
