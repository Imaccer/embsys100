# __Embedded Device Example - The Cubesat__
Using the telegraph example, and the challenges listed in the module as reference, and describe another device that you would like to discuss. Describe how you think its embedded system works, and what design challenges it presents.

<p align="center">
  <img src="cubesat_board.jpg">
</p>

# __How the Embedded System Works__

# __Design Challenges__

## __Throughput__

Cubesats typically operate in low Earth orbits, which means that they are travelling extremely fast with respect to the ground (~7 km/s). Consequently, there are only short communication windows with the ground station when the satellite can transmit and receive data. This means that the satellite must be able to process large amounts of data in short periods of time. 

Cubesats are often equipped with sensors which generate large volumes of data. A common application of cubesats is for imaging of the Earth's surface. Limited bandwidth may be available for transmission of images from cubesats to the ground. Hence, it may be necessary to perform image processing with the onboard microprocessor in order to reduce the data sufficiently for transmission. 

## __Response__ 

Cubesats must be capable of responding to information received from various sensors and acting on it quickly. For example, the satellite  may enter an uncontrolled spin and need to compute the necessary corrective action based on the gyroscope data to correct the spin as quickly as possible. It must also be able to respond immediately to commands received from the ground. For example, it may need to perform a collision avoidance maneuver if orbital debris or another satellite are going to intersect it's orbit. 

## __Testability__

Testing the satellite fully under space-like conditions on the ground is challenging. There are many situations that may occur in space which are not possible to recreate in the labarotory. 

An example of one aspect of the satellite that must be thoroughly tested is the Cubesat's de-tumbling control system and hardware. If the satellite enters an uncontrolled rotation (tumble) it must be able to quickly correct it's orientation and regain a controlled orientation. To recreate the conditions of space which impact this problem, it is necessary to use a Helmholtz coil to recreate the magnetic environment of space and a spherical air bearing which simulates the friction free environment in orbit. These two components allow for the creation of an adjustable system that simulates the satellite in orbit. 

https://www.youtube.com/watch?v=d9Cw1l7ExHE

<figure class="video_container">
<iframe width="560" height="315" src="https://www.youtube.com/embed/d9Cw1l7ExHE" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</figure>

## __Debugability__
_Without a screen or keyboard, finding out what software is doing wrong is troublesome._


## __Reliability__
Once it is launched, there is no option to physically interact with the system to address potential problems. If there is a malfunction, the system must be able to recover on its own. 

For space applications, radiation can damage electronics in two ways. Total ionizing dose (TID) is the amount of cumulative radiation received. Single event effects (SEE) is the disturbance created by single particles hitting the electronics . Total dose is measured in krad and can affect transistor performance. Single event upsets (SEU) can affect the logic state of memory. A single event latchup (SEL) can affect the output transistors on CMOS logic, potentially causing a high-current state.

 If the processor jumps to an erroneous memory location through a single-event upset or a software exception, the watchdog timer resets the processor to restore operations 11.

## __Memory Space__

TRIPLE MODULAR REDUNDANCY

Single-event upsets can interrupt discrete logic, including processing. Triple modular redundancy (TMR) is a fault mitigation technique where logic is replicated three times, and the output of the logic is determined by a majority-vote. 

Multiple copies of the firmware are also stored to mitigate against corruption of the data. Like data memory, program memory is also susceptible to single-event upsets and device failure. To counter this issue, a bootloader may be used to check the validity of the firmware and provide a mechanism for uploading new versions. Additionally, multiple copies of the firmware may be stored in memory in case the primary version is corrupt.

## __Program Installation and Upgrade__
Usually have a ground mock of the system to thoroughly test any software updates before upload to the satellite.


## __Power Consumption__
The small size of cubesats is their main advantage along with their low production cost due to the ability to manufacture at scale. However, the limited size has an impact on the available power resources. In space, solar power is widely used to power satellites. The limited real estate available to deploy solar panels on cubesats results in limited power resources. Also, the limited size restricts the available space for power storage solutions. Cubesats must be equipped with storage and low power modes when to allow for operation when the satellite is passing through the Earth's shadow. 

Since many components are more prone to radiation effects when powered on, a candidate mitigation strategy is to power off devices when they are not operationally needed.

## __Security__
Be able to prevent malicious uploads...especially for military satellites. Maintain secure communications. 


## __Cost__
Cubesats main selling point is their low cost compared to more traditional satellites. The cost per lb to lauch mass into a low earth orbit is ... Hence, minimizing the mass of the satellite is critical. Generally, the aim is to maximize the available mass for the system payload. Given the overall restrictions on mass and size, this means limiting the size and number of components. 

For satellites intended to operate beyond 6 months to 1year, their systems must also be radiation hardened to allow the electronics to operate. This incurs additional mass and hence cost. 

# __References__

https://sst-soa.arc.nasa.gov


