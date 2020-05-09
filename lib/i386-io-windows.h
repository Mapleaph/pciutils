/*
 *	The PCI Library -- Access to i386 I/O ports on Windows
 *
 *	Copyright (c) 2004 Alexander Stock <stock.alexander@gmx.de>
 *	Copyright (c) 2006 Martin Mares <mj@ucw.cz>
 *
 *	Can be freely distributed and used under the terms of the GNU GPL.
 */

#include <io.h>
#include <windows.h>
#include <stdbool.h>
#include "winio.h"

#define outb(x,y) SetPortVal(y, x, 1);
#define outw(x,y) SetPortVal(y, x, 2);
#define outl(x,y) SetPortVal(y, x, 4);

static int
intel_setup_io(struct pci_access *a)
{

  if (!InitializeWinIo())
    {
      a->warning("i386-io-windows: InitializeWinIo() failed.");
      return 0;
    }

  return 1;
}

static inline int
intel_cleanup_io(struct pci_access *a UNUSED)
{
  ShutdownWinIo();
  return 1;
}

static inline void intel_io_lock(void)
{
}

static inline void intel_io_unlock(void)
{
}
