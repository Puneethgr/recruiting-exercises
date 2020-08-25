READ ME 

Source Code by: Puneeth G R

This program is interactive. You must enter the values manually.

Test case 1:

Input: { apple: 10 }, 
[
	{ name: owd, inventory: { apple: 5 } }, 
	{ name: dm, inventory: { apple: 5 } }
]


Output: 
[
	{ dm: { apple: 5 }}, 
	{ owd: { apple: 5 } }
]


According to my source code:

Input:
```
Enter the number of inventories:
2
Enter details of inventory 1:
Enter the inventory name:
owd
Enter the number of items in the inventory:
1
Enter the details of item 1:
Enter the item name :
apple
Enter the quanitity available:
5
Enter details of inventory 2:
Enter the inventory name:
dm
Enter the number of items in the inventory:
1
Enter the details of item 1:
Enter the item name :
apple
Enter the quanitity available:
5
Enter the orders details:
Enter the number of orders:
1
Enter the ordered item 1's name:
apple
Enter the ordered item's quantity:
10
```

Output:
```
Final allocations are as follows:
----------
Inventory Name:owd
Allocated items:
Item name:apple
Item quantity:5
----------
Inventory Name:dm
Allocated items:
Item name:apple
Item quantity:5

```


Testcase 2:

Input: { apple: 10, orange : 15, mango : 15 }, 
[
	{ name: wip, inventory: { apple: 5, orange : 3 } }, 
	{ name: mro, inventory: { apple: 12, orange : 5, mango : 2 } },
	{ name: rw, inventory: {mango : 13}}
]

Output:
[
	{ wip: { apple: 5 } }, 
	{ mro: { apple: 10 , mango : 2} },
	{ rw: {mango : 13} }
]


According to my source code,

Input:
```
Enter the number of inventories:
3
Enter details of inventory 1:
Enter the inventory name:
wip
Enter the number of items in the inventory:
2
Enter the details of item 1:
Enter the item name :
apple
Enter the quanitity available:
5
Enter the details of item 2:
Enter the item name :
orange
Enter the quanitity available:
3
Enter details of inventory 2:
Enter the inventory name:
mro
Enter the number of items in the inventory:
3
Enter the details of item 1:
Enter the item name :
apple
Enter the quanitity available:
12
Enter the details of item 2:
Enter the item name :
orange
Enter the quanitity available:
5
Enter the details of item 3:
Enter the item name :
mango
Enter the quanitity available:
2
Enter details of inventory 3:
Enter the inventory name:
rw
Enter the number of items in the inventory:
1
Enter the details of item 1:
Enter the item name :
mango
Enter the quanitity available:
13
Enter the orders details:
Enter the number of orders:
3
Enter the ordered item 1's name:
apple
Enter the ordered item's quantity:
10
Enter the ordered item 2's name:
orange
Enter the ordered item's quantity:
15
Enter the ordered item 3's name:
mango
Enter the ordered item's quantity:
15
```

Output:
```
Final allocations are as follows:
----------
Inventory Name:wip
Allocated items:
Item name:apple
Item quantity:5
----------
Inventory Name:mro
Allocated items:
Item name:apple
Item quantity:10
----------
Inventory Name:mro
Allocated items:
Item name:mango
Item quantity:2
----------
Inventory Name:rw
Allocated items:
Item name:mango
Item quantity:13
```


Test case 3:

Input: { apple: 10000 }, 
[
	{ name: owd, inventory: { apple: 2 } }, 
	{ name: dm, inventory: { apple: 5 } }
]


Output (empty list, no allocation possible): 
[]

According to my source code,

Input:
```
Enter the number of inventories:
2
Enter details of inventory 1:
Enter the inventory name:
owd
Enter the number of items in the inventory:
1
Enter the details of item 1:
Enter the item name :
apple
Enter the quanitity available:
2
Enter details of inventory 2:
Enter the inventory name:
dm
Enter the number of items in the inventory:
1
Enter the details of item 1:
Enter the item name :
apple
Enter the quanitity available:
5
Enter the orders details:
Enter the number of orders:
1
Enter the ordered item 1's name:
apple
Enter the ordered item's quantity:
10000
```

Output:
```
No allocation can be made.
```
