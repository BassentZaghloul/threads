#target $@
#dependencies $^

src = $(wildcard *.c)
obj = $(src:.c=.o)

matMultp: $(obj)
	gcc -pthread -o matMultp $^

matmult.out: matMultp
	gcc -pthread -o matmult.out matMultp


%.o:%.c
	gcc -c $^

clean:
	rm *.o
