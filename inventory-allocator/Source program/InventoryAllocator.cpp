#include <unordered_map>
#include <iostream>
using namespace std;

class Inventory
{
public:
	string inventoryName;
	unordered_map<string, int> inventory;
	Inventory(string name, unordered_map<string, int> inventoryavailable)
	{
		inventoryName = name;
		inventory = inventoryavailable;
	}
};
class InventoryAllocator
{
public:
	std::vector<Inventory> allocateInventory(unordered_map<string, int> orders, std::vector<Inventory>& inventoryObjects)
	{
		std::vector<Inventory> allocations;
		for (auto orderName : orders)
		{
			bool allocationDone = false;
			int orderamount = orders[orderName.first];
			int currentlyordered = 0;
			for (auto& invobj : inventoryObjects)
			{
				if ((invobj.inventory).find(orderName.first) != (invobj.inventory).end())
				{
					if (invobj.inventory[orderName.first] >= orderamount)
					{
						currentlyordered = orderamount;
						allocationDone = true;
						break;
					}
					else
					{
						currentlyordered += invobj.inventory[orderName.first];
					}
				}
			}
			if (currentlyordered >= orderamount) 
			{
				allocationDone = true;
			}


			if (allocationDone)
			{
				int tempallocation = 0;
				for (auto& invobj : inventoryObjects)
				{
					if (tempallocation < orderamount)
					{
						if ((invobj.inventory).find(orderName.first) != (invobj.inventory).end())
						{
							
							if (invobj.inventory[orderName.first] >= orderamount)
							{
								unordered_map<string, int> orderedPair;
								orderedPair[orderName.first] = orderamount;

								Inventory obj1(invobj.inventoryName, orderedPair);
								allocations.push_back(obj1);

								tempallocation += invobj.inventory[orderName.first];
								invobj.inventory[orderName.first] -= orderamount;
							}
							else
							{
								unordered_map<string, int> orderedPair;
								orderedPair[orderName.first] = invobj.inventory[orderName.first];

								Inventory obj1(invobj.inventoryName, orderedPair);
								allocations.push_back(obj1);

								tempallocation += invobj.inventory[orderName.first];
								invobj.inventory[orderName.first] = 0;
							}
						}
					}
					else
					{
						break;
					}
				}
			}

		}

		return allocations;

	}
};

int main()
{
	int choice = 0;
	string inventoryName, inventoryItems, itemName;
	int itemQuantity;
	int numberOfInventory, numberOfInventoryItems;
	std::vector<Inventory> inventoryObjectsList;


	cout << "Enter the number of inventories:" << endl;
	cin >> numberOfInventory;

	for (int i = 0; i < numberOfInventory; i++) 
	{
		cout << "Enter details of inventory " << i+1 << ": " << endl;

		cout << "Enter the inventory name:" << endl;
		cin >> inventoryName;

		cout << "Enter the number of items in the inventory:" << endl;
		cin >> numberOfInventoryItems;

		unordered_map<string, int> itemsMap;

		for (int j = 0; j < numberOfInventoryItems; j++)
		{
			cout << "Enter the details of item " << j + 1 << ":" << endl;
			cout << "Enter the item name :" << endl;
			cin >> itemName;

			cout << "Enter the quanitity available:" << endl;
			cin >> itemQuantity;

			itemsMap[itemName] = itemQuantity;
		}
		Inventory inventoryObject(inventoryName, itemsMap);
		inventoryObjectsList.push_back(inventoryObject);
	}


	unordered_map<string, int> ordersMap;

	cout << "Enter the orders details: " << endl;
	int numberOfOrders; 
	cout << "Enter the number of orders: " << endl;
	cin >> numberOfOrders;

	for (int i = 0; i < numberOfOrders; i++)
	{
		string orderItemName;
		int orderItemQuantity;
		
		cout << "Enter the ordered item " << i + 1 << "'s name:" << endl;
		cin >> orderItemName;

		cout << "Enter the ordered item's quantity:" << endl;
		cin >> orderItemQuantity;

		ordersMap[orderItemName] = orderItemQuantity;
	}

	InventoryAllocator inventoryAllocationObject;
	std::vector<Inventory> finalAllocations = inventoryAllocationObject.allocateInventory(ordersMap, inventoryObjectsList);
	
	if (finalAllocations.empty())
	{
		cout << "No allocation can be made." << endl;
	}
	else
	{
		cout << "Final allocations are as follows:" << endl;
		for (auto allocation : finalAllocations)
		{
			cout << "----------"<<endl;
			cout << "Inventory Name:" << allocation.inventoryName << endl;
			cout << "Allocated items:" << endl;
			for (auto it : allocation.inventory)
			{
				cout << "Item name:" << it.first << endl;
				cout << "Item quantity:" << it.second << endl;
			}
		} 

	}
	return 0;
}