# Linear lists
### Information about the task:
* Element type: Char
* List type: Linear unidirectional
* Action: Remove from the list all the elements that precede and follow the specified value
### Realize these functions for list:
1. list_create- for list creating
2. help - to show information about the app 
3. list_insert- for inserting the value in the list
4. list_print- for showing content of the list
5. list_node_delete- for deleting the node with its value from the list
6. list_node_find - for finding the node with certain value
7. list_destroy - for list destroying
8. list_clear - for making the list empty
9. list_lenght - for defining list's lenght
10. list_task - for launching the action that is shown beyond
### Realize these functions for iterator:
1. iterator_first - returns first node's value of the list if it exists
2. iterator_last - returns last node's value of the list if it exists
3. iterator_next - returns the value which is the next after inputted element
### Algorithm of the solution of the task
* clear the list
* insert the definite element
### Testing
...
### How To Use
- 'add'     - to insert the value to the list\n");    
Input the elements in this order:
1. The value to set up
2. The value after which you have to insert
Note: if the value after which you want to insert doesn't exist, program should stop working <br>
For inserting the element to the list origin input in this way: 'value' '.'
- 'delete'  - to remove the value from the list
- 'lenght'  - to gain the list size
- 'task'    - to start removing the elements that precede and follow the specified value 
- 'print'   - to print the list
- 'clear'   - to make the list empty 
- 'destroy' - to destroy the list
- 'exit'    - to quit the application
