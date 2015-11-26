CREATE TABLE STUDENT(regno varchar(20), name varchar(20), major varchar(10), bdate date, PRIMARY KEY(regno) );

CREATE TABLE COURSE(cno int, cname varchar(20), dept varchar(20), PRIMARY KEY(cno) );

CREATE TABLE ENROLL(regno varchar(20), cno int, marks int, sem int, PRIMARY KEY(sem,regno,cno), 
					FOREIGN KEY(regno) REFERENCES student(regno), 
					FOREIGN KEY(cno) REFERENCES course(cno) );

CREATE TABLE TEXT(isbn int, title varchar(30), publisher varchar(20), author varchar(20), PRIMARY KEY(isbn) );

CREATE TABLE BOOK_ADOPTION(cno int, sem int, isbn int, 
					FOREIGN KEY(cno) REFERENCES course(cno), 
					FOREIGN KEY(isbn) REFERENCES TEXT(isbn) , 
					FOREIGN KEY(sem) REFERENCES enroll(sem));


/*
iii) Demonstrate how you add a new text book to the database
and make this book be adopted by some department.
*/		
INSERT INTO TEXT VALUES(3042,'NEW','PEARSON','AJITH');
INSERT INTO BOOK_ADOPTION VALUES(1009,7,3042);



/*
iv) Produce a list of text books (include Course #, Book-ISBN,
Book-title) in the alphabetical order for courses offered by
the ‘CS’ department that use more than two books.
*/

SELECT C.CNO,T.ISBN,T.TITLE 
	FROM COURSE C,
		BOOK_ADOPTION A,
		TEXT T 
	WHERE C.CNO=A.CNO 
	AND C.DEPT='CSE' 
	AND A.ISBN=T.ISBN 
	AND EXISTS
		(SELECT COUNT(A1.CNO) 
			FROM BOOK_ADOPTION A1 
			WHERE A1.CNO=C.CNO 
				GROUP BY A1.CNO 
				HAVING COUNT(*)>2 ) 
				ORDER BY C.CNO,T.ISBN,T.TITLE;



/*
v) List any department that has all its adopted books
published by a specific publisher.
*/
SELECT DISTINCT C.DEPT 
	FROM COURSE C,
		BOOK_ADOPTION A,
		TEXT T
	WHERE C.CNO=A.CNO 
	AND T.ISBN=A.ISBN 
	AND T.PUBLISHER='BILL' 
		GROUP BY DEPT 
		HAVING COUNT(A.ISBN)=
			(SELECT COUNT(*) 
				FROM TEXT 
				WHERE PUBLISHER='BILL'); 
