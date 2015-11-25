CREATE TABLE flight( fno int, ffrom varchar(20), fto varchar(20), distance int(11),
					departs time, arrives time, price float, PRIMARY KEY(fno));

CREATE TABLE aircraft(aid int, aname varchar(20), crange int, PRIMARY KEY(aid));

CREATE TABLE employees(eid int, ename varchar(20), salary int, PRIMARY KEY(eid));

CREATE TABLE certified(eid int, aid int,PRIMARY KEY(eid,aid),
						FOREIGN KEY(eid) REFERENCES employees(eid),
						FOREIGN KEY(aid) REFERENCES aircraft(aid));


/*
i) Find the names of aircraft such that all pilots certified to 
operate them have salaries more than Rs.80, 000.
*/

SELECT ANAME 
	FROM AIRCRAFT A,
		EMPLOYEES E,
		CERTIFIED C 
	WHERE C.EID=E.EID 
	AND C.AID=A.AID 
	AND E.SALARY>80000;


/*
ii) For each pilot who is certified for more than three aircrafts,
find the eid and the maximum cruisingrange of the aircraft
for which she or he is certified.
*/

SELECT E.EID,MAX(A.CRANGE)
	FROM EMPLOYEES E,
		CERTIFIED C,
		AIRCRAFT A 
	WHERE E.EID=C.EID 
	AND C.AID=A.AID 
		GROUP BY C.EID 
		HAVING COUNT(*)>3;


/*
iii) Find the names of pilots whose salary is less than the price
of the cheapest route from Bengaluru to Frankfurt.
*/		

SELECT DISTINCT E.ENAME
	FROM EMPLOYEES E,
		CERTIFIED C 
	WHERE E.EID=C.EID 
	AND E.SALARY<
	(SELECT MIN(PRICE) 
		FROM FLIGHT F 
		WHERE F.FFROM='BANGALORE' 
		AND F.FTO='FRANKFURT');


/*
iv) For all aircraft with cruisingrange over 1000 Kms, .find the
name of the aircraft and the average salary of all pilots
certified for this aircraft.
*/

SELECT A.ANAME,AVG(E.SALARY)
	FROM AIRCRAFT A,
		EMPLOYEES E,
		CERTIFIED C 
	WHERE CRANGE>1000
	AND C.EID=E.EID 
	AND A.AID=C.AID 
		GROUP BY A.ANAME;


/*
v) Find the names of pilots certified for some Boeing aircraft.
*/

SELECT ENAME 
	FROM AIRCRAFT A,
		CERTIFIED C,
		EMPLOYEES E 
	WHERE A.AID=C.AID
	AND C.EID=E.EID 
	AND A.ANAME 
		LIKE '%BOEING%';


/*
vi) Find the aids of all aircraft that can be used on routes from
Bengaluru to New Delhi.
*/

SELECT A.AID
	FROM AIRCRAFT A 
	WHERE A.CRANGE>=
	(SELECT MIN(F.DISTANCE) 
		FROM FLIGHT F 
		WHERE FFROM='BANGALORE' 
		AND FTO='NEW DELHI');