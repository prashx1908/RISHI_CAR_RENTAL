#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car {
  private:
    string make;
    string model;
    int year;
    bool available;
  
  public:
    Car(string _make, string _model, int _year) {
      make = _make;
      model = _model;
      year = _year;
      available = true;
    }
  
    void rent() {
      if (available) {
        available = false;
        cout << "Car rented!" << endl;
      } else {
        cout << "Car not available for rent." << endl;
      }
    }
  
    void returnCar() {
      if (!available) {
        available = true;
        cout << "Car returned." << endl;
      } else {
        cout << "Car not rented yet." << endl;
      }
    }
  
    void display() {
      cout << "Make: " << make << endl;
      cout << "Model: " << model << endl;
      cout << "Year: " << year << endl;
      cout << "Availability: " << (available ? "Available" : "Not available") << endl;
    }
};

class RentalSystem {
  private:
    vector<Car> cars;
  
  public:
    void addCar() {
      string make, model;
      int year;
      cout << "Enter car make: ";
      cin >> make;
      cout << "Enter car model: ";
      cin >> model;
      cout << "Enter car year: ";
      cin >> year;
      cars.push_back(Car(make, model, year));
      cout << "Car added to inventory." << endl;
    }
  
    void rentCar() {
      int carIndex;
      cout << "Enter car index to rent: ";
      cin >> carIndex;
      if (carIndex >= 0 && carIndex < cars.size()) {
        cars[carIndex].rent();
      } else {
        cout << "Invalid car index." << endl;
      }
    }
  
    void returnCar() {
      int carIndex;
      cout << "Enter car index to return: ";
      cin >> carIndex;
      if (carIndex >= 0 && carIndex < cars.size()) {
        cars[carIndex].returnCar();
      } else {
        cout << "Invalid car index." << endl;
      }
    }
  
    void displayInventory() {
      for (int i = 0; i < cars.size(); i++) {
        cout << "Car " << i << ":" << endl;
        cars[i].display();
        cout << endl;
      }
    }
};

int main() {
  RentalSystem rentalSystem;
  int choice;
  
  do {
    cout << "Choose an option:" << endl;
    cout << "1. Add car to inventory" << endl;
    cout << "2. Rent a car" << endl;
    cout << "3. Return a car" << endl;
    cout << "4. Display inventory" << endl;
    cout << "5. Exit" << endl;
    cin >> choice;
    
    switch (choice) {
      case 1:
        rentalSystem.addCar();
        break;
      case 2:
        rentalSystem.rentCar();
        break;
      case 3:
        rentalSystem.returnCar();
        break;
      case 4:
        rentalSystem.displayInventory();
        break;
      case 5:
        cout << "Goodbye!" << endl;
        break;
      default:
        cout << "Invalid choice." << endl;
        break;
    }
  } while (choice != 5);
  
  return 0;}
