
CC = gcc
CFLAGS = -O2

# Source files
SRCS = mul_ijk.c mul_jik.c mul_kij.c mul_ijk8192.c mul_jik8192.c mul_kij8192.c \
       mul_ijk_b.c mul_jik_b.c mul_kij_b.c mul_ijk_b8192.c mul_jik_b8192.c mul_kij_b8192.c\
       mul_ijk_c.c mul_jik_c.c mul_kij_c.c mul_ijk_c8192.c mul_jik_c8192.c mul_kij_c8192.c

# Object files
OBJS = $(SRCS:.c=.o)

# Targets
all: ijk jik kij ijk_b jik_b kij_b  ijk_c jik_c kij_c ijk8192 jik8192 kij8192 ijk_b8192 jik_b8192 kij_b8192 ijk_c8192 jik_c8192 kij_c8192

ijk: mul_ijk.c
	$(CC) $(CFLAGS) -o ijk mul_ijk.c

jik: mul_jik.c
	$(CC) $(CFLAGS) -o jik mul_jik.c

kij: mul_kij.c
	$(CC) $(CFLAGS) -o kij mul_kij.c

ijk_b: mul_ijk_b.c
	$(CC) $(CFLAGS) -o ijk_b mul_ijk_b.c

jik_b: mul_jik_b.c
	$(CC) $(CFLAGS) -o jik_b mul_jik_b.c

kij_b: mul_kij_b.c
	$(CC) $(CFLAGS) -o kij_b mul_kij_b.c
	
ijk_c: mul_ijk_c.c
	$(CC) $(CFLAGS) -o ijk_c mul_ijk_c.c

jik_c: mul_jik_c.c
	$(CC) $(CFLAGS) -o jik_c mul_jik_c.c

kij_c: mul_kij_c.c
	$(CC) $(CFLAGS) -o kij_c mul_kij_c.c

ijk8192: mul_ijk8192.c
	$(CC) $(CFLAGS) -o ijk8192 mul_ijk8192.c

jik8192: mul_jik8192.c
	$(CC) $(CFLAGS) -o jik8192 mul_jik8192.c

kij8192: mul_kij8192.c
	$(CC) $(CFLAGS) -o kij8192 mul_kij8192.c

ijk_b8192: mul_ijk_b8192.c
	$(CC) $(CFLAGS) -o ijk_b8192 mul_ijk_b8192.c

jik_b8192: mul_jik_b8192.c
	$(CC) $(CFLAGS) -o jik_b8192 mul_jik_b8192.c

kij_b8192: mul_kij_b8192.c
	$(CC) $(CFLAGS) -o kij_b8192 mul_kij_b8192.c
	
ijk_c8192: mul_ijk_c8192.c
	$(CC) $(CFLAGS) -o ijk_c8192 mul_ijk_c8192.c

jik_c8192: mul_jik_c8192.c
	$(CC) $(CFLAGS) -o jik_c8192 mul_jik_c8192.c

kij_c8192: mul_kij_c8192.c
	$(CC) $(CFLAGS) -o kij_c8192 mul_kij_c8192.c

clean:
	rm -f ijk jik kij ijk_b jik_b kij_b ijk_c jik_c kij_c ijk8192 jik8192 kij8192 ijk_b8192 jik_b8192 kij_b8192 ijk_c8192 jik_c8192 kij_c8192 *.o

