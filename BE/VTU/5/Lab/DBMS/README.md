# DATABASE APPLICATIONS LABORATORY
> Subject Code : 10CSL57

1) Consider the following relations:
	
	Student (snum: integer, sname: string, major: string, level: string,
	age: integer)
	Class (name: string, meets at: string, room: string, d: integer)
	Enrolled (snum: integer, cname: string)
	Faculty (fid: integer, fname: string, deptid: integer)
	
	The meaning of these relations is straightforward; for example,
	Enrolled has one record per student-class pair such that the student
	is enrolled in the class. Level is a two character code with 4 different
	values (example: Junior: JR etc)
	Write the following queries in SQL. No duplicates should be printed
	in any of the answers.

		i) Find the names of all Juniors (level = JR) who are enrolled
		in a class taught by Prof. Harshith
		
		ii) Find the names of all classes that either meet in room R128
		or have five or more Students enrolled.
		
		iii) Find the names of all students who are enrolled in two
		classes that meet at the same time.
		
		iv) Find the names of faculty members who teach in every
		room in which some class is taught.
		
		v) Find the names of faculty members for whom the combined
		enrollment of the courses that they teach is less than five.



2) The following relations keep track of airline flight information:
	
	Flights (no: integer, from: string, to: string, distance: integer,
	Departs: time, arrives: time, price: real)
	Aircraft (aid: integer, aname: string, cruisingrange: integer)
	Certified (eid: integer, aid: integer)
	Employees (eid: integer, ename: string, salary: integer)
	
	Note that the Employees relation describes pilots and other kinds of
	employees as well;
	Every pilot is certified for some aircraft, and only pilots are certified to fly.
	Write each of the following queries in SQL.

		i)Find the names of aircraft such that all pilots certified to
		operate them have salaries more than Rs.80, 000.
		
		ii) For each pilot who is certified for more than three aircrafts,
		find the eid and the maximum cruisingrange of the aircraft
		for which she or he is certified.
		
		iii) Find the names of pilots whose salary is less than the price
		of the cheapest route from Bengaluru to Frankfurt.
		
		iv) For all aircraft with cruisingrange over 1000 Kms, .find the
		name of the aircraft and the average salary of all pilots
		certified for this aircraft.
		
		v) Find the names of pilots certified for some Boeing aircraft.
		
		vi) Find the aids of all aircraft that can be used on routes from
		Bengaluru to New Delhi.


3) Consider the following database of student enrollment in courses & 
books adopted for each course.
	
	STUDENT (regno: string, name: string, major: string, bdate:date)
	COURSE (course #:int, cname:string, dept:string)
	ENROLL ( regno:string, course#:int, sem:int, marks:int)
	BOOK _ ADOPTION (course# :int, sem:int, book-ISBN:int)
	TEXT(book-ISBN:int, book-title:string, publisher:string, author:string)

		i) Create the above tables by properly specifying the primary 
		keys and the foreign keys.
		
		ii) Enter at least five tuples for each relation.
		
		iii) Demonstrate how you add a new text book to the database
		and make this book be adopted by some department.
		
		iv) Produce a list of text books (include Course #, Book-ISBN,
		Book-title) in the alphabetical order for courses offered by
		the ‘CS’ department that use more than two books.
		
		v) List any department that has all its adopted books
		published by a specific publisher.
		
		vi) Generate suitable reports.
		
		vii) Create suitable front end for querying and displaying the results.


4) The following tables are maintained by a book dealer.
	
	AUTHOR (author-id:int, name:string, city:string, country:string)
	PUBLISHER (publisher-id:int, name:string, city:string, country:string)
	CATALOG (book-id:int, title:string, author-id:int, publisher-id:int,
	category-id:int, year:int, price:int)
	CATEGORY (category-id:int, description:string)
	ORDER-DETAILS (order-no:int, book-id:int, quantity:int)

		i) Create the above tables by properly specifying the primary
		keys and the foreign keys.
		
		ii) Enter at least five tuples for each relation.
		
		iii) Give the details of the authors who have 2 or more books in
		the catalog and the price of the books is greater than the
		average price of the books in the catalog and the year of
		publication is after 2000.
		
		iv) Find the author of the book which has maximum sales.
		
		v) Demonstrate how you increase the price of books published
		by a specific publisher by 10%.
		
		vi) Generate suitable reports.
		
		vii) Create suitable front end for querying and displaying the
		results.


5) Consider the following database for a banking enterprise
	
	BRANCH(branch-name:string, branch-city:string, assets:real)
	ACCOUNT(accno:int, branch-name:string, balance:real)
	DEPOSITOR(customer-name:string, accno:int)
	CUSTOMER(customer-name:string, customer-street:string, customer-city:string)
	LOAN(loan-number:int, branch-name:string, amount:real)
	BORROWER(customer-name:string, loan-number:int)

		i) Create the above tables by properly specifying the primary
		keys and the foreign keys
		
		ii) Enter at least five tuples for each relation
		
		iii) Find all the customers who have at least two accounts at the
		Main branch.
		
		iv) Find all the customers who have an account at all the
		branches located in a specific city.
		
		v) Demonstrate how you delete all account tuples at every
		branch located in a specific city.
		
		vi) Generate suitable reports.
		
		vii) Create suitable front end for querying and displaying the
		results.