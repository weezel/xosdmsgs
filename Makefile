CC		 = clang
CFLAGS		+= -std=c99 -Wall -Wextra -pedantic
INCLUDES	 = -I /usr/include
OS		 = $(shell uname)

ifeq ($(OS), Linux)
	LDFLAGS	 = $(shell xosd-config --libs)
	CFLAGS	+= -fsanitize=address
endif

ifeq ($(OS), OpenBSD)
	INCLUDES	+= -I /usr/local/include
	LDFLAGS		+= -L /usr/local/lib $(shell xosd-config --libs)
endif

.PHONY: all clean xosd

all: xosd

xosd:
	${CC} ${CFLAGS} ${INCLUDES} xosdmsgs.c -o xosdmsgs \
		${LDFLAGS}
clean:
	rm -f macvendor *.core *.o

