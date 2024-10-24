# CPPMulti
Class Example

This program demonstrates several important OOP concepts:

1. Abstract Base Classes (Interfaces):
   - `IControllable`: Defines interface for power control
   - `IMonitorable`: Defines interface for status monitoring

2. Multiple Inheritance:
   - Both `SmartThermostat` and `SmartLight` inherit from both interfaces
   - Each class implements all pure virtual methods from both base classes

3. Polymorphism:
   - Base class pointers are used to manage different derived classes
   - Virtual functions enable runtime polymorphism

4. Encapsulation:
   - Private member variables with public interface methods
   - Protected members in base classes

The program models a smart home system where devices can be both controlled and monitored. 

[UML Diagram](https://claude.site/artifacts/2807d59e-f5ad-428c-92e3-16628213ed69)
