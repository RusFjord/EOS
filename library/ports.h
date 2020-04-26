#ifndef PORTS_H
#define PORTS_H

extern unsigned char inb (unsigned short port);
extern void outb (unsigned short port, unsigned char data);
extern unsigned short inw (unsigned short port);
extern void outw (unsigned short port, unsigned short data);

#endif // PORTS_H