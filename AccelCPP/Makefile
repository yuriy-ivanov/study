CC=g++
CFLAGS=-c -Wall
LIB=lib/functions.o

all: ch2 ch3 ch4 ch5 ch6 ch7 ch8 ch9 ch10 ch11 ch12
	

ch2: lib
	$(CC) $(LIB) chap2/Task_2_0.cpp -o bin/task_2_0.exe
	$(CC) $(LIB) chap2/Task_2_1.cpp -o bin/task_2_1.exe
	$(CC) $(LIB) chap2/Task_2_2.cpp -o bin/task_2_2.exe
	$(CC) $(LIB) chap2/Task_2_3.cpp -o bin/task_2_3.exe
	$(CC) $(LIB) chap2/Task_2_4.cpp -o bin/task_2_4.exe
	$(CC) $(LIB) chap2/Task_2_5.cpp -o bin/task_2_5.exe
	$(CC) $(LIB) chap2/Task_2_7.cpp -o bin/task_2_7.exe
	$(CC) $(LIB) chap2/Task_2_8.cpp -o bin/task_2_8.exe
	$(CC) $(LIB) chap2/Task_2_9.cpp -o bin/task_2_9.exe

ch3: lib
	$(CC) $(LIB) chap3/Task_3_2.cpp -o bin/task_3_2.exe
	$(CC) $(LIB) chap3/Task_3_3.cpp -o bin/task_3_3.exe
	$(CC) $(LIB) chap3/Task_3_4.cpp -o bin/task_3_4.exe

ch4: lib
	$(CC) $(LIB) chap4/task_4_0/*.cpp -o bin/task_4_0.exe
	$(CC) $(LIB) chap4/Task_4_2.cpp -o bin/task_4_2.exe
	$(CC) $(LIB) chap4/Task_4_3.cpp -o bin/task_4_3.exe
	$(CC) $(LIB) chap4/Task_4_4.cpp -o bin/task_4_4.exe
	$(CC) $(LIB) chap4/task_4_5/*.cpp -o bin/task_4_5.exe
	$(CC) $(LIB) chap4/task_4_6/*.cpp -o bin/task_4_6.exe
	$(CC) $(LIB) chap4/task_4_7/*.cpp -o bin/task_4_7.exe

ch5: lib
	$(CC) $(LIB) chap5/Task_5_0.cpp -o bin/task_5_0.exe
	$(CC) $(LIB) chap5/Task_5_2.cpp -o bin/task_5_2.exe
	$(CC) $(LIB) chap5/Task_5_3.cpp -o bin/task_5_3.exe
	$(CC) $(LIB) chap5/Task_5_9.cpp -o bin/task_5_9.exe
	$(CC) $(LIB) chap5/Task_5_10.cpp -o bin/task_5_10.exe
	$(CC) $(LIB) chap5/Task_5_11.cpp -o bin/task_5_11.exe

ch6: lib
	$(CC) $(LIB) chap6/Task_6_0.cpp -o bin/task_6_0.exe
	$(CC) $(LIB) chap6/Task_6_3.cpp -o bin/task_6_3.exe
	$(CC) $(LIB) chap6/Task_6_9.cpp -o bin/task_6_9.exe

ch7: lib
	$(CC) $(LIB) chap7/Task_7_0_1.cpp -o bin/task_7_0_1.exe
	$(CC) $(LIB) chap7/Task_7_0_2.cpp -o bin/task_7_0_2.exe
	$(CC) $(LIB) chap7/Task_7_0_3.cpp -o bin/task_7_0_3.exe
	$(CC) $(LIB) chap7/Task_7_2.cpp -o bin/task_7_2.exe

ch8: lib
	$(CC) $(LIB) chap8/Task_8_2.cpp -o bin/task_8_2.exe
	$(CC) $(LIB) chap8/Task_8_5.cpp -o bin/task_8_5.exe

ch9: lib
	$(CC) $(LIB) chap9/Task_9_0.cpp -o bin/task_9_0.exe
	$(CC) $(LIB) chap9/Task_9_3.cpp -o bin/task_9_3.exe

ch10: lib
	$(CC) $(LIB) chap10/Task_10_3.cpp -o bin/task_10_3.exe
	$(CC) $(LIB) chap10/Task_10_4.cpp -o bin/task_10_4.exe

ch11: lib
	$(CC) $(LIB) chap11/Task_11_0.cpp -o bin/task_11_0.exe
	$(CC) $(LIB) chap11/Task_11_8.cpp -o bin/task_11_8.exe

ch12: lib
	$(CC) $(LIB) chap12/Task_12_0.cpp -o bin/task_12_0.exe

lib:
	$(CC) $(CFLAGS) functions.cpp -o $(LIB)

clean:
	del /Q lib\*.* 
	del /Q bin\*.*
