# Folder references
CONTIKI = /home/andrea/Softwares/contiki/
# CONTIKI = INSERT HERE YOUR PATH TO Contiki

TARGET=sky

all: main

PROJECT_SOURCEFILES += struct2packet.c

include $(CONTIKI)Makefile.include
