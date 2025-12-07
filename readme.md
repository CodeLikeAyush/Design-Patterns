1. Creational Design Patterns

Purpose: Deal with object creation mechanisms, trying to create objects in a manner suitable to the situation.
Goal: Encapsulate object creation to make a system independent of how its objects are created, composed, and represented.

Common Patterns:

Singleton: Ensures only one instance of a class exists.

Factory Method: Creates objects without specifying the exact class.

Abstract Factory: Provides an interface to create families of related objects.

Builder: Separates the construction of a complex object from its representation.

Prototype: Creates new objects by copying an existing object.

Example: Configuring a logger object so that the whole application uses the same instance (Singleton).

2. Structural Design Patterns

Purpose: Deal with object composition, creating relationships between objects to form larger structures.
Goal: Ensure flexibility and efficiency in the way objects are organized.

Common Patterns:

Adapter: Converts one interface to another.

Decorator: Adds behavior to objects dynamically.

Facade: Provides a simplified interface to a complex subsystem.

Composite: Treats individual objects and compositions uniformly.

Proxy: Provides a surrogate for controlling access to another object.

Example: Wrapping a legacy class with an adapter to make it compatible with a new system.

3. Behavioral Design Patterns

Purpose: Deal with object interaction and responsibility, defining communication patterns between objects.
Goal: Make complex control flows simpler and more maintainable.

Common Patterns:

Observer: Notifies dependents automatically when the state changes.

Strategy: Defines a family of algorithms, encapsulates them, and makes them interchangeable.

Command: Encapsulates a request as an object.

Iterator: Provides a way to access elements of a collection sequentially without exposing its structure.

State: Allows an object to alter its behavior when its internal state changes.

Example: Implementing a payment system where different strategies (credit card, PayPal) can be used interchangeably.