<h1>Stabilized car MK1</h1>

<h3>By Kian Mcintosh</h3>
![IMG-2783](https://github.com/kian-mc/Stabalized-car-mk1/assets/71298052/dc3d7cd7-790b-48d4-9ac0-7df7efd7b758)
<h2>Overview</h2>
<p>This project is a remote controlled car that features a stabilized platform on it. The car is controlled with your phone over wifi and uses 2 wheels to push the car around in different directions. The stabilized platform uses motors to keep the platform steady.</p>

![IMG-2784](https://github.com/kian-mc/Stabalized-car-mk1/assets/71298052/2e00f441-8e9c-4cf8-9388-e4bda1e9260c)
![IMG-27856](https://github.com/kian-mc/Stabalized-car-mk1/assets/71298052/a2febedf-fb3c-4fbb-9627-d891e7d20314)
![IMG-2786](https://github.com/kian-mc/Stabalized-car-mk1/assets/71298052/68e2fa32-9974-488f-914d-6937191a15c3)
<h2>System Details</h2>
<p> The design of the Stabilized Car is very complicated due to many features it provides. The movement of the wheels is caused by simple 5v DC motors that are controlled by a l298n motor controller. The motor controller is hooked up to a Node MCU 1.0 which is a wifi capable development board. The power is delivered by a 7.2v Lithium polymer battery. The stabilization is created with 3 servo motors in a gimbal mount orientation. The servos are controlled by an Arduino Nano and the Nano receives positional and rotational inputs based on a small MPU gyroscope. The phone controllability is due to the Node MCU unit which is connected through a software called Blynk which lets you control devices through their servers.</p>
![IMG-2784](https://github.com/kian-mc/Stabalized-car-mk1/assets/71298052/aa90b156-60af-4bb3-800a-3d69389f4d43)
![wiring scematic](https://github.com/kian-mc/Stabalized-car-mk1/assets/71298052/b1afc27f-478f-4822-a4f2-1342cc38bb3c)
<h2>Design Evaluation</h2>
<p> I think that my project meets all requirements provided by the assignment.</p>
1. Output display
  <p>The Output display on my project is on my mobile device through the Blynk app. It displays relevant information about the project like uptime.</p>
2. Manual user input
  <p> My project uses a virtual joystick through the use of the blink app. It allows the car to move in various directions based on the user's input.</p>
3. Automatic sensor
  <p> My project uses an MPU gyroscope to give information about the rotation position in space of the creation and sending that information to the gimbal mechanism.</p>
4. Actuation
  <p> My project uses 3 servos and 2 motors for actuation, the servos for the gimbal and the motors for the movement of the vehicle.</p>
5. Logic, Processing, and Control
  <p> My project utilizes 2 microcontrollers both programmed with complex code and wired in a custom pcb mount. It also does complex calculations for the gimbal mount in the code of the arduino nano.</p>
  
<p> the one thing i want to justify is my output display because it was going to be a live camera feed until i discovered that it required blynk premium so i was unable to implement it how it should have gone. With that being said it is still outputting information on the app and i think it counts. </p>

<h2>Parts List</h2>
Arduino Nano,  Amazon,  9.99
NodeMCU 1.0, Amazon, 6.49
l298N - Amazon - 6.99
2X DC motor and wheels - Amazon - 8.99
3X MG995 servo - Amazon - 15
MPU accelerometer - Amazon - 2.4
LiPo 7.2v - E-Team Hobbyplex - 25
Battery Mount (32-1) - goBuilda - 3.75
generic switch - Amazon - 1.3

Total Price - 79.91

<h2>Lessons learned</h2>
<h3>Time Management</h3>
<p>I did not manage my time as good as i think i should have. This is due to procrastination and because of it I'm submitting this assignment very late at night. If I were to manage my time better I think I could have added the camera feature too which would have been really cool.</p>
<h3>Servos and Power</h3>
<p>Just because one of those little blue servos work without a dedicated power source does not mean 3 big ones will. One of my biggest issues was dealing with power management and I finally realized that my servos were not moving because I had them connected to the arduino instead of the battery pack.</p>
<h3>Using unfamiliar technology</h3>
<p>At first I wanted to use a raspberry pi until I found out how much they would hurt the budget and so I looked for alternatives. One that I found was called the Banana Pi Zero and it's just like a normal raspberry pi zero except it doesn't support python natively nor does it use any mainstream OS. I spent so much time figuring that thing out only to realize that the camera connector was the wrong kind and I couldn't find the right one anywhere online.</p>



