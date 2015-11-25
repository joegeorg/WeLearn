CREATE TABLE author(aid int, aname varchar(20), acity varchar(20), acountry varchar(20), PRIMARY KEY(aid) );

CREATE TABLE publisher(pid int, pname varchar(20), pcity varchar(20), pcountry varchar(20), PRIMARY KEY(pid) );

CREATE TABLE category(cid int, description varchar(30), PRIMARY KEY(cid) );

CREATE TABLE catalog(bid int, btitle varchar(30), aid int, pid int, cid int, year int, price int, PRIMARY KEY(bid), 
					FOREIGN KEY(aid) REFERENCES author(aid), 
					FOREIGN KEY(pid) REFERENCES publisher(pid), 
					FOREIGN KEY(cid) REFERENCES category(cid) );

CREATE TABLE orderdetails(oid int, bid int, quantity int, PRIMARY KEY(oid), 
						FOREIGN KEY(bid) REFERENCES catalog(bid) );



/*iii) Give the details of the authors who have 2 or more books in
		the catalog and the price of the books is greater than the
		average price of the books in the catalog and the year of
		publication is after 2000.*/
SELECT A.ANAME 
	FROM AUTHOR A,
		CATALOG C 
	WHERE A.AID=C.AID 
	AND C.YEAR>2000 
	AND C.PRICE>
		(SELECT AVG(PRICE) 
			FROM CATALOG) 
				GROUP BY C.AID 
				HAVING COUNT(*)>=2;

/*
iv) Find the author of the book which has maximum sales.
*/
SELECT A.ANAME 
	FROM AUTHOR A,
		ORDERDETAILS O,
		CATALOG C 
		WHERE A.AID=C.AID 
		AND C.BID=O.BID 
		AND O.QUANTITY =
			(SELECT MAX(O.QUANTITY) 
				FROM ORDERDETAILS O) ;


/*
v) Demonstrate how you increase the price of books published 
by a specific publisher by 10%.
*/

SELECT C.BID,C.PRICE*1.1 
	AS NEWPRICE 
	FROM PUBLISHER P,
		CATALOG C
	WHERE P.PID=C.PID 
	AND P.PNAME='GREAT MAN';