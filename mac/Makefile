###########################################
# Simple Makefile for HIDAPI test program
#
# Alan Ott
# Signal 11 Software
# 2010-07-03
###########################################

all: ../read-usb-geiger

CC=gcc
CXX=g++
COBJS=hid.o
CPPOBJS=../read-usb-geiger.o
OBJS=$(COBJS) $(CPPOBJS)
CFLAGS+=-I../hidapi -Wall -g -c 
LIBS=-framework IOKit -framework CoreFoundation


../read-usb-geiger: $(OBJS)
	g++ -Wall -g $^ $(LIBS) -o ../read-usb-geiger

$(COBJS): %.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(CPPOBJS): %.o: %.cpp
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -f *.o ../read-usb-geiger $(CPPOBJS)

.PHONY: clean
