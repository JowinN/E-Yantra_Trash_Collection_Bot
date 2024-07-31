## Firebird V Line Following Bot - Waste Management System

### Teachers Robotics Competition 2024

## 1. Introduction

In the near future, maintaining a clean and green city is paramount. Urban sanitation and environmental sustainability have become critical, and diligent robots like Firebird V are key players in these efforts. Regular collection and proper disposal of waste are essential for balancing urban life and ecological health. This project revolves around a scenario where Firebird V navigates the city, divided into different zones, to manage three types of waste: organic, recyclable, and hazardous. Firebird V collects these materials from various locations, ensuring they are safely deposited into designated bins.

### Key Features
- **Waste Detection**: Firebird V detects three types of waste: organic, recyclable, and hazardous.
- **Navigation**: It follows a line to traverse the city, stopping at designated Waste Collection Points (WCPs) to detect waste.
- **Reporting**: After collecting waste, it reports the count at the Waste Management Hub (WMH).

## 2. Theme Description

The arena represents various locations within two cities, each generating different types of waste. The arena includes City A, City B, and a Waste Management Hub (WMH). 

### Waste Collection Points (WCPs)
The city sectors (restaurants, industries, hospitals, etc.) generate distinct waste types, gathered at WCPs. There are 10 WCPs divided into three sections:
- **Section 1: Organic Waste** - WCP 1, 9, 10
- **Section 2: Recyclable Waste** - WCP 2, 3, 4, 8
- **Section 3: Hazardous Waste** - WCP 5, 6, 7

### Waste Management Hub (WMH)
The WMH has three sectors, each handling specific waste types located by Firebird V:
1. **Composting Facility (CF)**: Organic waste bin for food scraps, yard debris, etc.
2. **Recycling Center (RC)**: For paper, glass, plastics, etc.
3. **Hazardous Waste Disposal Unit (HU)**: For hazardous materials like batteries and chemicals.

## 3. Arena Setup

### Arena Design
Teams need to prepare the arena following these steps:
- **Printing**: Print the arena design on a flex sheet as per provided dimensions (6.5 x 6 ft).
- **Waste Blocks (WBs)**: Create WBs of 7 x 7 x 8 cm using materials like thermocol or cardboard, ensuring they are white.

![Track](https://github.com/JowinN/E-Yantra_Trash_Collection_Bot/blob/main/Resources/Eyantra_Track.jpg?raw=true)

## 4. Getting Started

### Resources
- **Software**: Atmel Studio 6, AVR Dude, AVR Studio 4.17, WIN AVR.
- **Hardware/Software Manual**: Firebird V manual.
- **Tutorials**: Video tutorials on using Firebird V.

## 5. Theme Rules

### Theme Run and Human Interventions
- **Time Limit**: 5 minutes per run.
- **Reposition**: Teams can reposition the robot if it strays from the path, with a maximum of 3 interventions allowed.

### Run Procedure
- **Start**: Place Firebird V at the "IN" position.
- **Detection**: The robot detects WBs at WCPs and signals with a buzzer beep.
- **Reporting**: At the WMH, it reports the waste count with buzzer beeps.
- **End**: The run ends when the robot reaches "OUT" or the time limit is reached.

## 6. Judging and Scoring System

Scores are calculated as follows:
- **Total Score** = 300 - T + 10*WBI + 10*WMHI - 30*P + B

Where:
- **T**: Total time in seconds.
- **WBI**: Waste blocks identified.
- **WMHI**: Waste management hub identification.
- **P**: Penalty for human intervention.
- **B**: Bonus for correctly detecting all WBs and incurring no penalties.

## 7. Configuration for Final Run

The final configuration places WBs as per the provided setup. The code should be generic and not hardcoded to accommodate any configuration.

## 8. Example Run

The robot should follow the specified sequence for detecting waste and reporting at the WMH.

## 9. Submission Instructions

- **Video**: Record and upload the video of the run on YouTube as "Unlisted".
- **Project Folder**: Upload the complete project folder created in Atmel Studio 6.
- 
<iframe width="695" height="391" src="https://www.youtube.com/embed/iiDDVHnq1Is" title="EYTRC#1069" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

## All the Best! Happy Learning!

---

This README provides a comprehensive guide to setting up and operating the Firebird V line-following bot for waste management, as part of the Teachers Robotics Competition 2024. Ensure to follow all guidelines and submit the necessary materials for evaluation.
