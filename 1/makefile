caller:caller.c twoSum.c gen.c
	gcc -std=c99 -O2 caller.c -o caller
	gcc -std=c99 -O2 -DNLOGNOPT caller.c -o caller_opt
	gcc -std=c99 -O2 gen.c -o gen
clean:
	rm caller caller_opt gen
