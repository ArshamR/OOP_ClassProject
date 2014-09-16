/***********************************************************************************
 * AUTHOR	  	 : Brian, Luis, Arsham					  						   *
 * Class Project																   *
 * CLASS	  	 : CS1C									 						   *
 * SECTION	  	 : M & W 5.30 - 8.50					  						   *
 * DUE DATE	  	 : 12.12.13								 						   *
 **********************************************************************************/

#ifndef PCUSTOMER_H_
#define PCUSTOMER_H_

template <class Type>
class Client
{
	public:
		// Destructor
		virtual ~Client ();
		// Default constructor
		Client();
		// Constructor with parameters
		Client(Type name);
		// Virtual function to output name
		virtual Type Output ();
		// Function to set name
		void setName (Type newName);
		// Function to output name
		Type getName ();

	private:
		Type name;
};

/***********************************************************************************
 * Default Destructor
 * ---------------------------------------------------------------------------------
 * This is the default destructor for the class.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
Client<Type>::~Client()
{
}

/***********************************************************************************
 * Output
 * ---------------------------------------------------------------------------------
 * This is a virtual function to output the name for any of the derived classes.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
Type Client<Type>::Output()
{
	return name;
}
/***********************************************************************************
 * Default constructor
 * ---------------------------------------------------------------------------------
 * This is the default constructor for the class. Sets name to 0.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		name = 0
 **********************************************************************************/
template <class Type>
Client<Type>::Client()
{
	name = '\0';
}

/***********************************************************************************
 * Constructor with parameters
 * ---------------------------------------------------------------------------------
 * This constructor assigns a name to the template variable name.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		name = clientName
 **********************************************************************************/
template <class Type>
Client<Type>::Client(Type clientName)
{
	name = clientName;
}

/***********************************************************************************
 * setName
 * ---------------------------------------------------------------------------------
 * This function assigns a name into the template variable name.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		name = newName
 **********************************************************************************/
template <class Type>
void Client<Type>::setName (Type newName)
{
	name = newName;
}

/***********************************************************************************
 * getName
 * ---------------------------------------------------------------------------------
 * This function returns the template variable name.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		name: must have data
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
Type Client<Type>::getName ()
{
	return name;
}

template <class Type>
class ICustomer : public Client<Type>
{
	public:
		// Default constructor
		ICustomer ();
		// Constructor with parameters
		ICustomer (Type 		 customerName,
				   Type 		 customerAddress,
				   Type 		 customerCity,
				   Type 		 customerZipCode,
				   unsigned char customerInterest,
				   bool 		 customerValue);
		// Function to set name
		void setName (Type newName);
		// Function to get name
		Type getName ();
		// Function to set address
		void setAddress (Type newAddress);
		// Function to get address
		Type getAddress ();
		// Function to set city
		void setCity (Type newCity);
		// Function to get city
		Type getCity ();
		// Function to set zip
		void setZip (Type newZip);
		// Function to get zip
		Type getZip();
		// Function to set interest
		void setInterest (unsigned char newInterest);
		// Function to get interest
		unsigned char getInterest ();
		// Function set value
		void setValue (bool newValue);
		// Function to get value
		bool getValue ();

	private:
		Type address;
		Type city;
		Type zipCode;
		unsigned char interest;
		bool value;
};

/***********************************************************************************
 * Default constructor
 * ---------------------------------------------------------------------------------
 * This is the default constructor for the class
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		address  : NULL
 * 		city     : NULL
 * 		zipCode  : NULL
 * 		interest : NULL
 * 		value    : false
 **********************************************************************************/
template <class Type>
ICustomer<Type>::ICustomer ()
				: Client <Type> ()
{
	address = '\0';
	city = '\0';
	zipCode = '\0';
	interest = '\0';
	value = false;
}

/***********************************************************************************
 * Constructor with parameters
 * ---------------------------------------------------------------------------------
 * This is the constructor with parameters.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		name	 : customerName
 * 		address  : customerAddress
 * 		city     : customerCity
 * 		zipCode  : customerZipCode
 * 		interest : customerInterest
 * 		value    : customerValue
 **********************************************************************************/
template <class Type>
ICustomer<Type>::ICustomer (Type 		  customerName,
							Type 		  customerAddress,
							Type 		  customerCity,
							Type 		  customerZipCode,
							unsigned char customerInterest,
							bool 		  customerValue)
				: Client <Type> (		  customerName)
{
	Client<Type>::setName (customerName);
	address = customerAddress;
	city = customerCity;
	zipCode = customerZipCode;
	interest = customerInterest;
	value = customerValue;
}

