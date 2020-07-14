CC=g++
EXE_FILE=Run

$(EXE_FILE): student_db.o  Run.o
	$(CC) student_db.o Run.o -o $(EXE_FILE)
Run.o: Run.cpp
	$(CC) -c Run.cpp
student_db.o: student_db.cpp
	$(CC) -c student_db.cpp
	