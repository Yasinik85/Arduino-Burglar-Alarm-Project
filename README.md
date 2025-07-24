# 🐔🔒 Pokemon Chicken Protector (Arduino Burglar Alarm)

A fun twist on a burglar alarm system using Arduino! Our interactive security system features ultrasonic sensors, servo motors, LEDs, and a buzzer to detect nearby intruders. As the object approaches, LEDs brighten, servos move, and an alarm is triggered — with a playful "chicken protector" theme.

---

## 🧠 Inspiration

This project was inspired by the Arduino tutorial ["Big Brother Is Watching You"](https://projecthub.arduino.cc/frenchy22/big-brother-is-watching-you-f86de7). We customized the concept by:
- Adding blinking LEDs that respond based on proximity
- Creating servo-controlled "chickens" that follow motion
- Adding a creative cardboard enclosure for theme and style

---

## 👥 Team Members

- [Yaseman Nikoo](https://github.com/yourusername) — Code, debugging, testing
- Katherine Zhou — Report writing, circuit building
- Olivia Su — Circuit construction, TinkerCAD, visuals

---

## 🧰 Materials Used

- Arduino Uno
- 2 Ultrasonic sensors
- 2 Servo motors
- 2 LEDs (Red and Green)
- Speaker (Buzzer)
- 2 × 470Ω resistors
- Breadboard and jumper wires
- Cardboard + tape for enclosure and decoration

---

## ⚙️ Project Functionality

- 🔴 **Red LED** increases brightness as an object approaches the **side** sensor
- 🟢 **Green LED** increases brightness based on the **top** sensor
- 🔊 **Buzzer** activates when any object gets closer than 7.0 cm
- 🦾 **Servo motors** turn to follow the intruding object’s position
- 🐥 Chicken visuals on the servos add creativity and humor!

---

## 📐 How It Works

- The distance is calculated using the ultrasonic sensor's echo return time.
- `measureDist()` calculates the object’s proximity.
- The servo angle is determined based on horizontal and vertical positioning.
- When close enough, both LEDs blink, and the buzzer sounds.

---

## 🔩 Wiring Diagram

[🔗 TinkerCAD Project](https://www.tinkercad.com/things/cbiKmGOrcKW-powerful-densor-sango/editel?sharecode=qoaljgyZ-_0tWsSxz_iATn8W9yghLLALDy5eEwmkIcw)

---

## 🧪 What We Learned

- How to use ultrasonic sensors with Arduino to measure distance
- Controlling servo motors based on sensor input
- Building circuits in both TinkerCAD and physical hardware
- Team collaboration and task division

---

## 🚀 Future Improvements

- Only blink the LED closest to the object (not both)
- Add I/O2 communication to send phone alerts via an app or IoT device

---

## 📚 Helpful Resources

- [Servo Motors with Arduino](https://docs.arduino.cc/learn/electronics/servo-motors/)
- [Arduino Math Functions](https://www.arduino.cc/reference/en/language/functions/math/constrain/)
- [Arduino Project Hub](https://projecthub.arduino.cc/)

---

## 📸 
<img width="701" height="565" alt="Screenshot 2025-07-24 at 3 42 17 PM" src="https://github.com/user-attachments/assets/16f2043a-0119-4566-b14b-d1fc8754cbe2" />


