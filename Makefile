TARGET  = amphetamin
OBJS    = main.o blit.o font.o threads.o config.o power.o memorycard.o registry.o

LIBS    = -lSceAppMgr_stub -lSceCtrl_stub -lSceDisplay_stub -lSceFios2_stub -lSceKernel_stub -lScePower_stub -lSceLibc_stub -lSceReg_stub

PREFIX  = arm-vita-eabi
CC      = $(PREFIX)-gcc
CFLAGS  = -Wl,-q -Wall -O3 -nostartfiles
ASFLAGS = $(CFLAGS)

all: $(TARGET).suprx

%.suprx: %.velf
	vita-make-fself $< $@

%.velf: %.elf
	vita-elf-create $< $@

$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

clean:
	@rm -rf $(TARGET).suprx $(TARGET).velf $(TARGET).elf $(OBJS)

send: $(TARGET).suprx
	curl -T $(TARGET).suprx ftp://192.168.2.128:1337/ux0:/plugins/$(TARGET).suprx
	@echo "Sent."