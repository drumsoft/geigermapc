###########################################
# Simple Makefile for HIDAPI test program
#
# Alan Ott
# Signal 11 Software
# 2010-06-01
###########################################

all: ../read-usb-geiger

CC=gcc
CXX=g++
COBJS=hid-libusb.o
CPPOBJS=../read-usb-geiger.o
OBJS=$(COBJS) $(CPPOBJS)
CFLAGS+=-I../hidapi -Wall -g -c `pkg-config libusb-1.0 --cflags`
LIBS=`pkg-config libusb-1.0 --libs`
# LIBS=`pkg-config libudev --libs`


../read-usb-geiger: $(OBJS)
	g++ -Wall -g $^ $(LIBS) -o ../read-usb-geiger

$(COBJS): %.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(CPPOBJS): %.o: %.cpp
	$(CXX) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS) ../read-usb-geiger

.PHONY: clean
