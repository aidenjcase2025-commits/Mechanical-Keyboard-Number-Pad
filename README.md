# Mechanical-Keyboard-Number-Pad
<img width="765" height="517" alt="Screenshot 2026-08-24 114331" src="https://github.com/user-attachments/assets/08504df2-6b62-48d0-a3e7-b471a2e80a0a" />
A personal project of a fully functional mechanical keyboard number pad. Includes the PCB design, schematic, and software. It is a 5x4 matrix layout designed in KiCad and software written in the Arduino IDE.

Specs:
-Arduino Pro Nano
-Onesemi 1N4148 fast-switching diodes. (Chosen to prevent ghosting due to nanosecond response times.)
-Mechanical Keyboard switches (Personally, I used DROP Holy Panda X)
- USB-C connector cable.

Troubleshooting Errors:
-Biggest error was a non-functional key on row 3 column 3. This was due to a schematic error where I did not connect my diode to the microcontroller correctly. I circumvented this by hand-wiring a wire onto my microcontroller. The board functions completely after this slight change.
- Using a strong and stable USB-C cable is paramount to ensuring the number pad works effectively. 5V USB power is notoriously dirty. Because of this, a poorly built cable can affect how the number pad works. I had to swap out my cable to find one that fully latches into my Pro Nano board.
