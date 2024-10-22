#include <iostream>
#include <string>

// Abstract base class for controllable devices
class IControllable {
protected:
    bool powerState;

public:
    IControllable() : powerState(false) {}
    virtual ~IControllable() = default;
    
    // Pure virtual methods creating interface
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool isPowered() const = 0;
};

// Abstract base class for devices that can be monitored
class IMonitorable {
protected:
    std::string status;

public:
    IMonitorable() : status("Unknown") {}
    virtual ~IMonitorable() = default;
    
    // Pure virtual methods creating interface
    virtual std::string getStatus() const = 0;
    virtual void updateStatus(const std::string& newStatus) = 0;
};

// Concrete class inheriting from both interfaces
class SmartThermostat : public IControllable, public IMonitorable {
private:
    double temperature;
    double targetTemperature;

public:
    SmartThermostat() : temperature(20.0), targetTemperature(22.0) {}

    // Implementing IControllable interface
    void turnOn() override {
        powerState = true;
        std::cout << "Thermostat turned on\n";
    }

    void turnOff() override {
        powerState = false;
        std::cout << "Thermostat turned off\n";
    }

    bool isPowered() const override {
        return powerState;
    }

    // Implementing IMonitorable interface
    std::string getStatus() const override {
        return status;
    }

    void updateStatus(const std::string& newStatus) override {
        status = newStatus;
        std::cout << "Thermostat status updated to: " << status << "\n";
    }

    // Additional thermostat-specific methods
    void setTemperature(double temp) {
        if (isPowered()) {
            targetTemperature = temp;
            updateStatus("Adjusting temperature to " + std::to_string(temp));
        } else {
            std::cout << "Cannot set temperature: device is powered off\n";
        }
    }

    double getCurrentTemperature() const {
        return temperature;
    }

    double getTargetTemperature() const {
        return targetTemperature;
    }
};

// Another concrete class showing multiple inheritance
class SmartLight : public IControllable, public IMonitorable {
private:
    int brightness;

public:
    SmartLight() : brightness(0) {}

    // Implementing IControllable interface
    void turnOn() override {
        powerState = true;
        brightness = 100;
        std::cout << "Light turned on\n";
    }

    void turnOff() override {
        powerState = false;
        brightness = 0;
        std::cout << "Light turned off\n";
    }

    bool isPowered() const override {
        return powerState;
    }

    // Implementing IMonitorable interface
    std::string getStatus() const override {
        return status;
    }

    void updateStatus(const std::string& newStatus) override {
        status = newStatus;
        std::cout << "Light status updated to: " << status << "\n";
    }

    // Light-specific methods
    void setBrightness(int level) {
        if (isPowered() && level >= 0 && level <= 100) {
            brightness = level;
            updateStatus("Brightness set to " + std::to_string(level) + "%");
        } else if (!isPowered()) {
            std::cout << "Cannot set brightness: device is powered off\n";
        } else {
            std::cout << "Invalid brightness level\n";
        }
    }

    int getBrightness() const {
        return brightness;
    }
};

int main() {
    // Demonstrate usage of both classes
    SmartThermostat thermostat;
    SmartLight light;

    // Using IControllable interface
    thermostat.turnOn();
    light.turnOn();

    // Using IMonitorable interface
    thermostat.updateStatus("Operating normally");
    light.updateStatus("Full brightness");

    // Using specific functionality
    thermostat.setTemperature(24.5);
    light.setBrightness(75);

    // Demonstrate polymorphism using base class pointers
    IControllable* controllableDevices[] = {&thermostat, &light};
    for (auto device : controllableDevices) {
        device->turnOff();
    }

    IMonitorable* monitorableDevices[] = {&thermostat, &light};
    for (auto device : monitorableDevices) {
        std::cout << "Device status: " << device->getStatus() << "\n";
    }

    return 0;
}