# __Embedded Device Example - The Cubesat__
Using the telegraph example, and the challenges listed in the module as reference, and describe another device that you would like to discuss. Describe how you think its embedded system works, and what design challenges it presents.

<p align="center">
  <img src="cubesat_board.jpg">
</p>

## __Throughput__
Short communication windows with the ground station. Must be ready to transmit or receive data when making a pass over a ground station (while travelling at 7km/s).
## __Response__ 
Responding to information received from various sensors and acting on it. For example, it may enter an uncontrolled spin and need to act quickly on the gyroscope data to correct the spin as quickly as possible. It must also be able to respond immediately to commands received from the ground. For example, it may need to perform a collision avoidance maneuver if orbital debris or another satellite going to intersect it's orbit. 
## __Testability__
Testing the satellite fully under space-like conditions is challenging. 

## __Debugability__

## __Reliability__
Once it is launched...
## __Memory Space__

## __Program Installation and Upgrade__
Usually have a ground mock of the system to thoroughly test any software updates before upload to the satellite.

## __Power Consumption__
Rely on solar panels for power, what limit? Also, when in Earth's shadow no incoming power. Different power modes. 
## __Security__

## __Cost__
Cubesats main selling point is low cost compared to more traditional satellites. The cost per lb to lauch mass into a low earth orbit is ..., hence, minimizing the mass of the satellite is important. 

