# WILDLIFE-DETECTION-AND-ELECTRIC-FENCING-ACTIVATION-SYSTEM

The Wildlife Detection and Electric Fencing Activation System is a solution designed to mitigate human-wildlife conflict by detecting wildlife intrusions and activating electric fencing accordingly. The system utilizes computer vision, microcontroller-based hardware, and GSM communication to detect, respond to, and notify relevant stakeholders about potential wildlife threats.

### How It Works:

1. **Wildlife Detection**:
   - The system employs a YOLOv5 computer vision model implemented on a Raspberry Pi to detect wildlife, including elephants and domestic animals, within its field of view. The YOLOv5 model is trained to recognize specific classes of animals.

2. **Detection Response**:
   - Upon detecting wildlife, the system triggers a response based on the type of animal detected:
     - **Elephant Detection**: If an elephant is detected, the system sends a signal through USB serial communication to a microcontroller, such as an Arduino UNO.
       - The microcontroller activates a high-voltage relay, passing high voltage to the electric fencing, thereby deterring the elephant from entering the protected area.
     - **Domestic Animal Detection**: In the case of domestic animal detection, the system enables a low-voltage relay to activate a different mode of the electric fencing, suitable for deterring smaller animals without causing harm.
     - **Human Detection**: Detection of human presence prompts the system to deactivate the electric fencing to prevent accidental harm.

3. **Alert System**:
   - In addition to activating the electric fencing, the system notifies registered contacts about elephant detections via a GSM module controlled by the Arduino UNO.
   - The GSM module sends SMS alerts to predefined phone numbers, allowing relevant stakeholders to take necessary actions in response to the wildlife intrusion.

![image](https://github.com/Boolean-Hooligans-356/WILDLIFE-DETECTION-AND-ELECTRIC-FENCING-ACTIVATION-SYSTEM/assets/96923418/e236136a-d923-4fa1-b80f-6fa909655e85)

![image](https://github.com/Boolean-Hooligans-356/WILDLIFE-DETECTION-AND-ELECTRIC-FENCING-ACTIVATION-SYSTEM/assets/96923418/24521dd5-48ad-4006-8d84-06328f2611f0)

![image](https://github.com/Boolean-Hooligans-356/WILDLIFE-DETECTION-AND-ELECTRIC-FENCING-ACTIVATION-SYSTEM/assets/96923418/b5aa5fdb-6eb7-445c-a880-863f837cfbd2)

### System Components:

- **Hardware**:
  - Raspberry Pi: Runs the YOLOv5 model for real-time wildlife detection.
  - Arduino UNO: Controls the activation of relays based on detection events and manages GSM communication.
  - Relays: Control the flow of high and low voltage to the electric fencing.
  - GSM Module: Sends SMS alerts to registered contacts.
- **Software**:
  - YOLOv5 Model: Trained to detect elephants and other animals.
  - Arduino Code: Controls the behavior of the system based on detection events.
  - Python Scripts: Interface between the YOLOv5 model and the Arduino UNO for detection response.

 ## Contributing
    Contributions are welcome! If you have suggestions or improvements, please fork the repository and submit a pull request.
 






