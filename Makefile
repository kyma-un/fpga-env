TARGET=top
TOP=top
GATE_DIR=build/gateware
SOFT_DIR=build/software
LITEX_DIR=/home/carlos/Embedded/litex/
SERIAL=/dev/tty.usbserial-0001
all: gateware firmware

CFLAGS+=-Isrc/utils

${GATE_DIR}/${TARGET}.bit:
	python ./base.py

gateware: ${GATE_DIR}/${TARGET}.bit

${SOFT_DIR}/common.mak: gateware

firmware: ${SOFT_DIR}/common.mak
	$(MAKE) -C src/ -f Makefile all

litex_term: firmware
	litex_term ${SERIAL} --kernel src/hello_world.bin


configure: ${GATE_DIR}/${TARGET}.bit
	sudo openFPGALoader -c ft232RL --pins=0:3:4:1 -m ${GATE_DIR}/${TARGET}.bit
