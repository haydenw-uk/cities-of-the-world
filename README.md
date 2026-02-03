# Cities of the World in C++

A console-based C++ application designed to manage, analyse, and store city records. The project separates responsibilities using classes such as `MenuManager` for user interface logic and an `OperationsController` for backend data handling.

## Features

- **City Management:** Add new cities with validation, or delete cities by ID or name.
- **Search and Update:** Search for records by ID or name and update specific fields such as population or mayor details.
- **Data Sorting:** Display all records or sort specific fields, including population and coordinates, in ascending or descending order.
- **Distance Calculation:** Calculate the approximate distance in kilometres between any two stored cities using their coordinates.
- **Data Persistence:** Automatically loads from and saves data to `cities.txt` to preserve records between sessions.
- **Duplicate Resolution:** Detects and resolves duplicate entries based on city name and region.

## Data Model

Each city record stores the following information:

- **General:** Unique ID, name, brief history or description, population, year recorded, country or US state
- **Coordinates:** Latitude and longitude
- **Administration:** Mayor’s name and official residence address

## Usage

Upon running the application, the following main menu is presented:

```text
-- MAIN MENU --

1. Add a new city
2. Delete a city
3. Search for a city, update city fields
4. Display all cities or specific city fields
5. Calculate distance between two cities
6. Save
7. Exit
```

## Input Validation
The system includes robust validation to ensure data integrity:

- **Strings:** Checked for empty input and minimum and maximum length
- **Integers:** Validated for numeric input and constrained to defined ranges
- **Coordinates:** Verified to fall within valid latitude (-90 to 90) and longitude (-180 to 180) ranges

## Author
*Written by Hayden Williams, Oxford Brookes University - Copyright MMXXIV*
