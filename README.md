light52
=======

Yet another free 8051 FPGA core.

This is a 6-clocker-equivalent implementation of the MCS51 architecture, aiming at area performance.

## Status

This project has been frozen in a relatively immature state: 

* Design and implementation finished.
* Already tried on real hardware (Dhrystone demo on Cyclone-2 FPGA).
* No documentation other than this readme file and a draft of the datasheet.
* Has not yet passed a rigorous test bench.


The core has already passed a basic test bench and executed a Dhrystone benchmark
on actual hardware (DE-1 board from Terasic), compiled with SDCC (source and benchmark 
results included -- see datasheet). Yet, there are still many loose ends and a strong test bench 
has yet to be developed.

All the core features are described in detail [in the datasheet](https://github.com/jaruiz/light52/blob/master/doc/light52_ds.pdf?raw=true).

### Refactor in Progress

At the time of writing this (early May 2017) I'm beginning a refactor of the project that will make it less Windows-centric and will remove the dependency from Modelsim, among other changes. 

When the refactor is complete, quick start instructions will be added to this readme file.
In the meantime you can probably expect lots of breakage; as of right now, only two of the test programs (`cpu_test` and `hello_c`) actually work and there's no synthesis script for any target. The RTL should work just fine, though.

For the time being, if you plan to use this core at all you should use the Opencores version (see below).

### Next Steps

If I ever have any quality spare time again, I'd like to make this project actually useable in real life projects.  This will involve at least the following:

* A stronger test bench. This is by far the most important.
* An usage tutorial, single-stepping the creation of a simple project around the core.
* Some basic design documentation, necessary for maintenance.
* A detailed explanation of the cosimulation feature used by the test scheme.
* Better comments in the ISS source code.
* A decent command line interface for the ISS.
* Some support for cycle-accurate simulation of peripherals.


Also, the core needs some sort of on-chip debugging capability, ideally something that can be plugged on to an existing IDE. This feature is arguably not strictly necessary for the kind of project this core is better suited to, but I'm afraid it's going to be seen as a must for projects in which the CPU interacts with off-chip devices.

So, to summarize, the project is stalled a bit short of completion. However, it can be used with very little effort in any project where the risk of using a weakly verified CPU is acceptable.

### Warning

Until the core passes a really exhaustive test bench, you use this core at your
own risk -- it has worked so far but it may still have bugs.
If you want to try it anyway, check out file /doc/quickstart.txt and 
don't hesitate to contact me if you need help!


## Project replicated in OpenCores

This project started life in [Opencores](http://opencores.org/project,light52) before being moved here in 2016 or so. 

The Opencores version will remain frozen there for as long as Opencores itself is up.