/***********************************************************************************
 * setName
 * ---------------------------------------------------------------------------------
 * This function sets the name for PCustomer.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		name : newName
 **********************************************************************************/
template <class Type>
void ICustomer<Type>::setName (Type newName)
{
	Client<Type>::setName (newName);
}

/***********************************************************************************
 * getName
 * ---------------------------------------------------------------------------------
 * This function returns the template variable for name.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		name must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
Type ICustomer<Type>::getName ()
{
	return Client<Type>::getName ();
}

/***********************************************************************************
 * setAddress
 * ---------------------------------------------------------------------------------
 * This function sets the address for PCustomer.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		address : newAddress
 **********************************************************************************/
template <class Type>
void ICustomer<Type>::setAddress (Type newAddress)
{
	address = newAddress;
}

/***********************************************************************************
 * getAddress
 * ---------------------------------------------------------------------------------
 * This function returns the template variable for address.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		address must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
Type ICustomer<Type>::getAddress ()
{
	return address;
}

/***********************************************************************************
 * setCity
 * ---------------------------------------------------------------------------------
 * This function sets the city for PCustomer.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		city : newCity
 **********************************************************************************/
template <class Type>
void ICustomer<Type>::setCity (Type newCity)
{
	city = newCity;
}

/***********************************************************************************
 * getCity
 * ---------------------------------------------------------------------------------
 * This function returns the template variable for city.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		city must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
Type ICustomer<Type>::getCity ()
{
	return city;
}

/***********************************************************************************
 * setZip
 * ---------------------------------------------------------------------------------
 * This function sets the zipCode for PCustomer.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		zipCode : newZip
 **********************************************************************************/
template <class Type>
void ICustomer<Type>::setZip(Type newZip)
{
	zipCode = newZip;
}

/***********************************************************************************
 * getZip
 * ---------------------------------------------------------------------------------
 * This function returns the template variable for zipCode.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		zipCode must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
Type ICustomer<Type>::getZip()
{
	return zipCode;
}

/***********************************************************************************
 * setInterest
 * ---------------------------------------------------------------------------------
 * This function sets the interest for PCustomer.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		interest : newInterest
 **********************************************************************************/
template <class Type>
void ICustomer<Type>::setInterest (unsigned char newInterest)
{
	interest = newInterest;
}

/***********************************************************************************
 * getInterest
 * ---------------------------------------------------------------------------------
 * This function returns the unsigned char for interest.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		interest must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
unsigned char ICustomer<Type>::getInterest ()
{
	return interest;
}

/***********************************************************************************
 * setValue
 * ---------------------------------------------------------------------------------
 * This function sets the value for PCustomer.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		value : newValue
 **********************************************************************************/
template <class Type>
void ICustomer<Type>::setValue (bool newValue)
{
	value = newValue;
}

/***********************************************************************************
 * getValue
 * ---------------------------------------------------------------------------------
 * This function returns the bool for value.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		value must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
bool ICustomer<Type>::getValue ()
{
	return value;
}

template <class Type>
class Robot
{
	public:
		// Default constructor
		Robot();
		// Constructor with parameters
		Robot (Type 		 newName,
			   bool 		 newNorton,
			   unsigned char newColor,
			   unsigned char newMovement);
		// Function to set name
		void setName (Type newName);
		// Function to get name
		Type getName ();
		// Function to set norton
		void setNorton (bool newNorton);
		// Function to get norton
		bool getNorton ();
		// Function to set color
		void setColor (unsigned char newColor);
		// Function to get color
		unsigned char getColor();
		// Function to set movement
		void setMovement (unsigned char newMovement);
		// Function to get movement
		unsigned char getMovement ();
		// Function to get price
		int getPrice ();

	private:
		Type name;
		bool norton;
		unsigned char color;
		unsigned char movement;
};

/***********************************************************************************
 * Default constructor
 * ---------------------------------------------------------------------------------
 * This is the default constructor for the class
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		name	 : NULL
 * 		norton	 : false
 * 		color	 : NULL
 * 		movement : NULL
 **********************************************************************************/
template <class Type>
Robot<Type>::Robot ()
{
	name = '\0';
	norton = false;
	color = '\0';
	movement = '\0';
}

