# CS210 Portfolio Project: Corner Grocer

## Project Summary
The Corner Grocer program is a C++ application designed to analyze daily purchasing records for a local grocery store. The program reads a text file containing a chronological list of purchased items and processes this data to determine the purchasing frequency of each item. 

The application provides a menu-driven interface that allows users to:
1. Search for a specific item and return its exact purchase count.
2. Print a complete, alphabetically sorted list of all items and their numerical purchase counts.
3. Print a text-based histogram representing the frequency of each purchased item.
4. Automatically back up the aggregated data to a `frequency.dat` file upon execution.

## Code Successes
I am particularly proud of how this project utilizes C++ Standard Library containers, specifically `std::map`. By mapping the string of the item name to an integer representing its count, the program efficiently tracks, sorts, and retrieves item frequencies without needing complex, nested iterative loops. The separation of concerns between reading the file, processing the data, and rendering the user interface also keeps the program modular.

## Areas for Enhancement
If I were to expand on this project, I would focus on refining the user input validation. Rather than relying on quick "band-aid" solutions to clear error states—such as aggressively utilizing `ignore()` functions when a user inputs a character instead of an integer—the input handling could be enhanced with a cleaner, more professional parsing system. Capturing input as a string and professionally validating it before casting would prevent stream failure states entirely, resulting in a more secure and robust application.

## Challenges and Problem Solving
One of the primary challenges was ensuring that the data mapped correctly between the input file, the internal data structures, and the final console outputs. It is easy for outputs to become misaligned if the initialization logic is flawed. Drawing on past troubleshooting experience, where I successfully resolved an issue with operands switching places in a calculator output by carefully editing the initializing variables, I meticulously structured the initialization of my file streams and variables here to ensure strict data integrity from start to finish.

## Transferable Skills
This project reinforced several critical skills that will translate directly into larger, more complex software development roles:
* **File Input/Output (I/O):** Safely opening, reading, writing, and closing external data files.
* **Data Structures:** Selecting the appropriate structure (`std::map`) for efficient data retrieval and pairing.
* **User Interface Design:** Creating clear, intuitive, and error-resistant console menus.

## Code Maintainability
To ensure this program is readable and adaptable for other developers, I adhered to strict professional formatting standards. The code features clear, descriptive variable names rather than generic placeholders. Additionally, inline comments are used purposefully to explain the *why* behind complex logic blocks (such as the file parsing loop) rather than just stating *what* the code is doing, making future updates or feature additions straightforward.
