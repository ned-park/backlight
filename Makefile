include config.mk

SRC = backlight.c
OBJ = ${SRC:.c=.o}

all: options backlight

options: 
	@echo backlight build options:
	@echo "CC = ${CC}"

.c.o:
	${CC} -c $<

${OBJ}: config.h config.mk

config.h:
	cp config.def.h $@

backlight: ${OBJ}
	${CC} -o $@ ${OBJ}

clean:
	rm -f backlight *.o

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp -f backlight ${DESTDIR}${PREFIX}/bin/
	chmod 755 ${DESTDIR}${PREFIX}/bin/backlight
	mkdir -p ${DESTDIR}${MANPREFIX}/man1
	cp -fv backlight.1 ${DESTDIR}${MANPREFIX}/man1/
	chmod 644 ${DESTDIR}${MANPREFIX}/man1/backlight.1


uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/backlight \
		${DESTDIR}${MANPREFIX}/man1/backlight.1

	


.PHONY: all options clean install uninstall