/***********************************************************************************
 * Constructor with parameters
 * ---------------------------------------------------------------------------------
 * This is the constructor for the class that accepts parameters
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		name	 : newName
 * 		norton	 : newNorton
 * 		color	 : newColor
 * 		movement : newMovement
 **********************************************************************************/
template <class Type>
Robot<Type>::Robot (Type 		  newName,
					bool 		  newNorton,
					unsigned char newColor,
					unsigned char newMovement)
{
	name = newName;

	try
	{
		if (newNorton || !newNorton)
		{
			throw newNorton;
		}
	}
	catch (bool& newerNorton)
	{
		norton = newerNorton;
	}

	color = newColor;
	movement = newMovement;
}

/***********************************************************************************
 * setName
 * ---------------------------------------------------------------------------------
 * This function sets the name for Robot.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		name : newName
 **********************************************************************************/
template <class Type>
void Robot<Type>::setName (Type newName)
{
	name = newName;
}

/***********************************************************************************
 * getName
 * ---------------------------------------------------------------------------------
 * This function returns the template variable for name.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		name must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
Type Robot<Type>::getName ()
{
	return name;
}

/***********************************************************************************
 * setNorton
 * ---------------------------------------------------------------------------------
 * This function sets the norton for Robot.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		name : newName
 **********************************************************************************/
template <class Type>
void Robot<Type>::setNorton (bool newNorton)
{
	norton = newNorton;
}

/***********************************************************************************
 * getNorton
 * ---------------------------------------------------------------------------------
 * This function returns the bool for norton.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		norton must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
bool Robot<Type>::getNorton ()
{
	return norton;
}

/***********************************************************************************
 * setColor
 * ---------------------------------------------------------------------------------
 * This function sets the color for Robot.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		color : newColor
 **********************************************************************************/
template <class Type>
void Robot<Type>::setColor (unsigned char newColor)
{
	color = newColor;
}

/***********************************************************************************
 * getColor
 * ---------------------------------------------------------------------------------
 * This function returns the unsigned char for color.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		color must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
unsigned char Robot<Type>::getColor ()
{
	return color;
}

/***********************************************************************************
 * setMovement
 * ---------------------------------------------------------------------------------
 * This function sets the movement for Robot.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		movement : newMovement
 **********************************************************************************/
template <class Type>
void Robot <Type>::setMovement (unsigned char newMovement)
{
	movement = newMovement;
}

/***********************************************************************************
 * getMovement
 * ---------------------------------------------------------------------------------
 * This function returns the unsigned char for movement.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		movement must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
unsigned char Robot<Type>::getMovement ()
{
	return movement;
}

/***********************************************************************************
 * getPrice
 * ---------------------------------------------------------------------------------
 * This function calculates the price of the Robot based off the values for
 * 	norton, color, and movement.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		norton	 : Must have data in it
 * 		color	 : Must have data in it
 * 		movement : Must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
int Robot <Type>::getPrice ()
{
	// Sets initial price
	int price = 250000;

	// Checks if norton
	if (norton)
	{
		price += 10000;
	}

	// Checks default color
	if (color == 0)
	{
		price += 0;
	}
	// Cheap colors
	else if (color >= 1 && color <= 3)
	{
		price += 5000;
	}
	// Fancy colors
	else
	{
		price += 50000;
	}

	// Checks default movement
	if (movement == 0)
	{
		price += 0;
	}
	// Cheap movement
	else if (movement >= 1 && movement <= 3)
	{
		price += 50000;
	}
	// Fancy movement
	else
	{
		price += 100000;
	}

	return price;
}

template <class Type>
class PCustomer : public Client<Type>
{
	public:
		// Default constructor
		PCustomer ();
		// Constructor with parameters
		PCustomer (Type 		 newCustomerName,
				   Type 		 newTestimonial,
				   Type			 newPassword,
				   Type 		 robotName,
				   bool 	     norton,
				   unsigned char color,
				   unsigned char movement);
		// Destructor
		~PCustomer ();
		// Copy constructor
		PCustomer (const PCustomer<Type>& newCust);
		// Deep copy
		void Copy (PCustomer<Type>* newCust);
		// Calls default constructor for Robot
		void setRobot (Robot<Type>* newRobot);

		// Overloaded assignment operator
		void operator= (const PCustomer<Type>& newCust) const;

		// Function to set name
		void setName (Type customerName);
		// Function to get name
		Type getName ();
		// Function to set testimonial
		void setTestimonial (Type testimonial);
		// Function to get testimonial
		Type getTestimonial ();
		// Function to set password
		void setPassword (Type newPass);
		// Function to get password
		Type getPassword ();
		// Function to set Robot.name
		void setRobotName (Type robotName);
		// Function to get Robot.name
		Type getRobotName ();
		// Function to get Robot.norton
		void setNorton (bool norton);
		// Function to get Robot.norton
		bool getNorton ();
		// Function to get Robot.color
		void setColor (unsigned char color);
		// Function to get Robot.color
		unsigned char getColor ();
		// Function to get Robot.movement
		void setMovement (unsigned char movement);
		// Function to get Robot.movement
		unsigned char getMovement ();
		// Function to get Robot.price
		int getPrice ();

	private:
		Robot<Type>* robot;
		Type testimonial;
		Type password;
};

/***********************************************************************************
 * Default constructor
 * ---------------------------------------------------------------------------------
 * This is the default constructor for the class
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		robot 		: See default constructor for Robot
 * 		testimonial : NULL
 * 		password    : NULL
 **********************************************************************************/
