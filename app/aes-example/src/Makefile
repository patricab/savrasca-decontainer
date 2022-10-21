NAME=aes
ARCH=atmega128
# ARCH=atmega16
# MCU=atmega163

CC=avr-gcc -g -mmcu=$(ARCH)
AS=avr-gcc -g -c -mmcu=$(ARCH) -x assembler-with-cpp -lm
OBJCOPY=avr-objcopy
SIZE=avr-size

# CFLAGS=-Wall -I. -O2 -mcall-prologues
CFLAGS=-Wall -I. -mcall-prologues
# ASFLAGS=-Wall -I. -O2 

#CFLAGS=-Wall -I. -O0 -mcall-prologues
#ASFLAGS=-Wall -I. -O0 

# CSRC= \
# 	main.c \
# 	aes.c \

CSRC = $(wildcard *.c)

# SSRC= \
# 	gf256mul.S \
# 	aes_sbox-asm.S \

OBJ=$(CSRC:.c=.o)
# OBJ=$(CSRC:.c=.o) $(SSRC:.S=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lc -lm -Wl,-Map,$(NAME).map -o $(NAME) $(OBJ) -lm
	$(SIZE) $(NAME)
	$(CC) -o $(NAME).elf $(OBJ)
	# avr-gcc -g -mmcu=$(MCU) -o $(NAME).elf $(OBJ)
	$(OBJCOPY) -O binary $(NAME) $(NAME).bin
	$(OBJCOPY) -O ihex $(NAME) $(NAME).hex

# sloc:
# 	@echo
# 	@echo Lines of code
# 	@sloccount $(SLOCFILES) | grep -A 1000 "SLOC-by-Language" | grep -v "^$$"

# calltree:
# 	@echo
# 	@echo Calltree
# 	@/opt/schily/bin/calltree -m -I. -I/opt/avrgcc/avr/include/ -I/usr/lib/avr/include/ -D__AVR_ATmega163__ $(CALLTREEFILES)

# calldepth:
# 	@echo
# 	@echo Calldepth
# 	@/opt/schily/bin/calltree -m -I. -I/opt/avrgcc/avr/include/ -I/usr/lib/avr/include/ -D__AVR_ATmega163__ $(CALLTREEFILES) | sed -e "s/[^ ].*$$//" -e "s/    /#/g" -e "s/#/1/" -e "s/#/2/" -e "s/#/3/" -e "s/#/4/" -e "s/#/5/" -e "s/#/6/" -e "s/#/7/" -e "s/#/8/" -e "s/#/9/" -e "s/#/0/" | sort | tail -1

# uncalled:
# 	@echo
# 	@echo Uncalled
# 	@/opt/schily/bin/calltree -u -I. -I/opt/avrgcc/avr/include/ -I/usr/lib/avr/include/ -D__AVR_ATmega163__ $(CALLTREEFILES)

# statistics: sloc calldepth uncalled

clean: clean-$(NAME)
	rm -rf core

clean-$(NAME):
	rm -rf $(OBJ) $(NAME) $(NAME).bin $(NAME).hex $(NAME).map $(NAME).elf ../inputs.csv ../traces ../traces_exe