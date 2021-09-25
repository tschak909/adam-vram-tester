# adam-vram-tester

This is a testing program for the VRAM in the Coleco Adam computer.

It does the following upon boot-up:

* Explains what it will be doing
* Display an initial color bars screen
* Work through 15 patterns in RAM
* Display all good, if all patterns pass, otherwise an error is displayed with the address, the expected pattern, and the actual pattern returned from VRAM.

For each pattern pass:

* Random data is written to all of VRAM (0x3FFF)
* The pattern byte is written to the next address
* The pattern byte is read back from the same address
* Repeat until all VRAM address space is written to.

Each pattern is attempted 16 times.

The following patterns are written to memory:

* 0x00 (blank bits)
* 0xFF (all bits)
* 0xA5 (alternating nibbles)
* 0x5A (alternating nibbles)
* 0xAA (alternating bytes)
* 0x55 (alternating bytes)
* 0x01 (test bit 0)
* 0x02 (test bit 1)
* 0x04 (test bit 2)
* 0x08 (test bit 3)
* 0x10 (test bit 4)
* 0x20 (test bit 5)
* 0x40 (test bit 6)
* 0x80 (test bit 7)

(I briefly considered making a barber-pole or inch-worm test, but reconsidered, thinking that might be overkill!)

Author: Thom Cherryhomes <thom.cherryhomes at gmail.com>