template <class Type>
PCustomer<Type>::PCustomer ()
{
	robot = new Robot<Type>;
	testimonial = '\0';
	password = '\0';
}

/***********************************************************************************
 * Constructor with parameters
 * ---------------------------------------------------------------------------------
 * This is the default constructor for the class
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		robot->name		: newRobotName
 * 		robot->norton	: newNorton
 * 		robot->color	: newColor
 * 		robot->movement : newMovement
 * 		testimonial     : newTestimonial
 * 		password        : newPassword
 **********************************************************************************/
template <class Type>
PCustomer<Type>::PCustomer (Type 		  newCustomerName,
							Type 		  newTestimonial,
							Type		  newPassword,
							Type 		  newRobotName,
							bool 		  newNorton,
							unsigned char newColor,
							unsigned char newMovement)
				: Client <Type> (		  newCustomerName)
{
	robot = new Robot<Type>;
	Client<Type>::setName (newCustomerName);
	testimonial = newTestimonial;
	password = newPassword;
	robot->setName (newRobotName);
	robot->setNorton (newNorton);
	robot->setColor (newColor);
	robot->setMovement (newMovement);
}

/***********************************************************************************
 * Destructor
 * ---------------------------------------------------------------------------------
 * This is the destructor for the class
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		robot must be initialized
 *
 * POST-CONDITIONS
 * 		deletes the memory that robot was in
 **********************************************************************************/
template <class Type>
PCustomer<Type>::~PCustomer ()
{
	delete robot;
}

/***********************************************************************************
 * Default copy constructor
 * ---------------------------------------------------------------------------------
 * This is the copy constructor for the class, that calls the deep copy function
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		The instance of PCustomer must be initialized
 *
 * POST-CONDITIONS
 * 		The new instance of PCustomer has the data of newCust
 **********************************************************************************/
template <class Type>
PCustomer<Type>::PCustomer (const PCustomer<Type>& newCust)
{
	Copy (newCust);
}

/***********************************************************************************
 * Copy constructor
 * ---------------------------------------------------------------------------------
 * This is the method for the deep copy
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		The instance of PCustomer must be initialized
 *
 * POST-CONDITIONS
 * 		The new instance of PCustomer has the data of newCust
 **********************************************************************************/
template <class Type>
void PCustomer<Type>::Copy (PCustomer<Type>* newCust)
{
	setName (newCust->getName());
	setTestimonial (newCust->getTestimonial());
	setPassword (newCust->getPassword());
	robot = new Robot<Type>;
	setColor (newCust->getColor());
	setMovement (newCust->getMovement());
	setNorton (newCust->getNorton());
	setRobotName (newCust->getRobotName());
}

/***********************************************************************************
 * setRobot
 * ---------------------------------------------------------------------------------
 * This is the copy constructor for the Robot class
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		The instance of Robot must be initialized
 *
 * POST-CONDITIONS
 * 		The new instance of Robot has the data of newRobot
 **********************************************************************************/
template <class Type>
void PCustomer<Type>::setRobot (Robot<Type>* newRobot)
{
	robot = newRobot;
}

/***********************************************************************************
 * Overloaded =
 * ---------------------------------------------------------------------------------
 * This is the overloaded assignment operator.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		The instance of PCustomer doing the assignment must be initialized
 *
 * POST-CONDITIONS
 * 		The PCustomer on the left now has the data of the right version of it
 **********************************************************************************/
