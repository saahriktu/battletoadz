ifeq ($(prefix),)
	prefix=/usr/local
endif
ifeq ($(shell which $(CC)),)
	CC=gcc
endif
all:
	$(CC) $(CFLAGS) -o battletoadz battletoadz.c
	strip -S battletoadz
install:
	if [ ! -d "$(DESTDIR)$(prefix)/games" ]; then mkdir -p $(DESTDIR)$(prefix)/games; fi
	install -m755 battletoadz $(DESTDIR)$(prefix)/games
clean:
	rm battletoadz
