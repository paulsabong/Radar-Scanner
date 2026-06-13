# Radar Scanner 

## Background 
Radar scanners are widely used in Aerospace & Defense, such as detecting extraterrestrial objects and aircrafts for security. The scope of this project will be limited to ground object detection within less than 10 meters. 

## Core Principles
### Sensor Device
An ultrasonic sensor, HC-SR04, was used to detect objects using ultrasonic waves. Ultrasonic waves fall within 20kHz to 40kHz, which isn’t audible to the human ear. The two components/pins, echo and trig, enable the device to transmit this soundwave to and from a nearby object, calculating the total time duration for this process. This process is called echoing. 

To read more about how ultrasonic sensors work, [Click Here](https://www.allaboutcircuits.com/industry-articles/understanding-the-basics-of-ultrasonic-proximity-sensors/). 

### Measuring Device 

Since the goal is to measure the distance of the object, the kinematic equation can be used, 

$v = d/t$

Re-arranging for $d$, 

$d= vt$

Where $d$ is the distance (in cm) from the sensor to the object, $v$ is the air speed, 343 m/s or 0.0343 cm/µs, and $t$ is the time (in µs) taken for the soundwave to travel to and from the object. 

Since the total distance of the soundwave is twice the object’s range, the above equation will be adjusted to, 

$2d = vt$

$d = vt/2$

### Visualizing Radar Scanner

The software, Processing, was used to visualize object detection. In essence, the Arduino would send data to the serial port, and Processing would access the same serial port and interpret that data. In this project, the angle and distance at which the object was detected would be sent to the serial. In Processing, a radar line would move clockwise and counterclockwise given the angle value. At some distance and area, the object detected would be marked in red. 

## References
Reference Project: [Click Here](https://projecthub.arduino.cc/diegogalvan_1294/building-an-ultrasonic-radar-using-arduino-and-processing-59053e) 

Original Processing Code: [Click Here](https://hackaday.io/project/14871-make-a-radar-station-with-arduino-and-processing/details)

## Build Instructions

### Software Tools Required
- Arduino IDE or VS Code
- Processing 4.0 or later

### Material Requirements
- Arduino / ELEGOO UNO R3
- Prototyping board
- Wires
- HC-SR04 
- Micro Servo Motor
- Optional:
  - 100uF Polarized Capacitor

### Assemble the Following Circuit
<img width="736" height="516" alt="image" src="https://github.com/user-attachments/assets/11f16270-c8e2-43e4-b5fa-59c6474f4d5d" />

Which is equivalent to: 

<img width="433" height="545" alt="radar-scanner-diagram" src="https://github.com/user-attachments/assets/72aca90d-c892-4f60-8bb0-b08a5a89c28e" />

### Code Installation Instructions
- Download the zip folder
- Upload the Arduino code to the Arduino UNO 
- Stop running the Arduino code, then run the Processing code. 
  - Notes
    - Two consoles should not run simultaneously for the same serial port. This will produce a “port is busy” error. 
    - Change the port on the Processing code from “COM3” to the current port the Arduino is attached to. 



















