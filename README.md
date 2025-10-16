<h1>Cinema Ticket Booking System (C++ Project)</h1>

A simple yet functional C++ console application for managing a cinema’s seating arrangement, ticket sales, and revenue tracking.
This project was created as part of my First Semester Software Engineering course to demonstrate file handling, arrays, functions, and user interaction in C++.

<h2>1. Features</h2>
<br>
a) Dynamic Seating Chart<br>
b) Displays a 15×30 seating layout.<br>
c) represents available seats, * represents sold seats.<br>

<h2>2. Ticket Selling System</h2><br>
a) Allows customers to buy tickets by selecting a row and seat.<br>
b) Updates total revenue and sold seats in real time.<br>

<h2>3. Statistics and Reports</h2><br>
a) Shows total revenue.<br>
b) Displays number of seats sold and available per row.<br>

<h2>4. File Handling</h2><br>

a) Saves cinema data (prices, seating, sales) to theater_data.txt.<br>
b) Automatically loads previous session data at startup.<br>

<h2>5. Error Handling and Validation</h2><br>
a) Prevents invalid seat selection or duplicate booking.<br>
b) Ensures no negative price input.<br>

<h2>6. Concepts Used</h2><br>
a) File I/O (ifstream, ofstream, fstream)<br>
b) 2D arrays for seat management<br>
c) Functions and modular programming<br>
d) Data validation and loops<br>
e) Formatting output using iomanip<br>

<h2>7. How It Works</h2><br>
a) Run the program – it will try to load existing data from theater_data.txt.<br>
b) If no data file is found, it initializes a new cinema layout and asks for row prices.<br>

The main menu offers:

1. Display seating chart

2. Sell tickets

3. View statistics

4. Save and exit

After exiting, all data (revenue, seats, prices) is stored safely for the next session.

<h2>8. File Structure</h2>
cinema-project/
│
├── cinema project SE-08.cpp      # Main C++ source code
├── theater_data.txt              # Auto-generated data file
└── README.md                     # Project documentation

<h2>9. How to Run</h2><br>
a) Using g++ (Command Line)
    
    ```bash
      g++ "cinema project SE-08.cpp" -o cinema
      ./cinema

<br>b) Using Visual Studio 2022.<br>
c) Create a new C++ console project.<br>
d) Add the .cpp file to your project.<br>
e) Build and run.<br>

<h2>10. Project Info</h2>
<br>
a) Course: Software Engineering (Semester 1).<br>
b) Language: C++.<br>
c) IDE Used: Visual Studio 2022.<br>

<h4>Author: Muhammad Ali Rana</h4><br>
<h4>LinkedIn Profile Link : <a href = "www.linkedin.com/in/muhammad-ali-rana-975571356">Click Here</a></h4><br>
<h4> License</h4>
This project is free to use for educational and learning purposes.