template <class Type>
void PCustomer<Type>::operator= (const PCustomer<Type>& newCust) const
{
	Copy (newCust);
}

/***********************************************************************************
 * setName
 * ---------------------------------------------------------------------------------
 * This function sets the name for PCustomer.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		name : customerName
 **********************************************************************************/
template <class Type>
void PCustomer<Type>::setName (Type customerName)
{
	Client<Type>::setName (customerName);
}

/***********************************************************************************
 * getName
 * ---------------------------------------------------------------------------------
 * This function returns the template variable for name.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		name must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
Type PCustomer<Type>::getName ()
{
	return Client<Type>::getName ();
}

/***********************************************************************************
 * setTestimonial
 * ---------------------------------------------------------------------------------
 * This function sets the testimonial for PCustomer.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		testimonial : newTestimonial
 **********************************************************************************/
template <class Type>
void PCustomer<Type>::setTestimonial (Type newTestimonial)
{
	testimonial = newTestimonial;
}

/***********************************************************************************
 * getTestimonial
 * ---------------------------------------------------------------------------------
 * This function returns the template variable for testimonioal.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		testimonial must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
Type PCustomer<Type>::getTestimonial ()
{
	return testimonial;
}

/***********************************************************************************
 * setPassword
 * ---------------------------------------------------------------------------------
 * This function sets the password for PCustomer.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		password : newPass
 **********************************************************************************/
template <class Type>
void PCustomer<Type>::setPassword (Type newPass)
{
	password = newPass;
}

/***********************************************************************************
 * getPassword
 * ---------------------------------------------------------------------------------
 * This function returns the template variable for password.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		password must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
Type PCustomer<Type>::getPassword ()
{
	return password;
}

/***********************************************************************************
 * setRobotName
 * ---------------------------------------------------------------------------------
 * This function sets robot->name for PCustomer.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		robot->name : robotName
 **********************************************************************************/
template <class Type>
void PCustomer<Type>::setRobotName (Type robotName)
{
	robot->setName (robotName);
}

/***********************************************************************************
 * getRobotName
 * ---------------------------------------------------------------------------------
 * This function returns the template variable for robot->name.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		robot->name must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
Type PCustomer<Type>::getRobotName ()
{
	return robot->getName ();
}

/***********************************************************************************
 * setNorton
 * ---------------------------------------------------------------------------------
 * This function sets robot->norton for PCustomer.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		robot->norton : norton
 **********************************************************************************/
template <class Type>
void PCustomer<Type>::setNorton (bool norton)
{
	robot->setNorton (norton);
}

/***********************************************************************************
 * getNorton
 * ---------------------------------------------------------------------------------
 * This function returns the bool for robot->norton.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		robot->norton must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
bool PCustomer<Type>::getNorton ()
{
	return robot->getNorton ();
}

/***********************************************************************************
 * setColor
 * ---------------------------------------------------------------------------------
 * This function sets robot->color for PCustomer.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		robot->color : color
 **********************************************************************************/
template <class Type>
void PCustomer<Type>::setColor (unsigned char color)
{
	robot->setColor (color);
}

/***********************************************************************************
 * getColor
 * ---------------------------------------------------------------------------------
 * This function returns the unsigned char for robot->color.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		robot->norton must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
unsigned char PCustomer<Type>::getColor ()
{
	return robot->getColor ();
}

/***********************************************************************************
 * setMovement
 * ---------------------------------------------------------------------------------
 * This function sets robot->movement for PCustomer.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		none
 *
 * POST-CONDITIONS
 * 		robot->movement : movement
 **********************************************************************************/
template <class Type>
void PCustomer<Type>::setMovement (unsigned char movement)
{
	robot->setMovement (movement);
}

/***********************************************************************************
 * getMovement
 * ---------------------------------------------------------------------------------
 * This function returns the unsigned char for robot->movement.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		robot->movement must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
unsigned char PCustomer<Type>::getMovement ()
{
	return robot->getMovement();
}

/***********************************************************************************
 * getMovement
 * ---------------------------------------------------------------------------------
 * This function calculates the price based off the values of robot->norton,
 * 	robot->color, and robot->movement.
 * ---------------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 		robot->norton must have data in it
 * 		robot->color must have data in it
 * 		robot->movement must have data in it
 *
 * POST-CONDITIONS
 * 		none
 **********************************************************************************/
template <class Type>
int PCustomer<Type>::getPrice()
{
	return robot->getPrice();
}

#endif /* PCUSTOMER_H_ */
