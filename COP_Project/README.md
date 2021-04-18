# Map

### Unordered map based on hash table implementation.

#### Includes map find, add, and modify functions:

- push(key, value)
  - Overwrite the value if a duplicate key already exists.
- at(key)
  - According to the key to find the corresponding value, if the key does not exist will report an error and throw.
- operator[]
  - Find the corresponding value according to the key. 
  - If the key does not exist, push will be called to generate a new node for the map. value is a meaningless value.
  - The right value can be assigned to the value corresponding to the key by =.
- showAll()
  - Developer help method. Print out all nodes and their values.

