## Electrical & Firmware Architecture
* **Controller:** ATmega32U4 (Arduino Pro Micro)
* **Matrix Architecture:** 5 Rows × 4 Columns multiplexed matrix
* **Diode Isolation:** 1N4148 diodes configured in `COL2ROW` orientation to eliminate ghosting
* **Scanning Logic:** Active-low column strobe with internal pull-ups on row inputs

Matrix Line          Pro Micro Arduino Pin
Col 1                2
Col 2                3
Col 3                4
Col 4                5
Row 1                6
Row 2                7
Row 3                8
Row 4                9
Row 5                10

