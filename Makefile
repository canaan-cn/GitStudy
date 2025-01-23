# 根目录 Makefile
all:
	$(MAKE) -C source
	$(MAKE) -C mod
	ln -sf mod/copy copy
clean:
	$(MAKE) -C source clean
	$(MAKE) -C mod clean
