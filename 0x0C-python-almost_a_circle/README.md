# Python - Almost a circle

The objects of this project are:

- How to serialize and deserialize a Class
- What is Unit testing and how to implement it in a large project
- How to write and read a `JSON` file
- What is `*args` and how to use it
- What is `**kwargs` and how to use it
- How to handle named arguments in a function

## 1. Create a Base Class
[Base](./models/base.py) class:
- private class attribute `__nb_objects = 0`
- class constructor: `def __init__(self, id=None)`

## 2. Create Retangle Class
[Rectangle](./models/rectangle.py) class: inherits from `Base`
- Private instance attributes with its own getter and setter:
	- `width`
	- `height`
	- `x`
	- `y`
- Class constructor: `def __init__(self, width, height, x=0, y=0, id=None)`

## 3. Validate Attributes
Updates [Rectangle] class by validating it attributes:
- `width` and `height` must be integers and greater than `0`
- `x` and `y` must be integer and greater than or equal to `0`
- Raise `TypeError` if type not integer and `ValueError` if wrong value are given

## 4. Calculate Area
Defines a method `def area(self)` to calculate area from `width` and `height`

## 5. Display 2D Structure of Instance
Adds `def display(self)` method
- Prints 2D representation of [Rectangle](./models/rectangle.py) instance to the stdout
- The Structure should be drawn with `#`

## 6. String Representation
Override the `__str__` method to return string representation in the following format:
- `[Rectangle] (<id>) <x>/<y> - <width>/<height>`

## 7. Updates 2D Display
Updates the `def display(self)` method to factor `x` and `y` attributes
- `x`: The number of spaces characters before display
- `y`: The nuumber of `\n` characters to print before display

## 8. Create an Update Method
Adds a public method `def update(self, *args)` to modify instance attributes
- `args` is a tuple of variable positional arguments
	- 1st argument is `id`
	- 2nd argument is `width`
	- 3rd argument is `height`
	- 4th argument is `x`
	- 5th argument is `y`

## 9. Improve Update Method
Updates the `update` method to accept keyword arguments `def update(self, *args, **kwargs)`
- `**kwargs` is variable amount of `key=value` arguments
- `**kwargs` must be skipped if `args` exist and is not empty
- Each key in this dictionary represents an attribute to the instance

## 10. Square Class
Creates a [Square](./models/square.py) class that inherits from [Rectangle](./models/rectangle.py)
- Class constructor: `def __init__(self, size, x=0, y=0, id=None)`
- Call the super class with `id`, `x`, `y`, `width` and `height` - this super call will use the logic of the `__init__` of the `Rectangle` class.
- All `width`, `height`, `x` and `y` validation must inherit from `Rectangle` - same behavior in case of wrong data
- The overloading `__str__` method should return `[Square] (<id>) <x>/<y> - <size>` - in our case, width or height

## 11. Square size
Adds a Getter and Setter to `Square` `size`
- The setter should assign (in this order) the `width` and the `height` - with the same value
- The setter should have the same value validation as the `Rectangle` for `width` and `height` -  No need to change the exception error message (It should be the one from `width`)

## 12. Square Update
Update the class `Square` by adding the public method `def update(self, *args, **kwargs)`
- `*args` is the list of arguments - no-keyworded arguments 
	- 1st argument is `id`
	- 2nd argument is `size`
	- 3rd argument is `x`
	- 4th argument is `y`
- `**kwargs` can be thought of as a double pointer to a dictionary: key/value (keyworded arguments)
- `**kwargs` must be skipped if `*args` exists and is not empty

## 13. Rectangle instance to dictionary representation
Update the class `Rectangle` by adding the public method `def to_dictionary(self`)
- returns the dictionary representation of a `Rectangle`
- dictionary must contain:
	- `id`
	- `width`
	- `height`
	- `x`
	- `y`

## 14. Square instance to dictionary representation
Update the class `Square` by adding the public method `def to_dictionary(self)`
- returns the dictionary representation of a `Square`
- dictionary must contain:
	- `id`
	- `size`
	- `x`
	- `y`

## 15. Dictionary to JSON string
Update the class `Base` by adding the static method `def to_json_string(list_dictionaries)`
- returns the JSON string representation of `list_dictionaries`
- `list_dictionaries` is a list of dictionaries
- If `list_dictionaries` is None or empty, return the string: `"[]"`
- Otherwise, return the JSON string representation of `list_dictionaries`

## 16. JSON string to file
Update the class `Base` by adding the class method `def save_to_file(cls, list_objs)`
- writes the JSON string representation of `list_objs` to a file
- `list_objs` is a list of instances who inherits of `Base` - example: list of `Rectangle` or list of `Square` instances
- If `list_objs` is `None`, save an empty list
- The filename must be: `<Class name>.json` - example: `Rectangle.json`
- Must use the static method `to_json_string` (created before)
- Must overwrite the file if it already exists

## 17. JSON string to dictionary 
Update the class `Base` by adding the static method `def from_json_string(json_string)`
- returns the list of the JSON string representation `json_string`
- `json_string` is a string representing a list of dictionaries
- If `json_string` is None or empty, return an empty list
- Otherwise, return the list represented by `json_string`

## 18. Dictionary to Instance 
Update the class Base by adding the class method `def create(cls, **dictionary)`
- returns an instance with all attributes already set
- `**dictionary` can be thought of as a double pointer to a dictionary
- To use the `update` method to assign all attributes, you must create a “dummy” instance before
	- Create a `Rectangle` or `Square` instance with “dummy” mandatory attributes (width, height, size, etc.)
	- Call `update` instance method to this “dummy” instance to apply your real values
- Must use the method `def update(self, *args, **kwargs)`
- `**dictionary` must be used as `**kwargs` of the method `update`
- You are not allowed to use `eval`

## 19. File to instances 
- Update the class `Base` by adding the class method `def load_from_file(cls)` returns a list of instances:
- The filename must be: `<Class name>.json` - example: `Rectangle.json`
- If the file doesn’t exist, return an empty list
- Otherwise, return a list of instances - the type of these instances depends on `cls` (current class using this method)
- Must use the `from_json_string` and `create` methods (implemented previously)

## 20. JSON ok, but CSV?
Update the class `Base` by adding the class methods `def save_to_file_csv(cls, list_objs)`: and `def load_from_file_csv(cls)` that serializes and deserializes in CSV
- The filename must be: `<Class name>.csv` - example: `Rectangle.csv`
- Has the same behavior as the JSON serialization/deserialization
- Format of the CSV
	- Rectangle: `<id>,<width>,<height>,<x>,<y>`
	- Square: `<id>,<size>,<x>,<y>`

## 21. Let's draw it
Update the class Base by adding the static method `def draw(list_rectangles, list_squares)`: that opens a window and draws all the `Rectangles` and `Squares`:
- Must use the `Turtle graphics module`
- To install it: `sudo apt-get install python3-tk`
- No constraints for color, shape etc… be creative!
