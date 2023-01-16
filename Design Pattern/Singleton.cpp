
#include <bits/stdc++.h>


class Vehicle {
public:
    Vehicle(std::string name) : modelName(name) {};

    virtual void run() {
        std::cout << modelName  << " is running !!!" << std::endl;
    }

protected:
    const std::string modelName;
    std::string ownerName;
    std::string license;

};


class VehicleManager {
public:
    void addVehicle(Vehicle *vehicle) {
        vehicles.push_back(vehicle);
    }

    static VehicleManager * getManager() {
        if (manager == NULL) {
            manager = new VehicleManager();
        }
        return manager;
    }

    void start() {
        for(Vehicle* vehicel : vehicles) {
            vehicel->run();
        }
    }

private:
    std::vector<Vehicle *> vehicles;
    static VehicleManager *manager;

    VehicleManager() {

    }
    
};


VehicleManager * VehicleManager::manager = NULL;

int main() {
    system("cls");

    VehicleManager::getManager();

    // VehicleManager *maneger = new VehicleManager();

    Vehicle * taxi = new Vehicle("HOANG ANH TIEN");
    Vehicle * pickup = new Vehicle("Hoang anh chung");

    VehicleManager::getManager()->addVehicle(taxi);
    VehicleManager::getManager()->addVehicle(pickup);

    VehicleManager::getManager()->start();


    std::cin.get();
    return 0;
}