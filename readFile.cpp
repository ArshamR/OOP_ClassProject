#include "project.h"

/***********************************************************************************
 * openFile
 * ---------------------------------------------------------------------------------
 * This function opens a file and reads the data into a vector
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		The vector : vector<ICustomer<string>*>& customers must exist
 *
 * POST-CONDITIONS
 * 		Objects of interested customer class will have data members set.
 * 		Vector will be filled with the interested customer objects
 **********************************************************************************/
void openFile(vector<ICustomer<string>*>& customers)
{
	fstream inFile;									//input file stream variable used to open and read the file
	string name;									//Name of interested customer
	string address;									//Address of interested customer
	string city;									//City of interested customer
	string zipcode;									//Zip code of interested customer
	int interest;									//How interested the customer is
	string value;									//Whether the customer is key or not
	int index = 0;

	//Opens the file that contains the interested customer data
	inFile.open("example.txt");

	//Will read until there is no data left in file
	while(!inFile.eof())
	{
		//pushes back a new customer object
		customers.push_back(new ICustomer<string>);
		//reads in data and sets it to the corresponding data member
		getline(inFile, name);
		customers[index]->setName(name);
		getline(inFile,address);
		customers[index]->setAddress(address);
		getline(inFile, city);
		customers[index]->setCity(city);
		getline(inFile,zipcode);
		customers[index]->setZip(zipcode);
		inFile >> interest;
		customers[index]->setInterest((unsigned char)interest);
		inFile >> value;
		inFile.ignore(1000,'\n');
		//checks if the customer is key or not
		if(value =="key")
		{
			customers[index]->setValue(true);
		}
		else
		{
			customers[index]->setValue(false);
		}
		index++;
	}
	//closes the input file
	inFile.close();
}

/***********************************************************************************
 * openFile
 * ---------------------------------------------------------------------------------
 * This function opens a file and reads the data into a vector
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	The vector:	vector<PCustomer<string>*>& robots must exist
 *
 * POST-CONDITIONS
 * 		Objects of interested customer class will have data members set.
 * 		Vector will be filled with the interested customer objects
 **********************************************************************************/

void openFilePC(vector<PCustomer<string>*>& robots)
{
	fstream inFile;									//Input file variable used to open the input file and read into the vector
	string name;									//Name of the customer who owns the robot
	string testimonial;								//The testimonial of the customer
	string robotName;								//Name of the robot
	int norton;										//Whether the robot has norton or not
	int color;										//The color of the robot
	int movement;									//The movement of the robot
	int index = 0;


	//Opens the file that contains the customer/robot information
	inFile.open("payingCustomer.txt");

	//Loops until all data has been read
	while(!inFile.eof())
	{
		//pushes back a new paying customer object
		robots.push_back(new PCustomer<string>);
		//reads the data and sets it to the corresponding data memeber of the object
		getline(inFile,name);
		robots[index]->setName(name);
		getline(inFile,testimonial);
		robots[index]->setTestimonial(testimonial);
		getline(inFile, robotName);
		robots[index]->setRobotName(robotName);
		inFile >> norton;
		//checks to see if the robot has norton or not
		if(norton == 1)
		{
			robots[index]->setNorton(true);
		}
		else
		{
			robots[index]->setNorton(false);
		}
		inFile >> color;
		robots[index]->setColor((unsigned char)color);
		inFile >> movement;
		robots[index]->setMovement((unsigned char)movement);
		index++;
		inFile.ignore(1000,'\n');
	}
	//closes the input file
	inFile.close();
}

/***********************************************************************************
 * wrtieToFileIC
 * ---------------------------------------------------------------------------------
 * This function opens a file prints a vector of objects to the file
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	The vector:	vector<ICustomer<string>*>& customers must exist
 *
 * POST-CONDITIONS
 * 		The output file will be filled with the objects and their data
 **********************************************************************************/
void writeToFileIC(vector<ICustomer<string>*> customers)
{
	ofstream oFile;						//Variable used to open the variable

	//Opens the file to write to
	oFile.open("example.txt");
	int index;

	//loops until the vector has one object left in it
	for(index = 0; index < customers.size() -1; index++)
	{
		oFile << customers[index]->getName() << endl;
		oFile << customers[index]->getAddress() << endl;
		oFile << customers[index]->getCity() <<endl;
		oFile << customers[index]->getZip() << endl;
		oFile << int(customers[index]->getInterest()) << endl;
		oFile << (customers[index]->getValue()?"key":"nice to have") << endl;
	}
	//outputs the last object
	oFile << customers[customers.size()-1]->getName() << endl;
	oFile << customers[customers.size()-1]->getAddress() << endl;
	oFile << customers[customers.size()-1]->getCity() <<endl;
	oFile << customers[customers.size()-1]->getZip() << endl;
	oFile << int(customers[customers.size()-1]->getInterest())<< endl;
	oFile << (customers[customers.size()-1]->getValue()?"key":"nice to have");

	//closes the output file
	oFile.close();
}

/***********************************************************************************
 * writeToFilePC
 * ---------------------------------------------------------------------------------
 * This function opens a file and prints the vector into it
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	The vector:	vector<PCustomer<string>*>& robots must exist
 *
 * POST-CONDITIONS
 * 		The output file will be filled with the objects and their data
 **********************************************************************************/

void writeToFilePC(vector<PCustomer<string>*> robots)
{
	ofstream oFile;						//Output file variable used to open the output file
	int index;

	// opens the output file for paying customers
	oFile.open("payingCustomer.txt");

	//loops until there is one element left to print
	for(index = 0; index < robots.size() -1; index++)
	{
		oFile << robots[index]->getName() << endl;
		oFile << robots[index]->getTestimonial() << endl;
		oFile << robots[index]->getRobotName() << endl;
		oFile << (robots[index]->getNorton()? 1:0) << endl;
		oFile << int(robots[index]->getColor()) << endl;
		oFile << int(robots[index]->getMovement()) << endl;
	}
	//prints the last element to avoid extra line from endl
	oFile << robots[index]->getName() << endl;
	oFile << robots[index]->getTestimonial() << endl;
	oFile << robots[index]->getRobotName() << endl;
	oFile << (robots[index]->getNorton()? 1:0) << endl;
	oFile << int(robots[index]->getColor()) << endl;
	oFile << int(robots[index]->getMovement());

	//closes the output file
	oFile.close();
}
